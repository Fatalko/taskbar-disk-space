# Taskbar Disk Space

[English version](#english-version)

**Версия 0.17.4** · Мод [Windhawk](https://windhawk.net/) для штатной панели задач Windows 11.

Показывает место на дисках прямо на панели задач, позволяет выбирать диски и менять оформление через меню. Здесь публикуются последние авторские версии независимо от официального каталога. [Заявка в официальный каталог](https://github.com/ramensoftware/windhawk-mods/pull/5818).

## Возможности

- Один выбранный диск, группы «Автоматический режим» (все диски), «Локальные диски», «Внешние диски» или ручной набор через «Выбранные диски» в обоих меню. Отметки сохраняются после перезапуска Explorer; «Показывать выбранные диски» возвращает набор после смены группы.
- USB-флешки и внешние диски появляются и исчезают автоматически; изменения букв проверяются каждые две секунды. В ручном наборе новые неотмеченные устройства не добавляются. Отключённые выбранные буквы сохраняются и возвращаются при подключении; пустой набор показывает «Диски не выбраны».
- Свободно / Всего, Занято / Всего или процент свободного места; 0–2 знака после запятой, метки томов и собственное имя.
- На горизонтальной панели отображается столько целых карточек выбранного вида, сколько помещается, с кнопкой «Ещё · N» для скрытых дисков. При наведении она показывает их данные, при нажатии открывает полное меню выбора. Порядок — по буквам дисков.
- Автоматическое положение выбирает сторону, где помещается больше карточек; при равенстве центральные значки предпочитают левый участок после виджета, левое выравнивание — правый перед треем. Можно выбрать сторону вручную. Геометрия проверяется не реже раза в пять секунд; запас при возврате карточек уменьшает мигание.
- «Компактный режим → Автоматически» всегда включён и недоступен для переключения. Если ни одна карточка с «Ещё» не помещается, адаптация пробует компактный текст, плитки букв и «Диски · N». Скрытие имени, плитки и кнопку списка можно выбрать вручную; подсказка кнопки показывает сведения о текущем наборе.
- Системная тема, цветная полоса, фон свободного места и только текст; десять палитр. В списке нет общей рамки: системная тема и цветная полоса подсвечивают только диск под курсором. Постоянный фон свободного/занятого места не меняется при наведении; поверх него и плиток появляется лёгкая нейтральная подсветка с анимацией 120 мс. Рамки учитывают высоту, скругление и прозрачность кнопки «Пуск».
- Отдельные предупреждения о нехватке места для каждого диска. Высококонтрастное оформление и отключённые анимации Windows учитываются.
- Основная, все или выбранная панель; сохранение монитора по пути устройства, если Windows его предоставляет.
- Экспериментальная поддержка вертикальных панелей слева/справа: автоматическое размещение сверху и прокрутка длинного списка в пределах свободного участка.
- Меню оформления, обновления данных и сброса; команды открытия диска, «Этот компьютер» и «Управление дисками». Все пункты и варианты меню имеют короткие пояснения при наведении на русском или английском.
- Средняя кнопка мыши на подключённом диске в меню открывает его в Проводнике без изменения выбора. «Сбросить оформление» сохраняет ручной набор, «Применить настройки Windhawk» очищает отметки и параметры меню. Набор хранит буквы: другой том с той же буквой будет отображаться вместо прежнего.

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

Перечисляются локальные диски, USB-флешки и внешние накопители с назначенной буквой. Сетевые диски и устройства без буквы исключены. Съёмные носители и диски, сообщающие USB/IEEE 1394 или съёмный носитель в свойствах Windows, относятся к внешним; если свойства фиксированного диска недоступны, он остаётся в локальной группе. Читаются сведения о томах, пользовательские файлы не изменяются. ГиБ — 1024³ байт. Внутреннее устройство панели Windows может измениться после обновлений.

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

**Version 0.17.4** · A [Windhawk](https://windhawk.net/) mod for the native Windows 11 taskbar.

Shows disk capacity directly on the taskbar, with drive selection and appearance controls. This repository hosts the author's latest versions independently of the official catalog. [Official catalog submission](https://github.com/ramensoftware/windhawk-mods/pull/5818).

## Features

- One selected drive, Automatic mode (all drives), Local drives, External drives, or a manual set using Selected drives in either menu. Checks survive Explorer restarts; Show selected drives restores the set after changing groups.
- USB flash drive and external disk connection/removal detection checks drive-letter changes every two seconds. New unchecked devices are excluded from a manual set. Disconnected selected letters remain saved and return when reconnected; an empty set shows No drives selected.
- Free / Total, Used / Total, or free-space percentage; 0–2 decimal places, volume names and custom labels.
- Horizontal taskbars show as many complete cards of the selected layout as fit, reserving a More · N button for hidden drives. Hover shows their capacity details; clicking opens the complete selection menu. Drives are ordered by letter.
- Automatic placement chooses the side fitting more cards. Ties prefer the left gap after Widgets for centered icons, or the right gap before the tray for left-aligned icons. Manual side selection remains available. Layout is checked at least every five seconds; extra space is required before restoring a card to reduce flicker.
- Compact mode → Automatic is always enabled, checked and unavailable for toggling. If no card plus More fits, adaptation tries compact text, drive-letter tiles and Drives · N. Hide drive name, tiles and the list button can be selected manually; the list tooltip shows the current set's capacity.
- System, Color bar, Capacity background and Text only themes; ten palettes. Lists have no shared frame: System and Color bar highlight only the hovered drive. Capacity backgrounds keep their free/used fill unchanged; a subtle neutral overlay fades in/out over these cards and tiles in 120 ms. Frames follow the Start button's height, corner radius and translucent opacity.
- Per-drive low-space highlighting. High contrast and Windows animation preferences are respected.
- Primary, all or a selected taskbar; monitor device paths used when available.
- Experimental left/right vertical taskbars use automatic top placement; long lists scroll within the available space.
- Appearance, refresh and reset menus with shortcuts to the selected drive, This PC and Disk Management. All menu commands and options have short Russian or English hover hints.
- Middle-click a connected drive in a menu to open it in File Explorer without changing its selection. Reset appearance preserves the manual set; Apply Windhawk settings clears its checks and menu overrides. Sets store letters: a different volume receiving the same letter will be displayed instead.

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

Local disks, USB flash drives and external disks with drive letters are listed; network drives and devices without drive letters are excluded. Removable media and disks reporting USB/IEEE 1394 or removable media in Windows storage properties belong to the external group; a fixed disk whose properties cannot be queried stays in the local group. Reads use volume metadata, without modifying user files. GiB means 1024³ bytes. Windows taskbar internals can change after updates.

## Feedback

[Report a bug](https://github.com/Fatalko/taskbar-disk-space/issues/new?template=bug_report.yml) · [Suggest a feature](https://github.com/Fatalko/taskbar-disk-space/issues/new?template=feature_request.yml)

Include the mod/Windhawk/Windows versions, taskbar position, monitor setup, scale and steps to reproduce. Layout diagnostics can be enabled temporarily in mod settings with Windhawk debug logging; attach relevant `[Taskbar layout]` lines. Review logs and screenshots before sharing them publicly. Feedback is voluntary; the mod does not automatically upload reports.

## Development

Run `./test.ps1` in PowerShell with Windhawk installed in its default directory, or pass `-WindhawkPath`. The checks compile extracted production logic into a native regression harness, execute it and compile the full mod. They do not replace testing in Explorer. Build output is excluded from this repository.

[Development history](CHANGELOG.md) includes local versions that were not released in the official catalog.

## License and credits

[GPL-3.0](LICENSE). Taskbar XAML discovery is adapted from [Taskbar Multirow](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/taskbar-multirow.wh.cpp) by Michael Maltsev and [Taskbar System Info](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/taskbar-system-info.wh.cpp) by Yevhenii Starychenko. Original attribution is preserved in the source.

Developed by Fatalko with AI assistance (ChatGPT / Codex).
