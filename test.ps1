param([string]$WindhawkPath = 'C:\Program Files\Windhawk')
$ErrorActionPreference = 'Stop'
& (Join-Path $PSScriptRoot 'tests\verify.ps1') -WindhawkPath $WindhawkPath