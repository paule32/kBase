program MyTVapp;

uses App, Objects, Menus, Drivers, Views, Consts, Dialogs, MsgBox,
     SysUtils, Editors, Process, dbf, db, dbf_common;

type
  PKListWindow = ^TKListWindow;
  TKListWindow = object (TDialog)
    procedure HandleEvent(var event: TEvent); virtual;
    constructor Init;
  end;

  PNewDBFWindow = ^TNewDBFWindow;
  TNewDBFWindow = object (TDialog)
    procedure HandleEvent(var event: TEvent); virtual;
    constructor Init;
  end;

  PNeuDBFDialog = ^TNeuDBFDialog;
  TNeuDBFDialog = object(TDialog)
    procedure HandleEvent(var event: TEvent); virtual;
    constructor init(r: TRect; t: ShortString);
  end;

  PSubListBox = ^TSubListBox;
  TSubListBox = object(TListBox)
    procedure HandleEvent(var Event: TEvent); virtual;
    constructor Init(var bounds : TRect; anumcols : word; ascrollbar : PScrollBar);
  end;

  PnullStringCollection = ^TnullStringCollection;
  TnullStringCollection = object(TStringCollection)
    constructor init;
  end;

  PDBFStringCollection = ^TDBFStringCollection;
  TDBFStringCollection = object(TStringCollection)
    constructor init;
  end;
  PDBFListViewer = ^TDBFListViewer;
  TDBFListViewer = object(TListViewer)
    procedure HandleEvent(var Event: TEvent); virtual;
    function GetText(item: longint; maxlen: longint): ShortString; virtual;
    constructor init(var ab: TRect; cols: integer; hs,vs: PScrollBar);
  end;

  PProgrammeStringCollection = ^TProgrammeStringCollection;
  TProgrammeStringCollection = object(TStringCollection)
    constructor init;
  end;

  PMyApp = ^TMyApp;
  TMyApp = object(TApplication)
    procedure InitStatusLine; virtual;
    procedure InitMenuBar; virtual;
    procedure HandleEvent(var Event: TEvent); virtual;
    procedure List_It;
    constructor Init;
  end;

var MyApp: TMyApp;
    AProcess: TProcess;

    KListWindow: PKListWindow;
    NewDBFWindow: PNewDBFWindow;
    dwin: PNeuDBFDialog;
    neudbftypeliste: PView;

    feldname: Array [0..9] of PInputLine;
    feldtype: Array [0..9] of PInputLine;
    feldlen : Array [0..9] of PInputLine;
    felddec : Array [0..9] of PInputLine;
    feldidx : Array [0..9] of PCheckBoxes;

    feldzahl: integer;

    DBFDateiInputLine: PInputLine;


    nullListe: PnullStringCollection;
    nullListeControl: PView;

    DBFListe: PDBFStringCollection;
    DBFListeControl: PView;

    ProgrammeListe: PProgrammeStringCollection;
    ProgrammeListeControl: PView;

type
  TMemberInfo = record
    firstname: string[20];
    lastname: string[20];
  end;
var
  memarray : array[0..2] of Tmemberinfo;

procedure doHalt; forward;

procedure TMyApp.InitMenuBar;
var
  R: TRect;
begin
  GetExtent(R);
  R.B.Y := R.A.Y + 1;
  MenuBar := New(PMenuBar, Init(R, NewMenu(
  NewSubMenu('Katalog', hcNoContext, NewMenu(
    NewItem('Katalog Oeffnen', '', kbNoKey, cmKatalog, hcKatalog,
    nil)),
  NewSubMenu('Diverses', hcNoContext, NewMenu(
    NewItem('~T~oggle video', '', kbNoKey, cmOptionenVideo, hcNoContext,
    nil)),
  NewSubMenu('Optionen', hcNoContext, NewMenu(	
    NewItem('~T~oggle video', '', kbNoKey, cmOptionenVideo, hcNoContext,
    nil)),		
  nil))))));
end;

procedure TMyApp.InitStatusLine;
var
  R: TRect;
begin
  GetExtent(R);
  R.A.Y := R.B.Y - 1;
  New(StatusLine, Init(R,
    NewStatusDef(0, $EFFF,
      NewStatusKey('~F1~ Hilfe', kbF1, cmHelp,
      NewStatusKey('~Alt-X~ Beenden', kbAltX, cmQuit,
      StdStatusKeys(nil))),
    NewStatusDef($f000, $FFFF, StdStatusKeys(nil),
    nil))));
end;

procedure TMyApp.HandleEvent(var Event: TEvent);
begin
  if Event.What = evCommand then
  case Event.Command of
    cmQuit: doHalt;
    cmKatalog: List_It;
    cmOptionenVideo:
    begin
      SetScreenMode(smFont8x8);
    end;
  end;

  inherited HandleEvent(Event);
  ClearEvent(Event);
end;

procedure DoInfoBlock;
begin
  MessageBox(
  #3'kBase fuer Linux 1.0'#13#13+
  #3'DEMO Version'#13+#13+
  #3'Copyright 2013-2014'#13+
  #3'Kallup Software',
  nil, mfInformation or mfOkButton);
end;

constructor TMyApp.Init;
begin
  inherited Init;

  DoInfoBlock;
end;

constructor TSubListBox.Init(var bounds : TRect; anumcols : word; ascrollbar : PScrollBar);
begin
  inherited Init(bounds, anumcols, ascrollbar);
end;

procedure TSubListBox.HandleEvent(var event: TEvent);
begin

  DrawView;
(*  focusitem(1);
*)

  inherited HandleEvent(Event);
  clearEvent(event);
end;

procedure TKListWindow.HandleEvent(var event: TEvent);
begin
  if Event.What = evCommand then
  case Event.Command of
    cmNeudbf: 
    begin
      NewDBFWindow := New(PNewDBFWindow, init);
      desktop^.insert(NewDBFWindow);

      DBFListe := new(PDBFStringCollection, init);
      DBFListe^.Insert(NewStr('kkkkk'));
      PSubListBox(DBFListeControl)^.NewList(DBFListe);
      Draw;
    end;
  end;
  inherited HandleEvent(Event);
  clearEvent(Event);
end;

constructor TDBFListViewer.init(var ab: TRect; cols: integer; hs,vs: PScrollBar);
begin
  inherited init(ab,cols,hs,vs);
  //inherited init(ab,cols,vs);
end;

procedure TDBFListViewer.HandleEvent(var Event: TEvent);
begin
  Draw;
  inherited HandleEvent(Event);
  clearEvent(Event);
end;

function TDBFListViewer.GetText(item: longint; maxlen: longint): ShortString;
begin
  memarray[0].firstname := 'Zeichen';
  memarray[1].firstname := 'Zö';
  memarray[2].firstname := 'chen';

  with memarray[item] do
  begin
  messagebox(firstname,nil,0);
  GetText := Copy(firstname,1,maxlen);
  end;
end;

procedure TNeuDBFDialog.HandleEvent(var event: TEvent);
begin
  if Event.What = evCommand then
  begin
    case Event.Command of
      cmAbbrechenDBFtype:
      begin
        Dispose(dwin, done);
      end;
      cmokdbftype:
      begin
        if PRadioButtons(neudbftypeliste)^.Mark(0) then
        begin
          feldtype[feldzahl]^.Data := newstr('Zeichen');
          feldname[feldzahl]^.Data^ := 'feld' + inttostr(feldzahl);
          feldlen [feldzahl]^.Data^ := '20';
          felddec [feldzahl]^.Data^ := '0']
        end;
        if PRadioButtons(neudbftypeliste)^.Mark(1) then
        begin
          feldtype[feldzahl]^.Data := newstr('Numerisch');
          feldname[feldzahl]^.Data^ := 'feld'+inttostr(feldzahl);
          feldlen [feldzahl]^.Data^ := '10'; 
          felddec [feldzahl]^.Data^ := '0']
        end;
        if PRadioButtons(neudbftypeliste)^.Mark(2) then
        begin
          feldtype[feldzahl]^.Data := newstr('Boolean');
          feldname[feldzahl]^.Data^ := 'feld' + inttostr(feldzahl);
          feldlen [feldzahl]^.Data^ := '1';
          felddec [feldzahl]^.Data^ := '0']
        end;
        if PRadioButtons(neudbftypeliste)^.Mark(3) then
        begin
          feldtype[feldzahl]^.Data := newstr('Memo');
          feldname[feldzahl]^.Data^ := 'feld' + inttostr(feldzahl);
        end;
        Dispose(dwin, done);
      end;
    end;
  end;
  inherited HandleEvent(Event);
  clearEvent(Event);
end;

constructor TNeuDBFDialog.init(r: TRect; t: ShortString);
begin
  inherited init(r,t);
end;

procedure TNewDBFWindow.HandleEvent(var event: TEvent);
var
  r: TRect;
  i: integer;
  f1,f2: ShortString;
  mydbf: TDBF;
begin
  if Event.What = evCommand then
  case Event.Command of
    cmCloseNewDBFfile:
    begin
      Dispose(NewDBFWindow, Done);
    end;

    cmSaveNewDBFfile:
    begin
      mydbf := Tdbf.create(nil);
      mydbf.TableLevel := 7;
      mydbf.Exclusive := true;
      mydbf.TableName := 'neu.dbf';

      // tabellenfelder check ...
      for i := 0 to 1 do
      begin
        f1 := feldtype[i]^.Data^;
        f2 := feldname[i]^.Data^;

        if (length(trim(f1)) > 0) and (length(trim(f2)) > 0) then
        begin
          with mydbf.FieldDefs do
          begin
            if f2 = 'Zeichen'   then Add(f2, ftString, 25, true);
            if f2 = 'Numerisch' then Add(f2, ftNumeric, 25, true);
          end;
        end;
      end;

      mydbf.CreateTable;
      mydbf.Free;
    end;
    300..310:
    begin
      R.Assign(10,10,40,20);
      dwin := new(PNeuDBFDialog, init(r,'Auswahl'));
      desktop^.insert(dwin);

      R.Assign(2,2,24,6);
      neudbftypeliste := new(PRadioButtons, init(R,
        NewSItem('Zeichen',
        NewSItem('Numerisch',
        NewSItem('Boolean',
        NewSItem('Memo',
      nil))))));
      dwin^.insert(neudbftypeliste);

      if Event.Command = 300 then feldzahl := 0;
      if Event.Command = 301 then feldzahl := 1;
      if Event.Command = 302 then feldzahl := 2;
      if Event.Command = 303 then feldzahl := 3;
      if Event.Command = 304 then feldzahl := 4;
      if Event.Command = 305 then feldzahl := 5;
      if Event.Command = 306 then feldzahl := 6;
      if Event.Command = 307 then feldzahl := 7;
      if Event.Command = 308 then feldzahl := 8;
      if Event.Command = 309 then feldzahl := 9;

      R.Assign(5 ,7,10,9); dwin^.insert(new(PButton, init(R,'Ok'       ,cmOkDBFtype, bfNormal)));
      R.Assign(14,7,26,9); dwin^.insert(new(PButton, init(R,'Abbrechen',cmAbbrechenDBFtype, bfNormal)));
    end;
  end;
  inherited HandleEvent(Event);
  clearEvent(Event);
end;

constructor TNewDBFWindow.Init;
var
  R: TRect;
  i: word;
  s: string;
begin
  R.Assign(0,0,65,20);
  inherited init(R,'Neue DBF-Datei anlegen');
  Options := Options or ofCentered;

  s := '';
  for i := 1 to 60 do s := s + chr(196);
  R.Assign(1,3,61,4);
  insert(new(PLabel, init(R,s,nil)));

  R.Assign(1,2,57,3);
  insert(new(PLabel, init(R,
  ' Pos '        + chr(186) +
  ' Feldname   ' + chr(186) +
  ' Feldtyp    ' + chr(186) +
  ' L"ange '     + chr(186) +
  ' Dez '        + chr(186) +
  ' Index ',
  nil)));

  R.Assign(3,4,5,5); insert(new(PLabel,init(R,'1',nil)));
  R.Assign(3,5,5,6); insert(new(PLabel,init(R,'2',nil)));
  R.Assign(3,6,5,7); insert(new(PLabel,init(R,'3',nil)));
  R.Assign(3,7,5,8); insert(new(PLabel,init(R,'4',nil)));
  R.Assign(3,8,5,9); insert(new(PLabel,init(R,'6',nil)));
  R.Assign(3,9,5,10); insert(new(PLabel,init(R,'7',nil)));
  R.Assign(3,10,5,11); insert(new(PLabel,init(R,'8',nil)));
  R.Assign(3,11,5,12); insert(new(PLabel,init(R,'9',nil)));
  R.Assign(3,12,6,13); insert(new(PLabel,init(R,'10',nil)));

  for i := 1 to 9 do
  begin
    R.Assign(8,3+i,20,4+i);
    feldname[i] := new(PInputLine, init(R,15));
    insert(feldname[i]);

    R.Assign(21,3+i,32,4+i);
    feldtype[i] := new(PInputLine, init(R,15));
    insert(feldtype[i]);
    R.Assign(32,3+i,34,4+i);
    insert(new(PButton, init(r,'V',cmListDBFtype+i, bfNormal)));

    R.Assign(35,3+i,41,4+i);
    feldlen[i] := new(PInputLine, init(R,3));
    insert(feldlen[i]);

    R.Assign(43,3+i,49,4+i);
    felddec[i] := new(PInputLine, init(R,3));
    insert(felddec[i]);

    R.Assign(51,3+i,56,4+i);
    feldidx[i] := new(PCheckBoxes, init(R,
      NewSItem('j/n',nil)));
    insert(feldidx[i]);
  end;

  R.Assign(1,15,20,16);
  insert(new(PLabel, init(R,
  'Dateinane:', nil
  )));

  R.Assign(13,15,41,16);
  DBFDateiInputLine := new(PInputLine,init(R,200));
  insert(DBFDateiInputLine);
  DBFDateiInputLine^.Data^ := 'neu.dbf';

  R.Assign(13,17,28,19);
  insert(new(PButton, init(r,'speichern',cmSaveNewDBFfile, bfNormal)));
  R.Assign(36,17,49,19);
  insert(new(PButton, init(r,'Abbrechen',cmCloseNewDBFfile, bfNormal)));
end;

constructor TKListWindow.Init;
var
  R: TRect;
  ScrollBar1: PScrollBar;
  ScrollBar2: PScrollBar;
  ScrollBar3: PScrollBar;
  ScrollBar4: PScrollBar;
  ScrollBar5: PScrollBar;
begin
  R.Assign(0,0,65,15);
  inherited init(R,'Katalog: ');

  Options := Options or ofCentered;

  { neu dbf}
  R.Assign(13,5,14,11);
  ScrollBar1 := new(PScrollBar, init(r));
  insert(ScrollBar1);
  R.Assign(3,2,13,4);
  Insert(new(PButton, init(r,'<neu>',cmNeuDbf, bfDefault)));
  R.Assign(3,5,13,11);
  DBFListeControl := new(PSubListBox, Init(R, 1, scrollbar1));
  Insert(DBFListeControl);
  DBFListe := new(PDBFStringCollection, init);
  PSubListBox(DBFListeControl)^.NewList(DBFListe);
  R.Assign(2,3,13,4);
  insert(new(PLabel, init(R,'dB-Dateien',nil)));

  { neu Abfragen}
  R.Assign(25,5,26,11);
  ScrollBar2 := new(PScrollBar, init(r));
  insert(ScrollBar2);
  R.Assign(15,2,25,4);
  Insert(new(PButton, init(r,'<neu>',cmNeuDbf, bfDefault)));
  R.Assign(15,5,25,11);
  nullListeControl := new(PSubListBox, Init(R, 1, scrollbar2));
  Insert(nullListeControl);
  nullListe := new(PnullStringCollection, init);
  PSubListBox(nullListeControl)^.NewList(nullListe);
  R.Assign(16,3,25,4);
  insert(new(PLabel, init(R,'Abfragen',nil)));

  { Masken }
  R.Assign(37,5,38,11);
  ScrollBar3 := new(PScrollBar, init(r));
  insert(ScrollBar3);
  R.Assign(27,2,37,4);
  Insert(new(PButton, init(r,'<neu>',cmNeuDbf, bfDefault)));
  R.Assign(27,5,37,11);
  nullListeControl := new(PSubListBox, Init(R, 1, scrollbar3));
  Insert(nullListeControl);
  nullListe := new(PnullStringCollection, init);
  PSubListBox(nullListeControl)^.NewList(nullListe);
  R.Assign(27,3,37,4);
  insert(new(PLabel, init(R,' Masken',nil)));

  { Berichte }
  R.Assign(49,5,50,11);
  ScrollBar4 := new(PScrollBar, init(r));
  insert(ScrollBar4);
  R.Assign(39,2,49,4);
  Insert(new(PButton, init(r,'<neu>',cmNeuDbf, bfDefault)));
  R.Assign(39,5,49,11);
  nullListeControl := new(PSubListBox, Init(R, 1, scrollbar4));
  Insert(nullListeControl);
  nullListe := new(PnullStringCollection, init);
  PSubListBox(nullListeControl)^.NewList(nullListe);
  R.Assign(39,3,49,4);
  insert(new(PLabel, init(R,'Berichte',nil)));

  { Programme }
  R.Assign(61,5,62,11);
  ScrollBar5 := new(PScrollBar, init(r));
  insert(ScrollBar5);
  R.Assign(51,2,61,4);
  Insert(new(PButton, init(r,'<neu>',cmNeuDbf, bfNormal)));
  R.Assign(51,5,61,11);
  ProgrammeListeControl := new(PSubListBox, Init(R, 1, scrollbar5));
  Insert(ProgrammeListeControl);
  ProgrammeListe := new(PProgrammeStringCollection, init);
  PSubListBox(ProgrammeListeControl)^.NewList(ProgrammeListe);
  R.Assign(51,3,61,4);
  insert(new(PLabel, init(R,'Programme',nil)));
end;

constructor TnullStringCollection.init;
begin
  inherited init(20,4);
  Insert(NewStr('Anchorage'));
end;

constructor TProgrammeStringCollection.init;
begin
  inherited init(20,4);
  Insert(NewStr('Anchorage'));
  Insert(NewStr('Juneau'));
end;

constructor TDBFStringCollection.init;
begin
  inherited init(20,4);
  Insert(NewStr('Anchorage'));
  Insert(NewStr('Atlanta'));
  Insert(NewStr('Baltimore'));
  Insert(NewStr('Boston'));
end;

procedure TMyApp.List_It;
begin
  KListWindow := New(PKListWindow, init);
  insertwindow(KListWindow);
end;

procedure doHalt;
begin
  AProcess := TProcess.Create(nil);
  AProcess.CommandLine := 'reset';
  AProcess.Execute;
  AProcess.free;
end;

begin
  MyApp.Init;
  MyApp.Run;
  MyApp.Done;
  doHalt;
end.
