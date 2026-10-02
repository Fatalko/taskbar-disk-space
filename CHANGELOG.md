# Taskbar Disk Space — история изменений

Локальная история разработки. Эти записи не означают публикацию версий в официальном каталоге.

## 0.12.38 — 2026-10-02

- Добавлены разные значки внутренних и внешних дисков в меню левой кнопки и сохраняемые режимы «Все диски», «Все локальные диски», «Все внешние диски». USB-диски определяются по свойствам устройства в рабочем потоке; меню использует кеш.
- Added distinct local/external icons and persistent All drives, All local drives and All external drives groups. USB disks are classified from device properties on the worker; menus use cached results.

## 0.12.37 — 2026-10-02

- Добавлена поддержка USB-флешек и внешних дисков с назначенной буквой; подключение и отключение проверяются каждые две секунды. В режиме всех дисков список обновляется автоматически, одиночный режим сохраняет выбор.
- Added removable USB drives and external disks with drive letters, with automatic connection/removal detection every two seconds. All-drive mode updates automatically; single-drive selection is preserved.

## 0.12.36 — 2026-10-01

- На вертикальных панелях оставлено только автоматическое размещение сверху; меню показывает единственный отмеченный вариант.
- Сохранён выбор положения для горизонтальной панели; возврат вниз/вверх его восстанавливает.
- Vertical taskbars now use only automatic top placement; horizontal position preferences are preserved.

## 0.12.35 — 2026-10-01

- Исправлено исчезновение индикатора из-за кнопок за пределами видимой панели; их границы фильтруются и ограничиваются панелью.
- Область вертикальной прокрутки получает явные размеры в пределах свободного участка.
- Fixed off-screen button bounds collapsing available space and explicitly bounded the vertical scroll viewport.

## 0.12.34 — 2026-10-01

- Все диски отображаются вертикальным списком на левой и правой панели; длинный список прокручивается в пределах свободного участка.
- Сохранены отдельные полосы и предупреждения; возврат к горизонтальной панели восстанавливает колонки.
- Added vertical all-drive lists with bounded native scrolling and per-volume bars/warnings, restoring columns on horizontal taskbars.

## 0.12.33 — 2026-10-01

- Экспериментальное вертикальное размещение одного диска с расчётом свободной высоты; режим всех дисков пока скрыт на вертикальной панели.
- Защищён расчёт высоты от неподходящего значения TaskbarHost; расширена диагностика вертикальных границ.
- Added experimental single-drive vertical layout with safe button/tray gaps and narrow stacked values; all-drive vertical layout remains pending.

## 0.12.32 — 2026-10-01

- Добавлена отключённая по умолчанию диагностика положения панели: геометрия, поиск XAML и причина скрытия; алгоритм разметки не изменён.
- Added opt-in taskbar geometry/XAML/layout diagnostics without changing placement behavior.

## 0.12.31 — 2026-10-01

- Добавлен новый скриншот в описание и README.
- Added a new screenshot to the embedded description and README.

## 0.12.30 — 2026-10-01

- Добавлен режим всех фиксированных локальных дисков: отдельные колонки, полосы и предупреждения.
- Режим доступен в настройках и обоих меню; выбор диска возвращает одиночный вид.
- Added all-fixed-drive display with per-volume columns, bars, warnings and adaptive compact layout; settings and menu selection persist.

## 0.12.29 — 2026-10-01

- История перенесена в CHANGELOG.md; описания содержат только актуальную информацию.
- Обновлены правила агента для ведения отдельной истории и подготовки обновлений каталога.
- Moved development history to CHANGELOG.md and removed release lists from descriptions.

## Изменения 0.12.28 / Changes in 0.12.28

Кешируются загруженные элементы панели и Пуска. Список мониторов обновляется при изменении панелей и контрольной проверке раз в минуту.

Loaded taskbar and Start elements are cached. Monitor discovery runs on topology changes with a 60-second fallback.

## Изменения 0.12.27 / Changes in 0.12.27

Монитор сохраняется по пути устройства Windows, а не номеру DISPLAY. Прежний выбор переносится при обнаружении экрана; при недоступном пути остаётся имя DISPLAY.

Monitor selection stores the Windows device path and resolves the current GDI name; legacy choices migrate when detected, with a GDI fallback.

## Изменения 0.12.26 / Changes in 0.12.26

Меню используют кеш рабочего потока: диски обновляются раз в 30 секунд, мониторы — раз в пять секунд. При открытии меню системные запросы не выполняются.

Taskbar menus use cached drive and monitor lists collected by the worker, refreshed every 30 and five seconds respectively.

## Изменения 0.12.25 / Changes in 0.12.25

При выгрузке ожидается удаление интерфейса и обработчиков; убраны повторные записи статических подписей мониторов.

Final UI teardown completes before unload; redundant static monitor-label writes are removed.

## Изменения 0.12.24 / Changes in 0.12.24

Английское встроенное описание размещено первым; восстановлено пояснение о назначении отдельного мода.

English is now the default embedded description; the separate-mod rationale is restored.

## Изменения

- **0.12.23:** добавлены четыре актуальных скриншота в описание и README.
- **0.12.22:** ручной и автоматический компактный режимы объединены в подменю «Мини дизайн»; добавлены иконки остальных пунктов меню.
- **0.12.21:** автоматический компактный вид, быстрые пороги, сброс оформления, применение настроек Windhawk и иконки меню; добавлены регрессионные проверки.
- **0.12.20:** добавлен выбор точности чисел: 0, 1 или 2 знака после запятой.
- **0.12.19:** добавлен выбор положения через меню правой кнопки с сохранением выбора.
- **0.12.18:** ширина ограничивается свободной областью между кнопками и треем; при недостатке места индикатор скрывается.
- **0.12.17:** добавлены названия моделей мониторов из Windows; разрешение убрано из подписей.
- **0.12.16:** добавлено подменю «Монитор» с немедленным применением и сохранением выбора.
- **0.12.15:** исправлена ошибка YAML в описании выбора монитора: строки с двоеточиями заключены в кавычки.
- **0.12.14:** настройки мониторов объединены в один динамический выпадающий список с автоматическим обнаружением экранов.
- **0.12.13:** добавлен выбор основной, всех панелей или конкретного монитора с отдельным состоянием каждой панели.
- **0.12.12:** добавлена индикация нехватки места с порогом в процентах или ГиБ.
- **0.12.11:** добавлено подменю «Формат» с тремя вариантами и сохранением выбора.
- **0.12.10:** добавлены три темы оформления; палитры перенесены в подменю «Цвета».
- **0.12.9:** добавлен пункт «Обновить сейчас» для ручного обновления данных о диске.
- **0.12.8:** добавлен пункт «Открыть выбранный диск».
- **0.12.7:** добавлен переключатель «Мини дизайн» с сохранением компактного режима.
- **0.12.6:** переоформлено описание, добавлены актуальные действия меню и сведения о рамке.
- **0.12.5:** добавлен пункт «Управление дисками».
- **0.12.4:** добавлен пункт «Этот компьютер».
- **0.12.3:** меню правой кнопки с выбором и сохранением цветовой темы.
- **0.12.2:** высота и скругление рамки берутся у подсветки кнопки «Пуск».
- **0.12.1:** автоматическая ширина, анимации наведения и нажатия; убрана настройка максимальной ширины.


## История версий

### 0.12.23

**Русский:** добавлен блок из четырёх актуальных скриншотов в описание Windhawk
и README. Изображения открывают соответствующие страницы Imgur по нажатию.

**English:** added four current screenshots to the Windhawk description and
README, with clickable links to their Imgur pages.

### 0.12.22

**Русский:** «Мини дизайн» теперь подменю с двумя переключателями:
«Скрывать имя диска» и «Авто мини дизайн». Добавлены иконки остальных пунктов меню, включая вложенные варианты и выбор диска. Сохранённые значения не изменяются.

**English:** Mini design is now a submenu containing Hide drive name and
Automatic mini design toggles. Added icons to remaining menu items and nested choices, including drive selection. Existing selections are preserved.

### 0.12.21

**Русский:** добавлены автоматический компактный режим, готовые пороги нехватки
места, сброс оформления, применение настроек Windhawk и иконки меню. Увеличен
буфер чтения сохранённых строк для названий мониторов и списков устройств.
История в описании Windhawk сокращена до пяти версий, полная история сохранена здесь.
Добавлены воспроизводимые проверки расчёта размещения, форматов, порогов и выбора панелей.
Проверки живого Explorer вынесены в VALIDATION.md и не считаются пройденными автоматически.

**English:** added automatic compact layout, warning presets, appearance reset,
apply-settings action and menu icons. Expanded local-string buffers for monitor
labels and device lists. Windhawk history now shows five versions; full history
is retained here. Added regression checks and a separate live Explorer checklist.

### 0.12.20

**Русский:** добавлено подменю «Точность» с 0, 1 или 2 знаками после запятой.
Выбор сохраняется и применяется к ГиБ и процентам во всех режимах отображения.

**English:** added persistent 0, 1 or 2 decimal place selection for GiB and
percentages across all display modes.

### 0.12.19

**Русский:** добавлено подменю «Положение»: Автоматически, Слева и Справа.
Выбор применяется сразу на выбранных панелях и сохраняется.

**English:** added a persistent Position submenu with Automatic, Left and Right.
Selection applies immediately to the selected taskbars.

### 0.12.18

**Русский:** ограничение ширины учитывает реальные границы кнопок панели и трея.
При левом выравнивании расчёт учитывает резервирование места без обратной связи
с добавленным отступом. При недостатке места индикатор временно скрывается.

**English:** available width now accounts for taskbar button bounds and the tray.
Left-aligned reservation uses button span to avoid margin feedback. The indicator
is temporarily hidden when too little space remains.

### 0.12.17

**Русский:** меню и настройки показывают названия моделей мониторов через
DisplayConfigGetDeviceInfo. Если имя недоступно, сохраняется прежняя подпись.
Разрешение удалено; идентификатор устройства помогает различать одинаковые модели.

**English:** monitor menus and settings use model names from DisplayConfigGetDeviceInfo,
falling back to previous device labels. Resolution is removed; device identifiers
remain to distinguish identical models.

### 0.12.16

**Русский:** добавлено подменю «Монитор» с автоматически найденными экранами,
основной панелью и всеми панелями. Выбор применяется сразу и сохраняется.

**English:** added a Monitor submenu with detected displays, Primary taskbar
and All taskbars. Selection applies immediately and persists.

### 0.12.15

**Русский:** исправлена ошибка разбора YAML в описаниях настройки монитора.
Строки с двоеточиями заключены в кавычки.

**English:** fixed YAML parsing by quoting monitor descriptions containing colons.

### 0.12.14

**Русский:** два параметра монитора заменены одним пунктом «Выбор монитора для
отображения». В Windhawk 2.0 выпадающий список автоматически заполняется активными
мониторами, их названиями и разрешением, обновляется при изменении подключений.
В Windhawk 1.7.3 сохранена совместимость через текстовое поле.

**English:** replaced the two monitor settings with Monitor selection for display.
Windhawk 2.0 automatically lists active displays with names and resolution.
Windhawk 1.7.3 retains a text-field fallback.

### 0.12.13

**Русский:** добавлены режимы основной панели, всех панелей и конкретного монитора.
Каждая панель имеет собственные XAML-элементы, меню и анимацию. Общие настройки
применяются ко всем выбранным панелям. Дополнительные панели обнаруживаются
через CSecondaryTaskBand; отключённые панели удаляются при очередной проверке.

**English:** added Primary, All taskbars and Specific monitor selection. Each
panel owns its XAML elements, menu and animation, with shared disk and appearance
settings. Secondary panels use CSecondaryTaskBand; removed panels are cleaned up
on the next topology probe.

### 0.12.12

**Русский:** добавлена индикация нехватки места. Настраиваемый порог в процентах
или ГиБ меняет текст на красный во всех темах; системные высококонтрастные цвета
сохраняются. По умолчанию функция выключена.

**English:** added optional low-space thresholds in percent or GiB. Text turns
red in all appearance modes while high-contrast foreground colors are preserved.

### 0.12.11

**Русский:** подменю «Формат» позволяет выбрать «Свободно / Всего»,
«Занято / Всего» или «Свободно, %». Выбор сохраняется и работает в мини-дизайне.

**English:** added persistent Free / Total, Used / Total and Free, % formats,
including compact layout support.

### 0.12.10

**Русский:** добавлены темы «Системная», «Цветная полоса» и «Только текст»
с сохранением выбора. Десять цветовых пар перенесены в подменю «Цвета»,
доступное для цветной полосы. Мини дизайн совместим со всеми темами.

**English:** added persistent System, Color bar and Text only appearance modes.
The ten palettes now live in Colors, enabled for Color bar. Mini design works
with every appearance mode.

### 0.12.9

**Русский:** в меню правой кнопки добавлен пункт «Обновить сейчас».
Данные о выбранном диске перечитываются рабочим потоком без ожидания интервала
и без выполнения дискового запроса в потоке интерфейса панели задач.

**English:** added Refresh now to the context menu. The worker rereads the selected
drive without waiting for the refresh interval or running disk I/O on the taskbar UI thread.

### 0.12.8

**Русский:** добавлен пункт «Открыть выбранный диск» в меню правой кнопки.
Он открывает в Проводнике диск, который сейчас отображается в индикаторе.

**English:** added Open selected drive to the context menu. It opens the drive
currently displayed by the indicator in File Explorer.

### 0.12.7

**Русский:** в меню правой кнопки добавлен переключатель «Мини дизайн» с галочкой.
Он скрывает имя диска и включает компактную строку. Выбор сохраняется после
перезапуска Explorer; повторное нажатие возвращает обычный вид.

**English:** added a checked Mini design toggle to the context menu. It hides the
drive name and enables the compact single-line layout. The choice persists across
Explorer restarts; clicking again restores the standard layout.

### 0.12.6

**Русский:** обновлено и переоформлено описание во вкладке Windhawk и README.
Добавлены актуальные действия меню, автоматическая геометрия рамки и список
последних изменений. В AGENTS.md закреплено обязательное обновление описания
и истории версий при каждом выпуске.

**English:** refreshed the Windhawk description and README with current menu
actions, automatic hover geometry and recent changes. Agent rules now require
updating documentation and version history for every release.

## Изменения 0.12.5 / Changes in 0.12.5

**Русский:** в меню правой кнопки добавлен пункт «Управление дисками».
Он запускает системную консоль diskmgmt.msc через MMC с запросом прав администратора.

**English:** added Disk Management to the right-click menu. It launches the
system diskmgmt.msc console through MMC with administrator elevation.

## Изменения 0.12.4 / Changes in 0.12.4

**Русский:** в меню правой кнопки добавлен пункт «Этот компьютер», открывающий
соответствующий раздел Проводника.

**English:** added a This PC item to the right-click menu to open File Explorer
at This PC.

## Изменения 0.12.3 / Changes in 0.12.3

**Русский:** правая кнопка мыши на индикаторе открывает меню «Тема» с десятью
цветовыми парами. Текущий вариант отмечен галочкой. Выбор применяется сразу и
сохраняется после перезапуска Explorer. Изменение цветовой схемы в настройках
Windhawk заменяет выбор из меню; остальные настройки его сохраняют.
Левая кнопка по-прежнему открывает список дисков. Всплывающая подсказка не добавлена.

**English:** right-click opens a Theme submenu with ten color pairs and a check
mark for the current choice. Selection applies immediately and persists across
Explorer restarts. Changing the configured color scheme overrides the menu
selection; other settings preserve it. Left-click still selects drives.

## Изменения 0.12.2 / Changes in 0.12.2

**Русский:** высота подсветки и скругление берутся непосредственно из
`BackgroundElement` кнопки «Пуск», а не из высоты всей панели задач.
Ширина продолжает автоматически подстраиваться под текст.

**English:** the hover surface height and corner radius follow the Start button's
`BackgroundElement` instead of the full taskbar height. Width still follows the text.

## Изменения 0.12.1 / Changes in 0.12.1

**Русский:** ширина индикатора рассчитывается автоматически, настройка максимальной
ширины удалена. Рамка использует скругление 4 логические единицы, плавную подсветку
при наведении (120 мс) и нажатии (80 мс). Цветовые пары сохранены. Анимации
учитывают системную настройку Windows; всплывающая подсказка не добавляется.

**English:** automatic content-based width replaces the maximum-width setting.
The surface uses a 4-DIP corner radius with hover (120 ms) and pressed (80 ms)
transitions. Color pairs are preserved. Animations respect the Windows animation
setting; no tooltip is added.

## Изменения 0.12.0 / Changes in 0.12.0

**Русский:** отступ по умолчанию уменьшен до 15, добавлены три скриншота и
обновлено описание. Упрощена обработка старых значений цветовой схемы и режима
резервирования места.

**English:** reduced the default offset to 15, added three screenshots, and updated
the description. Simplified handling of legacy color-scheme and space-reservation values.

## Изменения 0.11.0 / Changes in 0.11.0

**Русский:** режим с именем диска снова использует две строки, а компактный
режим без имени остаётся однострочным. Высота рамки берётся у панели задач и
совпадает с высотой рамки кнопки «Пуск».

**English:** the named-drive mode uses two lines again, while the compact
name-hidden mode stays on one line. The frame height is taken from the taskbar
and matches the Start button frame height.

## Изменения 0.10.0 / Changes in 0.10.0

**Русский:** верхняя строка и объём объединены в одну горизонтальную строку;
рамка автоматически измеряется по её содержимому.

**English:** the drive name and capacity are now rendered in one horizontal
line, and the hover frame measures itself from that content.

## Изменения 0.9.1 / Changes in 0.9.1

**Русский:** при отображении имени разделитель `/` заменён на «из». При
включённой настройке скрытия имени нижняя строка стала компактной и содержит
только значения свободного и общего объёма.

**English:** when the drive name is shown, `/` is replaced with the Russian
word “из” (“of”). When the name is hidden, the second line is compact and
contains only the free and total values.

## Изменения 0.9.0 / Changes in 0.9.0

**Русский:** интервал обновления по умолчанию изменён на 600 секунд (10 минут),
а максимальное значение увеличено до 3600 секунд. Опрос диска не выполняет
запись на накопитель.

**English:** the default update interval is now 600 seconds (10 minutes), and
the maximum is 3600 seconds. Disk polling performs no writes to the drive.

Комментарии для новой логики сохранены на русском и английском языках.
Comments for the new logic are kept in both Russian and English.
