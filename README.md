# Taskbar Disk Space

**Version 0.12.36** · A [Windhawk](https://windhawk.net/) mod for the native Windows 11 taskbar.

Shows disk capacity directly on the taskbar, with drive selection and appearance controls. This repository hosts the author's latest versions independently of the official catalog. [Official catalog submission](https://github.com/ramensoftware/windhawk-mods/pull/5818).

## Features

- One selected drive or all local fixed drives, with volume names and custom labels.
- Free / Total, Used / Total, or free-space percentage; 0–2 decimal places.
- System, Color bar and Text only themes; ten palettes and animated hover/pressed states.
- Manual and automatic compact layouts, plus per-drive low-space highlighting.
- Primary, all or a selected taskbar; monitor device paths used when available.
- Horizontal placement controls. Experimental left/right vertical taskbars use automatic top placement; all-drive lists scroll within the available space.
- Menus for drives, appearance, refresh, reset and system shortcuts: selected drive, This PC and Disk Management.

## Screenshots

![Taskbar Disk Space screenshot 1](https://i.imgur.com/QsiHo0m.png)
![Taskbar Disk Space screenshot 2](https://i.imgur.com/VyaAfGR.png)
![Taskbar Disk Space screenshot 3](https://i.imgur.com/fHFa648.png)
![Taskbar Disk Space screenshot 4](https://i.imgur.com/zqPRJ9V.png)
![Taskbar Disk Space screenshot 5](https://i.imgur.com/7Zs15Sq.png)

## Install / update

1. Install Windhawk and download [taskbar-disk-space.wh.cpp](taskbar-disk-space.wh.cpp) using GitHub's **Raw / Download raw file** action.
2. In Windhawk, create a new mod, replace its source with the complete downloaded file, and compile it.
3. For an existing local installation, edit that local mod, replace its source and compile it again.
4. Disable another installation of Taskbar Disk Space before enabling this one; keep a single active installation.

Updates published here are installed manually. This repository does not configure automatic updates in Windhawk. Catalog installations follow the version published in the official collection. The embedded description contains detailed controls and compatibility notes.

## Compatibility

Windows 11 22H2+ with the native taskbar, x86-64. Windhawk 1.7.3 and 2.0-compatible settings; dynamic settings lists require 2.0. Vertical taskbar support is experimental and requires a Windows configuration providing those positions. ExplorerPatcher and StartAllBack are unsupported.

Only fixed local drives are listed. Reads use volume metadata, without modifying user files. GiB means 1024³ bytes. Windows taskbar internals can change after updates.

## Feedback

[Report a bug](https://github.com/Fatalko/taskbar-disk-space/issues/new?template=bug_report.yml) · [Suggest a feature](https://github.com/Fatalko/taskbar-disk-space/issues/new?template=feature_request.yml)

Include the mod/Windhawk/Windows versions, taskbar position, monitor setup, scale and steps to reproduce. Layout diagnostics can be enabled temporarily in mod settings with Windhawk debug logging; attach relevant `[Taskbar layout]` lines. Review logs and screenshots before sharing them publicly. Feedback is voluntary; the mod does not automatically upload reports.

## Development

Run `./test.ps1` in PowerShell with Windhawk installed in its default directory, or pass `-WindhawkPath`. The checks compile extracted production logic into a native regression harness, execute it and compile the full mod. They do not replace testing in Explorer. Build output is excluded from this repository.

[Development history](CHANGELOG.md) includes local versions that were not released in the official catalog.

## Русский

Мод показывает место на одном или всех локальных дисках на панели задач Windows 11. Доступны темы, точность, проценты, мини-дизайн, выбор монитора и предупреждение о нехватке места. На вертикальной панели размещается автоматически сверху; длинный список дисков прокручивается колёсиком.

**Установка:** скачайте полный файл [taskbar-disk-space.wh.cpp](taskbar-disk-space.wh.cpp), создайте мод в Windhawk, вставьте исходник и скомпилируйте. Для обновления замените исходник уже установленного локального мода. Другую копию мода отключите.

Это репозиторий последних авторских версий. Обновления отсюда устанавливаются вручную; публикация в официальном каталоге проходит отдельно.

[Сообщить об ошибке](https://github.com/Fatalko/taskbar-disk-space/issues/new?template=bug_report.yml) · [Предложить функцию](https://github.com/Fatalko/taskbar-disk-space/issues/new?template=feature_request.yml) · [История изменений](CHANGELOG.md)

## License and credits

[GPL-3.0](LICENSE). Taskbar XAML discovery is adapted from [Taskbar Multirow](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/taskbar-multirow.wh.cpp) by Michael Maltsev and [Taskbar System Info](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/taskbar-system-info.wh.cpp) by Yevhenii Starychenko. Original attribution is preserved in the source.

Developed by Fatalko with AI assistance (ChatGPT / Codex).
