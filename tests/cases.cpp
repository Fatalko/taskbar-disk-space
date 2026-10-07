
int main() {
    strings={{L"Drive",L"C:"},{L"FreeColor",L"green-red"},{L"DisplayOn",L"primary"},
             {L"ReserveSpace",L"auto"},{L"LowSpaceMode",L"off"}};
    integers={{L"UpdateInterval",600},{L"LeftOffset",160},{L"LowSpaceThreshold",10}};
    LoadSettings();
    assert(g_settings.drive==L"C:" && g_settings.colorScheme==L"green-red");
    assert(g_settings.autoCompact && g_settings.precision==1);
    // Canonical, letter-only sets: no paths, duplicates, network shares or junk.
    assert(SerializeManualDrives(ParseManualDrives(L"e:;C:,c:; d:\\ Z"))==L"C:;D:;E:;Z:");
    assert(ParseManualDrives(L"C:\\folder;\\\\server\\share;1:;AA:;?:")==0);
    assert(ParseManualDrives(L"; , \t\r\n")==0);
    assert(SerializeManualDrives(0).empty());
    assert(ParseManualDrives(SerializeManualDrives(0x03ffffff))==0x03ffffff);
    assert(SerializeManualDrives(0xffffffff).size()==77); // Only A through Z are stored.
    SetManualDrive(L"c",true);
    SetManualDrive(L"E:",true);
    assert(g_settings.showAllDrives && g_settings.driveGroup==L"manual");
    assert(storage[L"SelectedManualDrives"]==L"C:;E:");
    SetManualDrive(L"C:",true); // Idempotent add, not an accidental toggle.
    assert(storage[L"SelectedManualDrives"]==L"C:;E:");
    LoadSettings();
    assert(g_settings.driveGroup==L"manual" && g_settings.manualDrives==ParseManualDrives(L"C:;E:"));
    assert(MatchesDriveGroup(g_settings,L"C:",false));
    assert(MatchesDriveGroup(g_settings,L"E:",true));
    assert(!MatchesDriveGroup(g_settings,L"D:",false));
    assert(!MatchesDriveGroup(g_settings,L"F:",true)); // A new USB volume is not added to this set.
    assert(!MatchesDriveGroup(g_settings,L"\\\\server\\share",true));
    // Disconnecting a letter does not erase its saved selection; removal is explicit.
    assert(storage[L"SelectedManualDrives"]==L"C:;E:");
    SetManualDrive(L"E:",false);
    assert(storage[L"SelectedManualDrives"]==L"C:");
    SetManualDrive(L"not-a-drive",true);
    assert(storage[L"SelectedManualDrives"]==L"C:");
    SetManualDrive(L"C:",false);
    LoadSettings();
    assert(g_settings.manualDrives==0 && g_settings.driveGroup==L"manual" && g_settings.showAllDrives);
    assert(!MatchesDriveGroup(g_settings,L"C:",false)); // Empty means empty, never all drives.
    SetManualDrive(L"D:",true);
    ResetAppearance(); LoadSettings();
    assert(g_settings.manualDrives==ParseManualDrives(L"D:") && g_settings.driveGroup==L"manual");
    SetAllDrives(true,L"local"); LoadSettings();
    assert(MatchesDriveGroup(g_settings,L"C:",false) && !MatchesDriveGroup(g_settings,L"E:",true));
    assert(g_settings.manualDrives==ParseManualDrives(L"D:"));
    SetAllDrives(true,L"external"); LoadSettings();
    assert(!MatchesDriveGroup(g_settings,L"C:",false) && MatchesDriveGroup(g_settings,L"E:",true));
    SetAllDrives(true); LoadSettings();
    assert(MatchesDriveGroup(g_settings,L"C:",false) && MatchesDriveGroup(g_settings,L"E:",true));
    SetAllDrives(true,L"manual"); LoadSettings();
    assert(MatchesDriveGroup(g_settings,L"D:",false));
    SetAllDrives(false,L"manual"); LoadSettings();
    assert(!g_settings.showAllDrives && g_settings.manualDrives==ParseManualDrives(L"D:"));
    assert(g_settings.drive==L"C:"); // Original single-drive selection is retained.
    SetAllDrives(true,L"manual"); LoadSettings();
    assert(g_settings.showAllDrives && g_settings.driveGroup==L"manual");
    ApplyConfiguredSettings();
    assert(g_settings.manualDrives==0 && g_settings.driveGroup==L"all" && !g_settings.showAllDrives);
    assert(storage[L"SelectedManualDrives"].empty());
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
    // Persistent capacity fill uses the native brush alpha without a second opacity multiplier.
    assert(DriveBackgroundOpacity(L"background",true,false,false)==1.0);
    assert(DriveBackgroundOpacity(L"background",true,true,false)==1.0);
    assert(DriveBackgroundOpacity(L"background",false,true,false)==1.0); // Neutral hover for unavailable capacity.
    assert(DriveBackgroundOpacity(L"background",true,true,true)==1.0); // System highlight in high contrast.
    assert(DriveBackgroundOpacity(L"bar",true,false,false)==0.0);
    assert(DriveBackgroundOpacity(L"bar",true,true,false)==1.0);
    assert(DriveBackgroundOpacity(L"system",true,true,false)==1.0);
    assert(DriveBackgroundOpacity(L"system",false,false,false)==0.0);
    assert(DriveBackgroundOpacity(L"bar",false,true,false)==1.0);
    assert(DriveBackgroundOpacity(L"bar",true,true,true)==1.0);
    assert(DriveBackgroundOpacity(L"text",true,true,false)==0.0);
    assert(EffectiveBrushAlpha(32,0.5)==16);
    assert(EffectiveBrushAlpha(16,1.0)==16);
    assert(EffectiveBrushAlpha(255,0.0)==0);
    assert(EffectiveBrushAlpha(32,2.0)==32);
    assert(EffectiveBrushAlpha(32,-1.0)==0);
    assert(EffectiveBrushAlpha(32,std::numeric_limits<double>::quiet_NaN())==0);
    assert(g_settings.displayOn==L"\\\\.\\DISPLAY2" && g_settings.position==L"right");
    assert(g_settings.lowSpaceMode==L"gib" && g_settings.lowSpaceThreshold==20 && g_settings.autoCompact);
    assert(storage[L"SelectedAutoCompact"]==L"1"); // Migrate the formerly disabled option on reload.
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
    // Eight volumes: reserve the More button before choosing whole cards.
    std::array<std::vector<double>,3> cards;
    cards[0]=std::vector<double>(8,100);
    cards[1]=std::vector<double>(8,70);
    cards[2]=std::vector<double>(8,40);
    std::vector<double> more(9,60);
    auto partial=ChooseDriveListLayout({{15,500},{1000,540}},true,false,false,cards,more,80,0,true);
    assert(partial.mode==0 && partial.visible==4 && partial.right && partial.width==524);
    partial=ChooseDriveListLayout({{15,500},{1000,540}},false,false,false,cards,more,80,0,true);
    assert(partial.mode==0 && partial.visible==3 && !partial.right && partial.width==412);
    partial=ChooseDriveListLayout({{15,500},{1000,500}},true,false,false,cards,more,80,0,true);
    assert(partial.visible==3 && !partial.right); // Equal counts keep the preferred side.
    partial=ChooseDriveListLayout({{15,500},{1000,500}},true,true,false,cards,more,80,0,true);
    assert(partial.visible==3 && partial.right);
    auto fit=FitDrivePrefix(cards[0],more,900);
    assert(fit.visible==8 && fit.width==900); // No More button when every card fits.
    assert(FitDrivePrefix(cards[0],more,899).visible==7);
    assert(FitDrivePrefix(cards[0],more,188).visible==1);
    assert(FitDrivePrefix(cards[0],more,187).visible==0);
    // Expansion has hysteresis; shrink never allows a card to overlap native buttons.
    assert(FitDrivePrefix(cards[0],more,526,3).visible==3);
    assert(FitDrivePrefix(cards[0],more,532,3).visible==4);
    assert(FitDrivePrefix(cards[0],more,523,4).visible==3);
    assert(FitDrivePrefix(cards[0],more,907,7).visible==7);
    assert(FitDrivePrefix(cards[0],more,908,7).visible==8);
    partial=ChooseDriveListLayout({{15,500},{1000,526}},true,false,false,cards,more,80,0,true,0,3);
    assert(partial.visible==3 && !partial.right); // Near-threshold growth on the other side also waits.
    partial=ChooseDriveListLayout({{15,500},{1000,532}},true,false,false,cards,more,80,0,true,0,3);
    assert(partial.visible==4 && partial.right);
    // Manual designs and positions remain effective; compact only if no selected card fits.
    partial=ChooseDriveListLayout({{15,500},{1000,540}},false,false,true,cards,more,80,1,false);
    assert(partial.mode==1 && partial.right && partial.visible==5);
    partial=ChooseDriveListLayout({{15,160},{1000,0}},true,false,false,cards,more,80,0,true);
    assert(partial.mode==1 && partial.visible==1);
    partial=ChooseDriveListLayout({{15,160},{1000,0}},true,false,false,cards,more,80,0,false);
    assert(partial.mode==3 && partial.visible==0 && partial.width==80);
    partial=ChooseDriveListLayout({{15,500},{1000,540}},true,false,false,cards,more,80,3,true);
    assert(partial.mode==3 && partial.visible==0); // Explicit Drives · N stays a count button.
    assert(ChooseDriveListLayout({{15,70},{1000,70}},true,false,false,cards,more,80,0,true).mode==-1);
    cards[0][0]=700;
    partial=ChooseDriveListLayout({{15,500},{1000,540}},true,false,false,cards,more,80,0,true);
    assert(partial.mode==1 && partial.visible>0); // A long first name can use auto mini.
    cards[0][0]=100;
    // Full one-card lists must not reserve a nonexistent hidden-drive button.
    assert(FitDrivePrefix({100},{0,60},116).visible==1);
    assert(FitDrivePrefix({}, {0},500).visible==0);
    assert(FitDrivePrefix({std::numeric_limits<double>::quiet_NaN()},{0,60},500).visible==0);
    assert(FitDrivePrefix(cards[0],more,std::numeric_limits<double>::infinity()).visible==0);
    // Counts and variable text widths remain within actual DPI-adjusted gaps.
    for (size_t diskCount : {size_t{1},size_t{3},size_t{8},size_t{26}}) {
        std::array<std::vector<double>,3> sample;
        for (size_t i=0;i<diskCount;++i) {
            sample[0].push_back(90+37*(i%3));
            sample[1].push_back(72);
            sample[2].push_back(40);
        }
        std::vector<double> button(diskCount+1,60);
        for (size_t i=10;i<button.size();++i) button[i]=68;
        for (double physical : {1920.0,2560.0}) for (double scale : {1.0,1.25,1.5,2.0}) {
            auto space=FindHorizontalGaps(physical/scale,220,physical/scale*.3,
                {{0,100},{physical/scale*.3,physical/scale*.4}});
            auto chosen=ChooseDriveListLayout(space,true,false,false,sample,button,80,0,true);
            if (chosen.mode<0) continue;
            assert(chosen.width<=chosen.gap.width && chosen.visible<=diskCount);
            if (chosen.visible) {
                double actual=16;
                for (size_t i=0;i<chosen.visible;++i) actual+=sample[chosen.mode][i]+(i?12:0);
                if (chosen.visible<diskCount) actual+=12+button[diskCount-chosen.visible];
                assert(actual==chosen.width);
            }
        }
    }
    Reading snapshot;
    for (size_t i=0;i<8;++i) {
        Reading disk; disk.title=std::to_wstring(i); snapshot.drives.push_back(disk);
    }
    auto hiddenSnapshot=HiddenDriveReading(snapshot,3);
    assert(hiddenSnapshot.drives.size()==5 && hiddenSnapshot.drives.front().title==L"3");
    assert(snapshot.drives.size()==8 && snapshot.drives.front().title==L"0");
    assert(HiddenDriveReading(snapshot,0).drives.size()==8);
    assert(HiddenDriveReading(snapshot,8).drives.empty());
    assert(HiddenDriveReading(snapshot,99).drives.empty());
    Reading info;
    info.title=L"C:"; info.capacity=L"25 / 100 GiB";
    assert(DriveTooltip(info)==L"C: — 25 / 100 GiB");
    Reading usb; usb.title=L"E:"; usb.capacity=L"75 %";
    Reading selected; selected.drives={info,usb};
    assert(DriveTooltip(selected)==L"C: — 25 / 100 GiB\nE: — 75 %");
    selected.drives={usb}; assert(DriveTooltip(selected)==L"E: — 75 %");
    // The rich tooltip uses only the filtered snapshot, including empty groups.
    info.title=L"Windows (C:)"; info.compactTitle=L"(C:)";
    info.hasRatio=true; info.freeRatio=0.25;
    usb.title=L"Backup (E:)"; usb.compactTitle=L"(E:)";
    usb.hasRatio=true; usb.freeRatio=0.75; usb.lowSpace=true;
    selected.drives={info,usb};
    auto tooltipDisks=TooltipDisks(selected,true);
    assert(tooltipDisks.size()==2 && tooltipDisks[0].letter==L"C:" && tooltipDisks[0].name==L"Windows");
    assert(tooltipDisks[0].capacity==L"25 / 100 GiB" && tooltipDisks[0].freeRatio==0.25);
    assert(tooltipDisks[1].capacity==L"75 %" && tooltipDisks[1].lowSpace);
    selected.drives={usb}; assert(TooltipDisks(selected,true).size()==1);
    selected.drives.clear(); assert(TooltipDisks(selected,true).empty());
    assert(TooltipDisks(info,false).size()==1);
    info.title=info.compactTitle; assert(TooltipDisks(info,false)[0].name.empty());
    info.freeRatio=2.0; assert(TooltipDisks(info,false)[0].freeRatio==1.0);
    info.freeRatio=std::numeric_limits<double>::quiet_NaN();
    assert(!TooltipDisks(info,false)[0].hasRatio);
    // Passive cards fit DPI-adjusted monitor bounds without an interactive scroller.
    for (double scale : {1.0,1.25,1.5,2.0}) {
        for (size_t count : {size_t{0},size_t{1},size_t{3},size_t{10},size_t{26}}) {
            const double workWidth=1920.0/scale, workHeight=1032.0/scale;
            const auto card=PassiveTooltipLayout(count,workWidth,workHeight);
            assert(card.columns>=1 && card.rows>=1 && card.visible<=count);
            assert(card.visible<=card.columns*card.rows);
            assert(card.width+30.0<=workWidth-32.0+0.01);
            assert(card.rows*104.0<=workHeight-140.0+0.01);
            if (count<=3) assert(card.columns==1 && card.visible==count);
        }
    }
    auto defaultCard=PassiveTooltipLayout(3,2560,1392);
    assert(defaultCard.width==330 && defaultCard.visible==3);
    auto invalidCard=PassiveTooltipLayout(26,std::numeric_limits<double>::quiet_NaN(),-1);
    assert(invalidCard.visible>0 && std::isfinite(invalidCard.width));
    info.hasRatio=false; info.freeRatio=0.0;
    assert(!TooltipDisks(info,false)[0].hasRatio);
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
