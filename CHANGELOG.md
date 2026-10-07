# Taskbar Disk Space — история изменений

**Последняя версия: 0.17.4 · 7 октября 2026**

В этом обновлении — лёгкая подсветка при наведении на цветные карточки дисков.

[Исходник мода](taskbar-disk-space.wh.cpp) · [Установка и описание](README.md) · [Обратная связь](https://github.com/Fatalko/taskbar-disk-space/issues)

> История авторских версий. Запись здесь не означает публикацию в официальном каталоге Windhawk.

## Навигация

- [0.17.4 — лёгкая подсветка при наведении](#version-0-17-4)
- [0.17.3 — размеры и прозрачность рамок](#version-0-17-3)
- [0.17.2 — подсветка отдельного диска](#version-0-17-2)
- [0.17.1 — компактный режим](#version-0-17-1)
- [0.17.0 — ручной набор дисков](#version-0-17-0)
- [0.16.0 — подсказки пунктов меню](#version-0-16-0)
- [0.15.0 — диски по доступному месту](#version-0-15-0)
- [0.14.2 — повторное открытие карточки](#version-0-14-2)
- [0.14.1 — оформление всплывающей карточки](#version-0-14-1)
- [0.14.0 — тема с фоновым отображением места](#version-0-14-0)
- [0.13.0 — фон дисков и кнопка списка](#version-0-13-0)

- [0.12.40 — исправление измерения ширины](#version-0-12-40)

- [0.12.39 — адаптивное размещение и меню](#version-0-12-39)

- [0.12.38 — значки и группы дисков](#version-0-12-38)
- [0.12.37 — подключение USB-накопителей](#version-0-12-37)
- [0.12.36 — размещение на вертикальной панели](#version-0-12-36)
- [Архив — 0.12.35 и более ранние версии](#version-archive)

---

<a id="version-0-17-4"></a>

## 0.17.4

**Дата:** 2026-10-07

### Исправлено

- В теме «Фон свободного места» и плитках букв добавлена лёгкая нейтральная подсветка карточки под курсором. Она располагается отдельным слоем, не меняя прозрачность постоянной заливки свободного/занятого места.
- Подсветка плавно появляется и исчезает за 120 мс; при отключённых анимациях Windows переключается сразу. Общий фон списка остаётся прозрачным, текст и данные остаются читаемыми.
- Меню, его пункты и настройки не изменены; схема n8n не обновляется по правилам проекта.

<details>
<summary>English</summary>

### Fixed

- Added a subtle neutral hover layer to Capacity background cards and letter tiles without changing the persistent capacity fill opacity.
- The highlight fades in and out over 120 ms, or switches immediately when Windows animations are disabled. The shared list container stays transparent and content remains readable.
- Menu items and settings are unchanged; the n8n map is not updated under the project rules.

</details>

---

<a id="version-0-17-3"></a>

## 0.17.3

**Дата:** 2026-10-07

### Исправлено

- Карточки дисков на горизонтальной панели и кнопка «Ещё · N» используют высоту и скругление рамки «Пуска»; содержимое центрируется. Обычный и компактный вид сохраняют единый размер рамки. На вертикальной панели используется минимальная высота, чтобы не обрезать многострочные карточки.
- Прозрачность нейтральных и цветных рамок индикатора вычисляется из полупрозрачной кисти «Пуска» с учётом её `Opacity`. Если кисть недоступна или неприменима, используется системный ресурс либо резервное значение 16/255 — около 6% непрозрачности.
- В теме «Фон свободного места» убрано дополнительное ослабление заливки: постоянный фон использует ту же эффективную прозрачность, без усиления при наведении. Общая подсветка списка остаётся отключённой; высококонтрастные системные цвета сохраняются.

<details>
<summary>English</summary>

### Fixed

- Horizontal drive cards and More · N use the Start frame height and corner radius, with centered content. Normal and compact cards share the frame size. Vertical cards use a minimum height so stacked text is not clipped.
- Neutral and capacity frames use the translucent Start brush's effective alpha, including brush opacity. When unavailable or unsuitable, use a system resource or a 16/255 fallback, about 6% opacity.
- Capacity background no longer applies a second opacity reduction or brightens on hover. Shared list highlighting remains disabled; high-contrast system colors are retained.

</details>

---

<a id="version-0-17-2"></a>

## 0.17.2

**Дата:** 2026-10-07

### Исправлено

- У списка дисков убрана общая подсветка контейнера: наведение или нажатие больше не выделяет весь список.
- В теме «Цветная полоса» наведение на отдельный диск больше не заливает его фон долями свободного/занятого места. Подсвечивается только карточка под курсором, нейтральным фоном; нижняя полоса сохраняется.
- Отдельная нейтральная подсветка работает и в системной теме, при недоступном объёме и в высококонтрастном режиме. Тема с постоянным фоном места, вариант «Только текст» и одиночный диск сохраняют своё оформление; меню и подсказки «Диски · N»/«Ещё · N» продолжают работать.

<details>
<summary>English</summary>

### Fixed

- Removed the shared hover/press highlight around a drive list.
- Color bar lists now highlight only the hovered drive with a neutral background, keeping the bottom capacity strip without adding a free/used capacity fill on hover.
- Per-drive neutral highlighting also works in the System theme, with unavailable capacity and in high contrast. Persistent Capacity background, Text only and single-drive appearance are preserved; Drives · N/More · N menus and tooltips keep working.

</details>

---

<a id="version-0-17-1"></a>

## 0.17.1

**Дата:** 2026-10-07

### Изменено

- Подменю «Мини дизайн» переименовано в «Компактный режим», а «Авто мини дизайн» — в «Автоматически».
- Автоматическая адаптация всегда включена: пункт отмечен галочкой и недоступен для переключения. При загрузке старое сохранённое выключение заменяется включением; остальные параметры оформления и выбор дисков сохраняются.
- Ручные варианты компактного режима сохраняют свой приоритет. Правила размещения дисков и перехода к более компактному виду не изменены.

<details>
<summary>English</summary>

### Changed

- Renamed Mini design to Compact mode and Automatic mini design to Automatic.
- Automatic adaptation is always enabled: the item is checked and disabled. Loading a previously saved disabled value migrates it to enabled; other appearance settings and drive selections are retained.
- Manual compact options retain their priority. Drive placement and compact fallback rules remain unchanged.

</details>

---

<a id="version-0-17-0"></a>

## 0.17.0

**Дата:** 2026-10-07

### Добавлено

- «Выбранные диски» в обоих меню: галочки позволяют составить ручной набор из локальных и внешних дисков. Отметка применяется сразу; «Показывать выбранные диски» возвращает сохранённый набор после переключения режима.
- Ручной набор сохраняется после перезапуска Explorer. Неотмеченные новые устройства не добавляются; отключённые отмеченные буквы сохраняются отдельными строками меню и возвращаются на панель при подключении с той же буквой.
- «Ещё · N» и «Диски · N» показывают сведения только о подключённых дисках выбранного набора. Пустой набор сообщает «Диски не выбраны», не переключаясь на все диски.
- У новых пунктов есть русские и английские пояснения; средняя кнопка на подключённом диске открывает его в Проводнике без изменения отметки.

### Изменено

- «Сбросить оформление» сохраняет ручной набор; «Применить настройки Windhawk» очищает отметки вместе с параметрами меню. Переключение на одиночный диск или другую группу сохраняет набор для повторного включения.
- Выбор хранится по буквам A–Z; строки нормализуются, повторы удаляются, произвольные пути и сетевые ресурсы не принимаются. Если букву получит другой том, набор будет показывать его.

<details>
<summary>English</summary>

- Added Selected drives in both menus with checkboxes for a manual set combining internal and external drives. Each check applies immediately; Show selected drives restores the saved set after changing modes.
- The set survives Explorer restarts. New unchecked devices are excluded. Disconnected selected letters remain listed separately and return to the taskbar when that letter reconnects.
- More · N and Drives · N show only connected drives from the selected set. An empty set shows No drives selected instead of reverting to all drives.
- New items have Russian and English hints; middle-click opens a connected drive in File Explorer without changing its selection.
- Reset appearance preserves the set; Apply Windhawk settings clears its checks along with menu overrides. Choosing a single drive or another group retains the set for later reuse.
- Store normalized, unique letters A–Z, rejecting arbitrary paths and network resources. If another volume receives a saved letter, the set displays that volume.

</details>

---

<a id="version-0-16-0"></a>

## 0.16.0

**Дата:** 2026-10-07

### Добавлено

- Короткие штатные подсказки при наведении на все пункты меню левой и правой кнопки: группы и отдельные диски, темы и палитры, форматы, точность, мониторы, положение, мини-дизайн, пороги и системные команды. Варианты подменю также имеют пояснения; разделители исключены.
- Пояснения доступны на русском и английском согласно языку интерфейса Windows, а также передаются средствам доступности. Подсказки дисков объясняют выбор левой кнопкой и открытие средней.

### Изменено

- Серые информационные строки допускают наведение без изменения настроек. В темах «Системная» и «Только текст» серое подменю цветов открывается для пояснений, но смена палитры заблокирована проверкой текущей темы.
- Используются штатные текстовые ToolTip без собственных окон, таймеров и обработчиков наведения. Карточки «Ещё · N» и «Диски · N» сохраняют прежнее оформление.

<details>
<summary>English</summary>

- Added short native hover hints to every command and option in both taskbar menus: drive groups and individual drives, appearances, palettes, capacity formats, precision, monitors, positions, mini designs, thresholds and system actions. Submenus also have hints; separators are excluded.
- Hints follow the Windows interface language (Russian or English) and are exposed as accessibility help text. Drive hints explain left-click selection and middle-click opening.
- Dimmed informational entries support hovering without changing settings. In System and Text only appearances, the dimmed Colors submenu can open for explanations, but palette changes are guarded by the current appearance.
- Used native plain-text tooltips without custom windows, timers or hover handlers. Existing More · N and Drives · N cards retain their design.

</details>

---

<a id="version-0-15-0"></a>

## 0.15.0

**Дата:** 2026-10-07

### Добавлено

- На горизонтальной панели в режиме списка отображаются только целые карточки дисков, которые помещаются в свободном участке. Место для «Ещё · N» резервируется заранее; выбранный вид и порядок по буквам сохраняются.
- «Ещё · N» показывает количество скрытых дисков. Наведение открывает пассивную карточку с их именами и данными о месте; нажатие открывает полное меню выбора дисков. Фильтр локальных/внешних дисков сохраняется.

### Изменено

- Автоматическое положение выбирает сторону, вмещающую больше карточек выбранного вида. При равном количестве сохраняется предпочтение по выравниванию значков; ручной выбор стороны соблюдается.
- В режиме списка авто мини-дизайн пробует более компактный вид только если ни одна карточка выбранного вида не помещается. Если карточки не помещаются, остаётся «Диски · N»; ручной режим счётчика сохранён.
- Количество пересчитывается при проверках панели не реже раза в пять секунд. Для возврата карточки нужны восемь свободных единиц XAML сверх её ширины; сокращение не откладывается. Диагностика сообщает видимое/скрытое количество и итоговую ширину.
- Полный снимок показаний сохраняется: скрытые диски доступны через меню и подсказку. Одиночный режим и вертикальный список с прокруткой сохраняют прежнее поведение. Подсказки остаются пассивными, содержимое открытой карточки не заменяется.

<details>
<summary>English</summary>

- Horizontal list mode shows the largest fitting prefix of whole drive cards, reserving More · N before choosing the count. The selected design and drive-letter order are preserved.
- More · N reports the hidden count. Hover displays a passive card containing hidden-drive names and capacity readings; left-click opens the complete drive menu. Local/external group filtering is retained.
- Automatic position chooses the side fitting more cards in the selected design; ties keep the preference associated with taskbar icon alignment. Manual side selection is respected.
- In list mode, automatic mini design compacts further only if no selected-design card fits. Drives · N remains the final fallback and an explicit manual mode.
- Recompute on taskbar probes at least every five seconds. Restoring a card needs eight extra logical pixels of headroom; shrinking is not delayed. Diagnostics include visible/hidden counts and final width.
- Retain the full reading snapshot for menus and tooltips. Single-drive and vertically scrolling list behavior is unchanged. Tooltips remain passive and their open content is not replaced.

</details>

---

<a id="version-0-14-2"></a>

## 0.14.2

**Дата:** 2026-10-06

### Исправлено

- После сообщения о падении Explorer при повторном наведении карточка переведена в пассивный режим: интерактивный ScrollViewer удалён, перехват мыши отключён. Дампы подтверждают исключение XAML с HRESULT 0x80070057; точный внутренний вызов не восстановлен, повторные наведения требуется проверить в Explorer.
- Подсказка явно привязана к XamlRoot и элементу своей панели. Содержимое обновляется только при закрытой карточке, а положение меняется только при необходимости; полностью настроенная карточка присоединяется к кнопке после создания содержимого.

### Изменено

- Большие списки размещаются в колонках без прокрутки, в пределах рабочей области монитора и текущего DPI. При нехватке места показывается число оставшихся дисков. Имена и объёмы ограничены двумя строками; счётчик, палитра и шкалы сохранены.

<details>
<summary>English</summary>

- Addressed reported repeated-hover Explorer crashes by making the card passive: removed its interactive ScrollViewer and disabled mouse hit testing. Dumps show a XAML exception with HRESULT 0x80070057; the exact internal call could not be recovered, so repeated-hover testing in Explorer is still required.
- Explicitly associated the tooltip with its owner's XamlRoot and placement target. Content refreshes only while closed, placement changes only when needed, and the configured tooltip attaches after its content is created.
- Long lists use columns instead of scrolling, bounded by the monitor work area and DPI. Any remaining drive count is shown when space runs out. Names and capacity wrap to at most two lines; count, palette and capacity bars are preserved.

</details>

---

<a id="version-0-14-1"></a>

## 0.14.1

**Дата:** 2026-10-06

### Изменено

- Текстовая подсказка «Диски · N» заменена скруглённой карточкой: заголовок выбранной группы, счётчик дисков, отдельные блоки с буквой, именем, объёмом, процентом свободного места и цветовой шкалой свободно/занято.
- Сохранены выбранные формат и точность. Палитра и предупреждения о нехватке места применяются к карточке; светлая, тёмная и высококонтрастная темы Windows учитываются.
- Длинные имена переносятся до двух строк; большой список прокручивается, высота ограничена рабочей областью монитора с учётом DPI. Карточка открывается со стороны рабочего стола для всех положений панели.
- Карточка использует готовые показания выбранной группы без дополнительных обращений к дискам; при выходе из режима списка и отключении мода подсказка закрывается и отсоединяется.

<details>
<summary>English</summary>

- Redesigned the Drives · N tooltip as a rounded card with a group heading, drive count and individual drive panels containing the letter, name, capacity, free-space percentage and a free/used bar.
- Preserved the selected capacity format and precision; applied the palette and low-space warnings, with light, dark and high-contrast colors.
- Long names wrap to two lines. Long lists scroll within a DPI-aware monitor work-area limit; placement faces the desktop on each taskbar edge.
- Reused the selected group's cached readings without extra disk queries. The tooltip closes and detaches when leaving list-button mode or disabling the mod.

</details>

---

<a id="version-0-14-0"></a>

## 0.14.0

**Дата:** 2026-10-06

### Добавлено

- «Тема → Фон свободного места»: свободное и занятое место постоянно отображаются фоном каждого диска списка, без нижней полосы. При наведении фон плавно становится ярче.
- Подменю «Цвета» доступно в новой теме; выбор темы сохраняется. Высококонтрастный режим отключает цветовой фон, отключённые анимации Windows учитываются. Плитки букв сохраняют собственный фон.

<details>
<summary>English</summary>

- Added Theme → Capacity background: each drive in the list has a persistent free/used background instead of a bottom strip, which brightens smoothly on hover.
- Colors are available for the new persistent theme selection. High contrast disables the capacity background, Windows animation preferences are respected, and letter tiles retain their own background.

</details>

---

<a id="version-0-13-0"></a>

## 0.13.0

**Дата:** 2026-10-06

### Добавлено

- В теме «Цветная полоса» каждый диск списка получает фон свободного/занятого места при наведении с плавным переходом; учитываются высококонтрастная тема и отключение анимаций Windows.
- Подсказка кнопки «Диски · N» показывает информацию о дисках выбранной группы в текущем формате и точности, без дополнительных запросов к дискам.
- «Мини дизайн → Диски · N» позволяет включить кнопку списка вручную, в том числе на вертикальной панели; выбор сохраняется и сбрасывается существующими командами оформления.

### Изменено

- Для новых наборов изменений принято правило MAJOR.MINOR.PATCH: исправления повышают PATCH, новые функции — MINOR, несовместимые изменения — MAJOR. Исторические версии сохранены.

<details>
<summary>English</summary>

- Added animated per-drive free/used hover backgrounds in Color bar appearance, respecting high contrast and Windows animation preferences.
- Drives · N has a native tooltip containing the selected group's capacity readings in the current format and precision, without extra disk queries.
- Added a persistent manual Drives · N option under Mini design, including vertical taskbars; existing appearance reset commands clear it.
- Adopted MAJOR.MINOR.PATCH numbering for new changes; historical versions are unchanged.

</details>

---

<a id="version-0-12-40"></a>

## 0.12.40

**Дата:** 2026-10-06

### Исправлено

- Прежний отступ индикатора больше не входит в измерение содержимого: перед Measure обнуляется Margin. Исправлен рост измеренной ширины при размещении справа, ошибочно включавший кнопку «Диски · N» даже на свободной панели.
- Поиск справа учитывает свободные промежутки между отдельными группами кнопок, а не только участок после самой правой кнопки; добавлены регрессионные проверки таких промежутков и отсутствия перекрытий.

<details>
<summary>English</summary>

- Reset the previous placement Margin before measuring intrinsic content width. Fixed growing width estimates and unnecessary Drives · N fallback on otherwise spacious taskbars.
- Find free gaps between separated right-side button groups instead of considering only the section after the last button; added gap and overlap regression coverage.

</details>

---

<a id="version-0-12-39"></a>

## 0.12.39

**Дата:** 2026-10-06

### Добавлено

- Измерение реальных размеров полного, компактного, плиточного вида и кнопки списка; автоматический выбор свободного участка слева/справа с учётом штатных кнопок, виджета и трея.
- «Буквы дисков и полоса» в мини-дизайне: постоянный фон свободного/занятого места; резервная кнопка «Диски · N» при нехватке места.
- Расширенные логи свободных участков, DPI, ширины всех вариантов и причины выбора; регрессионные сценарии 1080p/1440p, масштабы 100/125/150%, тесная панель и резервные виды.
- Средняя кнопка на пункте диска открывает Проводник без смены выбранной группы; подсказка объясняет действие.

### Изменено

- Группы меню переименованы в «Автоматический режим», «Локальные диски» и «Внешние диски»; автоматический режим получил отдельный значок.
- Убран фиксированный минимум ширины на диск при горизонтальном размещении; левый отступ автоматического режима ограничивается реальным свободным участком.

<details>
<summary>English</summary>

- Added measured full/compact/tile/list-button views and automatic left/right placement around native buttons, Widgets and the tray.
- Added persistent drive-letter capacity tiles, a Drives · N fallback, detailed layout diagnostics and geometry tests for 1080p/1440p and 100/125/150% scaling.
- Middle-click opens a drive in Explorer without changing the group; drive menu tooltips explain the shortcut.
- Renamed groups to Automatic mode, Local drives and External drives, with a distinct automatic icon. Removed the fixed horizontal minimum per drive and constrained the preferred offset to the safe gap.

</details>

---

<a id="version-0-12-38"></a>

## 0.12.38

**Дата:** 2026-10-02

### Добавлено

- Добавлены разные значки внутренних и внешних дисков в меню левой кнопки и сохраняемые режимы «Все диски», «Все локальные диски», «Все внешние диски». USB-диски определяются по свойствам устройства в рабочем потоке; меню использует кеш.

<details>
<summary>English</summary>

- Added distinct local/external icons and persistent All drives, All local drives and All external drives groups. USB disks are classified from device properties on the worker; menus use cached results.

</details>

---

<a id="version-0-12-37"></a>

## 0.12.37

**Дата:** 2026-10-02

### Добавлено

- Добавлена поддержка USB-флешек и внешних дисков с назначенной буквой; подключение и отключение проверяются каждые две секунды. В режиме всех дисков список обновляется автоматически, одиночный режим сохраняет выбор.

<details>
<summary>English</summary>

- Added removable USB drives and external disks with drive letters, with automatic connection/removal detection every two seconds. All-drive mode updates automatically; single-drive selection is preserved.

</details>

---

<a id="version-0-12-36"></a>

## 0.12.36

**Дата:** 2026-10-01

### Изменено

- На вертикальных панелях оставлено только автоматическое размещение сверху; меню показывает единственный отмеченный вариант.
- Сохранён выбор положения для горизонтальной панели; возврат вниз/вверх его восстанавливает.

<details>
<summary>English</summary>

- Vertical taskbars now use only automatic top placement; horizontal position preferences are preserved.

</details>

---

<a id="version-archive"></a>

## Архив версий

<details>
<summary>Открыть историю 0.12.35 и более ранних версий / Older versions</summary>

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

</details>
