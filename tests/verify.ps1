param([string]$WindhawkPath = 'C:\Program Files\Windhawk')
$ErrorActionPreference = 'Stop'
$repo = Split-Path $PSScriptRoot -Parent
$source = [IO.File]::ReadAllText((Join-Path $repo 'taskbar-disk-space.wh.cpp'))
$build = Join-Path $repo 'build'
New-Item -ItemType Directory -Path $build -Force | Out-Null
function Extract([string]$pattern) {
    $match = [regex]::Match($source, $pattern)
    if (!$match.Success) { throw "Production code fragment not found: $pattern" }
    return $match.Value + "`n"
}
$harness = @'
#include <windows.h>
#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <limits>
#include <map>
#include <mutex>
#include <string>
#include <string_view>
#include <iostream>
std::map<std::wstring,std::wstring> storage, strings;
std::map<std::wstring,int> integers;
std::wstring StringSetting(PCWSTR key) { return strings[key]; }
std::wstring LocalStringValue(PCWSTR key) { return storage[key]; }
int Wh_GetIntSetting(PCWSTR key) { return integers[key]; }
bool Wh_SetStringValue(PCWSTR key, PCWSTR value) { storage[key]=value; return true; }
bool Wh_DeleteValue(PCWSTR key) { storage.erase(key); return true; }
std::wstring UiText(bool russian, PCWSTR english, PCWSTR translated) { return russian?translated:english; }
HANDLE g_changed = nullptr;
constexpr wchar_t kSelectedDriveValue[]=L"SelectedDrive";
constexpr wchar_t kConfiguredDriveValue[]=L"ConfiguredDrive";
'@
$harness += "`n" + (Extract '(?s)struct Settings \{.*?\r?\n\};')
$harness += "Settings g_settings; std::mutex g_settingsMutex;`n"
foreach ($pattern in @(
    '(?s)std::wstring NormalizeDrive\(.*?\r?\n\}',
    '(?s)void LoadSettings\(\).*?\r?\n\}',
    '(?s)std::wstring FormatGiB\(.*?\r?\n\}',
    '(?s)std::wstring CapacityText\(.*?\r?\n\}',
    '(?s)bool LowSpaceReached\(.*?\r?\n\}',
    '(?s)bool ShouldUseCompact\(.*?\r?\n\}',
    '(?s)struct ButtonBounds \{.*?\r?\n\};',
    '(?s)double AvailableIndicatorWidth\(.*?\r?\n\}',
    '(?s)struct TaskbarWindow \{.*?\r?\n\};',
    '(?s)bool IsSelectedTaskbar\(.*?\r?\n\}',
    '(?s)void ResetAppearance\(\).*?\r?\n\}',
    '(?s)void ApplyConfiguredSettings\(\).*?\r?\n\}'
)) { $harness += Extract $pattern }
$harness += "struct UiState {};`n" + (Extract '(?s)thread_local UiState\* g_activeUi = nullptr;.*?\r?\n\};')
$harness += [IO.File]::ReadAllText((Join-Path $PSScriptRoot 'cases.cpp'))
$testSource = Join-Path $build 'regression-tests.cpp'
$testExe = Join-Path $build 'regression-tests.exe'
[IO.File]::WriteAllText($testSource, $harness, [Text.UTF8Encoding]::new($false))
$compiler = Join-Path $WindhawkPath 'Compiler\bin\clang++.exe'
& $compiler -std=c++23 -static -target x86_64-w64-mingw32 $testSource -o $testExe
if ($LASTEXITCODE -ne 0) { throw 'Regression test compilation failed' }
& $testExe
if ($LASTEXITCODE -ne 0) { throw 'Regression tests failed' }
& $compiler -std=c++23 -c -O1 -target x86_64-w64-mingw32 -DUNICODE -D_UNICODE -DWH_MOD -DWH_EDITING -D_WIN32_WINNT=0x0A00 (Join-Path $repo 'taskbar-disk-space.wh.cpp') -o (Join-Path $build 'taskbar-disk-space.o')
if ($LASTEXITCODE -ne 0) { throw 'Mod compilation failed' }
