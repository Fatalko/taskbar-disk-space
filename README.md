# Taskbar Disk Space

[English version](#english-version)

**Версия 0.12.36** · Мод [Windhawk](https://windhawk.net/) для штатной панели задач Windows 11.

Показывает место на дисках прямо на панели задач, позволяет выбирать диски и менять оформление через меню. Здесь публикуются последние авторские версии независимо от официального каталога. [Заявка в официальный каталог](https://github.com/ramensoftware/windhawk-mods/pull/5818).

## Возможности

- Один выбранный диск или все фиксированные локальные диски, метки томов и собственное имя.
- Свободно / Всего, Занято / Всего или процент свободного места; 0–2 знака после запятой.
- Системная тема, цветная полоса и только текст; десять палитр и анимации наведения/нажатия.
- Ручной и автоматический мини-дизайн, отдельные предупреждения о нехватке места для каждого диска.
- Основная, все или выбранная панель; сохранение монитора по пути устройства, если Windows его предоставляет.
- Выбор положения на горизонтальной панели. Экспериментальная поддержка вертикальных панелей слева/справа: автоматическое размещение сверху и прокрутка длинного списка дисков в пределах свободного участка.
- Меню выбора дисков, оформления, обновления данных и сброса; команды открытия диска, «Этот компьютер» и «Управление дисками».

## Скриншоты

![Taskbar Disk Space — скриншот 1](https://i.imgur.com/QsiHo0m.png)
![Taskbar Disk Space — скриншот 2](https://i.imgur.com/VyaAfGR.png)
![Taskbar Disk Space — скриншот 3](https://i.imgur.com/fHFa648.png)
![Taskbar Disk Space — скриншот 4](https://i.imgur.com/zqPRJ9V.png)
![Taskbar Disk Space — скриншот 5](https://i.imgur.com/7Zs15Sq.png)

## Установка и обновление

1. Установите Windhawk и скачайте [taskbar-disk-space.wh.cpp](taskbar-disk-space.wh.cpp) через **Raw / Download raw file** на GitHub.
2. Создайте новый мод в Windhawk, замените его исходник полным содержимым скачанного файла и скомпилируйте.
3. Для обновления существующей локальной установки откройте её исходный код, замените содержимое новым файлом и снова скомпилируйте.
4. Перед включением отключите другую установку Taskbar Disk Space; оставьте одну активную копию.

Версии из этого репозитория обновляются вручную. Автоматические обновления в Windhawk этим репозиторием не настраиваются. Установки из официального каталога получают опубликованную там версию. Подробное описание управления и ограничений находится также внутри мода.

## Совместимость

Windows 11 22H2 и новее со штатной панелью задач, x86-64. Настройки совместимы с Windhawk 1.7.3 и 2.0; динамические списки требуют 2.0. Вертикальная панель поддерживается экспериментально и требует конфигурации Windows, в которой доступны эти положения. ExplorerPatcher и StartAllBack не поддерживаются.

Перечисляются только фиксированные локальные диски. Читаются сведения о томах, пользовательские файлы не изменяются. ГиБ — 1024³ байт. Внутреннее устройство панели Windows может измениться после обновлений.

## Обратная связь

[Сообщить об ошибке](https://github.com/Fatalko/taskbar-disk-space/issues/new?template=bug_report.yml) · [Предложить функцию](https://github.com/Fatalko/taskbar-disk-space/issues/new?template=feature_request.yml)

Укажите версии мода, Windhawk и Windows, положение панели, мониторы, масштаб и шаги воспроизведения. Для проблем размещения временно включите диагностику в настройках мода и журнал отладки Windhawk; приложите нужные строки `[Taskbar layout]`. Перед публичной отправкой проверьте логи и скриншоты. Обратная связь добровольная; мод не отправляет отчёты автоматически.

## Разработка

Запустите `./test.ps1` в PowerShell с установленным Windhawk по стандартному пути либо передайте `-WindhawkPath`. Проверки собирают и запускают тесты извлечённой логики исходника, затем компилируют весь мод. Они не заменяют проверку в Explorer. Результаты сборки исключены из репозитория.

[История разработки](CHANGELOG.md) включает локальные версии, которые не публиковались в официальном каталоге.

## Лицензия и авторство

[GPL-3.0](LICENSE). Поиск XAML панели адаптирован из [Taskbar Multirow](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/taskbar-multirow.wh.cpp) Michael Maltsev и [Taskbar System Info](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/taskbar-system-info.wh.cpp) Yevhenii Starychenko. Авторские ссылки сохранены в исходнике.

Разработчик — Fatalko, с помощью ИИ (ChatGPT / Codex).

---

## English version

[Русская версия](#taskbar-disk-space)

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

[View screenshots](#скриншоты).

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

## License and credits

[GPL-3.0](LICENSE). Taskbar XAML discovery is adapted from [Taskbar Multirow](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/taskbar-multirow.wh.cpp) by Michael Maltsev and [Taskbar System Info](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/taskbar-system-info.wh.cpp) by Yevhenii Starychenko. Original attribution is preserved in the source.

Developed by Fatalko with AI assistance (ChatGPT / Codex).
