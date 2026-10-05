
int main() {
    strings={{L"Drive",L"C:"},{L"FreeColor",L"green-red"},{L"DisplayOn",L"primary"},
             {L"ReserveSpace",L"auto"},{L"LowSpaceMode",L"off"}};
    integers={{L"UpdateInterval",600},{L"LeftOffset",160},{L"LowSpaceThreshold",10}};
    LoadSettings();
    assert(g_settings.drive==L"C:" && g_settings.colorScheme==L"green-red");
    assert(g_settings.autoCompact && g_settings.precision==1);
    storage[L"SelectedTheme"]=L"blue-orange";
    storage[L"SelectedMiniDesign"]=L"1";
    storage[L"SelectedAppearance"]=L"text";
    storage[L"SelectedFormat"]=L"used";
    storage[L"SelectedPrecision"]=L"2";
    storage[L"SelectedMonitor"]=L"\\\\.\\DISPLAY2";
    storage[L"SelectedPosition"]=L"right";
    storage[L"SelectedLowSpace"]=L"gib:20";
    storage[L"SelectedAutoCompact"]=L"0";
    integers[L"UpdateInterval"]=800;
    LoadSettings();
    assert(g_settings.colorScheme==L"blue-orange" && g_settings.hideDriveName);
    assert(g_settings.appearance==L"text" && g_settings.format==L"used" && g_settings.precision==2);
    storage[L"SelectedAppearance"]=L"background"; LoadSettings();
    assert(g_settings.appearance==L"background");
    // Persistent fill only in the background theme; hover restores full opacity.
    assert(DriveBackgroundOpacity(L"background",true,false,false)==0.65);
    assert(DriveBackgroundOpacity(L"background",true,true,false)==1.0);
    assert(DriveBackgroundOpacity(L"background",false,true,false)==0.0);
    assert(DriveBackgroundOpacity(L"background",true,true,true)==0.0);
    assert(DriveBackgroundOpacity(L"bar",true,false,false)==0.0);
    assert(DriveBackgroundOpacity(L"bar",true,true,false)==1.0);
    assert(DriveBackgroundOpacity(L"system",true,true,false)==0.0);
    assert(DriveBackgroundOpacity(L"text",true,true,false)==0.0);
    assert(g_settings.displayOn==L"\\\\.\\DISPLAY2" && g_settings.position==L"right");
    assert(g_settings.lowSpaceMode==L"gib" && g_settings.lowSpaceThreshold==20 && !g_settings.autoCompact);
    strings[L"FreeColor"]=L"cyan-purple";
    strings[L"DisplayOn"]=L"all";
    strings[L"ReserveSpace"]=L"left";
    integers[L"LowSpaceThreshold"]=50;
    LoadSettings();
    assert(g_settings.colorScheme==L"cyan-purple" && g_settings.displayOn==L"all");
    assert(g_settings.position==L"left" && g_settings.lowSpaceMode==L"off" && g_settings.lowSpaceThreshold==50);
    ResetAppearance(); LoadSettings();
    assert(g_settings.colorScheme==L"green-red" && g_settings.appearance==L"bar");
    assert(g_settings.format==L"free" && g_settings.precision==1 && !g_settings.hideDriveName && g_settings.autoCompact);
    assert(g_settings.displayOn==L"all" && g_settings.position==L"left" && g_settings.drive==L"C:");
    ApplyConfiguredSettings();
    assert(g_settings.colorScheme==L"cyan-purple" && g_settings.format==L"free");
    assert(g_settings.displayOn==L"all" && g_settings.position==L"left");
    storage[L"SelectedLowSpace"]=L"percent:9999999"; LoadSettings();
    assert(g_settings.lowSpaceThreshold==100);
    storage[L"SelectedLowSpace"]=L"gib:bad"; LoadSettings();
    assert(g_settings.lowSpaceMode==L"off" && g_settings.lowSpaceThreshold==50);

    assert(LowSpaceReached(10,100,L"percent",10));
    assert(!LowSpaceReached(11,100,L"percent",10));
    assert(!LowSpaceReached(0,0,L"percent",100));
    assert(!LowSpaceReached(0,100,L"off",100));
    assert(LowSpaceReached(10ULL<<30,100ULL<<30,L"gib",10));
    assert(!LowSpaceReached((10ULL<<30)+1,100ULL<<30,L"gib",10));
    assert(!LowSpaceReached(101,100,L"percent",100));
    assert(FormatGiB(1.256,true,2)==L"1,26");
    assert(FormatGiB(1.256,true,1)==L"1,3");
    assert(FormatGiB(1.6,true,0)==L"2");
    assert(FormatGiB(0.0,true,2)==L"0,00");
    assert(CapacityText(25ULL<<30,100ULL<<30,true,true,L"used",0)==L"75 / 100 ГиБ");
    assert(CapacityText(25ULL<<30,100ULL<<30,true,true,L"percent",2)==L"25,00 %");
    assert(CapacityText(110ULL<<30,100ULL<<30,true,true,L"used",0)==L"0 / 100 ГиБ");
    assert(ShouldUseCompact(false,true,300,160,200));
    assert(!ShouldUseCompact(false,true,150,160,200));
    assert(!ShouldUseCompact(false,true,200,300,100));
    assert(!ShouldUseCompact(false,false,300,160,200));
    assert(ShouldUseCompact(true,false,100,300,200));
    ButtonBounds centered{600,1100,true};
    assert(AvailableIndicatorWidth(1920,160,220,false,false,centered)==428);
    assert(AvailableIndicatorWidth(1920,220,220,true,false,centered)==588);
    ButtonBounds left{200,700,true}, shifted{400,900,true}, full{20,1900,true};
    assert(AvailableIndicatorWidth(1920,160,220,false,true,left)==
           AvailableIndicatorWidth(1920,160,220,false,true,shifted));
    assert(AvailableIndicatorWidth(1920,220,220,true,false,full)==0);
    // Actual free intervals, including a left Widgets button and centered pinned apps.
    auto gaps = FindHorizontalGaps(1920,220,600, {{600,500},{0,140}});
    assert(gaps.left.left==152 && gaps.left.width==436);
    assert(gaps.right.left==1112 && gaps.right.width==588);
    std::array<double,4> widths{500,300,120,80};
    auto placement = ChooseHorizontalLayout(gaps,true,false,false,widths,0,true);
    assert(placement.mode==0 && placement.right); // Full view fits on the other side.
    placement = ChooseHorizontalLayout(gaps,false,false,false,widths,0,true);
    assert(placement.mode==1 && !placement.right); // Manual Left stays on the left.
    placement = ChooseHorizontalLayout(gaps,true,true,false,widths,0,true);
    assert(placement.mode==0 && placement.right);
    HorizontalGaps tiny{{15,140},{1600,100}};
    placement=ChooseHorizontalLayout(tiny,true,false,false,widths,0,true);
    assert(placement.mode==2 && !placement.right); // Letter tiles, not hidden.
    tiny.left.width=90; tiny.right.width=70;
    assert(ChooseHorizontalLayout(tiny,true,false,false,widths,0,true).mode==3);
    tiny.left.width=60;
    assert(ChooseHorizontalLayout(tiny,true,false,false,widths,0,true).mode==-1);
    assert(ChooseHorizontalLayout(gaps,true,false,false,widths,2,true).mode==2);
    // Many pinned apps leave only a short left section on a 1080p monitor.
    gaps=FindHorizontalGaps(1920,300,120,{{120,1400}});
    assert(gaps.left.width==93 && gaps.right.width==88);
    assert(ChooseHorizontalLayout(gaps,true,false,false,widths,0,true).mode==3);
    // DPI tests convert to logical coordinates; no physical pixels mixed with XAML.
    for (double physical : {1920.0,2560.0}) {
        for (double scale : {1.0,1.25,1.5}) {
            const double logical=physical/scale;
            const double start=logical*0.3, buttonEnd=logical*0.7;
            auto geometry=FindHorizontalGaps(logical,220,start,{{0,100},{start,buttonEnd-start}});
            auto chosen=ChooseHorizontalLayout(geometry,true,false,false,widths,0,true);
            assert(chosen.mode>=0);
            assert(chosen.gap.left>=0 && chosen.gap.left+chosen.gap.width<=logical-220+0.001);
            assert(widths[chosen.mode]<=chosen.gap.width);
        }
    }
    // Overlapping/off-screen buttons, empty geometry and ordering do not manufacture gaps.
    gaps=FindHorizontalGaps(1920,220,600,{{650,500},{600,300},{-20,160},{5000,50}});
    assert(gaps.left.left==152 && gaps.right.left==1162);
    assert(FindHorizontalGaps(0,220,0,{}).left.width==0);
    assert(FindHorizontalGaps(1920,220,0,{{0,1920}}).right.width==0);
    widths[0]=std::numeric_limits<double>::quiet_NaN();
    assert(ChooseHorizontalLayout({{15,500},{0,0}},false,false,false,widths,0,true).mode==1);
    gaps=FindHorizontalGaps(1920,220,600,{{std::numeric_limits<double>::quiet_NaN(),100},{600,500}});
    assert(gaps.left.width==573 && gaps.right.width==588);
    // Simulated measured blocks grow with both name width and drive count.
    for (int drives : {1,3,10,26}) {
        for (double nameWidth : {30.0,300.0}) {
            std::array<double,4> content{16+drives*(nameWidth+12),16+drives*110.0,
                                       16+drives*44.0,80};
            auto choice=ChooseHorizontalLayout({{15,400},{1100,500}},true,false,false,content,0,true);
            assert(choice.mode>=0 && content[choice.mode]<=choice.gap.width);
            if (drives==26) assert(choice.mode==3);
        }
    }
    // A distant native toggle near the tray must not erase a large free middle section.
    gaps=FindHorizontalGaps(2560,360,15,{{15,1000},{2080,24}});
    assert(gaps.right.left==1027 && gaps.right.width==1041);
    std::array<double,4> largeBlock{700,450,136,80};
    assert(ChooseHorizontalLayout(gaps,true,true,false,largeBlock,0,true).mode==0);
    // A merged/overlapping cluster may block a gap, but isolated late buttons must not.
    gaps=FindHorizontalGaps(2560,360,15,{{15,1000},{900,700},{2080,24}});
    assert(gaps.right.left==1612 && gaps.right.width==456);
    assert(ChooseHorizontalLayout(gaps,true,true,false,largeBlock,0,true).mode==1);
    // All returned free intervals stay disjoint from occupied rectangles.
    const std::vector<LayoutGap> scattered{{15,200},{500,150},{800,100},{1800,200}};
    gaps=FindHorizontalGaps(2560,300,15,scattered);
    for (const auto& gap : {gaps.left,gaps.right}) {
        if (gap.width<=0) continue;
        for (const auto& block : scattered)
            assert(gap.left+gap.width<=block.left || gap.left>=block.left+block.width);
    }
    Reading info;
    info.title=L"C:"; info.capacity=L"25 / 100 GiB";
    assert(DriveTooltip(info)==L"C: — 25 / 100 GiB");
    Reading usb; usb.title=L"E:"; usb.capacity=L"75 %";
    Reading selected; selected.drives={info,usb};
    assert(DriveTooltip(selected)==L"C: — 25 / 100 GiB\nE: — 75 %");
    selected.drives={usb}; assert(DriveTooltip(selected)==L"E: — 75 %");
    storage[L"SelectedSummaryButton"]=L"1"; LoadSettings(); assert(g_settings.summaryButton);
    ResetAppearance(); assert(!g_settings.summaryButton);
    storage[L"SelectedSummaryButton"]=L"1"; ApplyConfiguredSettings(); assert(!g_settings.summaryButton);
    // Menu choice persists and is cleared by the existing reset/apply commands.
    storage[L"SelectedLetterTiles"]=L"1"; LoadSettings(); assert(g_settings.letterTiles);
    ResetAppearance(); assert(!g_settings.letterTiles);
    storage[L"SelectedLetterTiles"]=L"1"; ApplyConfiguredSettings(); assert(!g_settings.letterTiles);
    TaskbarWindow primary{nullptr,1,L"\\\\.\\DISPLAY1",true}, secondary{nullptr,2,L"\\\\.\\DISPLAY2",false};
    Settings choice;
    assert(IsSelectedTaskbar(choice,primary) && !IsSelectedTaskbar(choice,secondary));
    choice.displayOn=L"all";
    assert(IsSelectedTaskbar(choice,primary) && IsSelectedTaskbar(choice,secondary));
    choice.displayOn=L"\\\\.\\display2";
    assert(!IsSelectedTaskbar(choice,primary) && IsSelectedTaskbar(choice,secondary));
    choice.displayOn=L"disconnected";
    assert(!IsSelectedTaskbar(choice,primary) && !IsSelectedTaskbar(choice,secondary));
    UiState a,b;
    { UiScope outer(&a); assert(g_activeUi==&a);
      {UiScope inner(&b); assert(g_activeUi==&b);} assert(g_activeUi==&a); }
    assert(g_activeUi==nullptr);
    std::cout << "Settings, thresholds, formats, compact views, free gaps, DPI scenarios and monitor routing passed.\n";
}
