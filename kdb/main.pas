unit main;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, Menus,
  ComCtrls, Buttons, PairSplitter, ExtCtrls, StdCtrls, Grids, EditBtn, Spin,
  ToolWin, ImgList, IniFiles, contnrs, dbf,
  IdBaseComponent, IdComponent, IdTCPServer, IdThreadMgr, IdThreadMgrDefault,
  Interfaces,
  LResources;

type
  TSimpleClient = class(TObject)
    DNS,
    Name        : String;
    SQLfile     : String;
    Password    : String;
    command     : String;
    ListLink    : Integer;
    Thread      : Pointer;
  end;

  TDataBasesList = class(TObject)
    Name         : String;
    dbDriver     : String;
    dbPath       : String;
  end;

  TUserPassword = class(TObject)
    user : String;
    pass : String;
  end;

  { TForm1 }

  TForm1 = class(TForm)
    DrawGrid1: TDrawGrid;
    lbClients: TListBox;
    MainMenu1: TMainMenu;
    Memo1: TMemo;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    MenuItem3: TMenuItem;
    MenuItem4: TMenuItem;
    MenuItem5: TMenuItem;
    MenuItem6: TMenuItem;
    MenuItem7: TMenuItem;
    PageControl1: TPageControl;
    PageControl2: TPageControl;
    Panel1: TPanel;
    Panel2: TPanel;
    Panel3: TPanel;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    SpeedButton3: TSpeedButton;
    SpeedButton4: TSpeedButton;
    Splitter1: TSplitter;
    Splitter2: TSplitter;
    StaticText1: TStaticText;
    StaticText2: TStaticText;
    StatusBar1: TStatusBar;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    TabSheet3: TTabSheet;
    ToolBar1: TToolBar;
    TreeView1: TTreeView;
    procedure Button1Click(Sender: TObject);
    procedure CheckBox1Change(Sender: TObject);
    procedure CheckBox1Enter(Sender: TObject);
    procedure ComboBox1Enter(Sender: TObject);
    procedure DirectoryEdit1AcceptDirectory(Sender: TObject; var Value: String);
    procedure DrawGrid1Click(Sender: TObject);
    procedure DrawGrid1DrawCell(Sender: TObject; aCol, aRow: Integer;
      aRect: TRect; aState: TGridDrawState);
    procedure FormClose(Sender: TObject; var CloseAction: TCloseAction);
    procedure FormCreate(Sender: TObject);
    procedure FormResize(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure MenuItem1Click(Sender: TObject);
    procedure MenuItem2Click(Sender: TObject);
    procedure MenuItem6Click(Sender: TObject);
    procedure SpeedButton4Click(Sender: TObject);
    procedure SpinEdit1Enter(Sender: TObject);
    procedure TreeView1AdvancedCustomDrawItem(Sender: TCustomTreeView;
      Node: TTreeNode; State: TCustomDrawState; Stage: TCustomDrawStage;
      var PaintImages, DefaultDraw: Boolean);
    procedure TreeView1Change(Sender: TObject; Node: TTreeNode);
    procedure TreeView1Click(Sender: TObject);
    procedure TreeView1Enter(Sender: TObject);
    procedure TreeView1GetSelectedIndex(Sender: TObject; Node: TTreeNode);
    procedure TreeView1SelectionChanged(Sender: TObject);
  private
    tcpServer : TIdTCPServer;
    IdThreadMgrDefault1: TIdThreadMgrDefault;

    actualNodeText: String;
    currentUsers: Integer;

    dbTypeText : String;
    PathEditorDirText: String;

    ListDriver: TComboBox;
    BCDChekBox: TCheckBox;
    PortEditor: TSpinEdit;
    PathEditor: TDirectoryEdit;
    Button: TButton;

    procedure tcpServerConnect(AThread: TIdPeerThread);
    procedure tcpServerExecute(AThread: TIdPeerThread);
    procedure tcpServerDisconnect(AThread: TIdPeerThread);

    procedure createDatabase(dbname: String);
    procedure getSettings;
  public
    Clients: TList;
    procedure UpdateBindings;
    procedure UpdateClientList;
  end;

var
  Form1: TForm1;
  DatabaseListe: TObjectList;
  MyUserList: Array of TUserPassword;

var
  Line : Integer;

implementation
uses
  IdSocketHandle;  // This is where the IdSocketHandle class is defined.

{$R *.lfm}

{ TForm1 }

procedure TForm1.UpdateBindings;
var
  Binding : TIdSocketHandle;
  vPort : Integer;
begin
  if PortEditor = nil then
  vPort := 1979 else
  vPort := PortEditor.Value;
  tcpServer.DefaultPort := vPort;
end;

procedure TForm1.MenuItem1Click(Sender: TObject);
begin

end;

procedure TForm1.DrawGrid1Click(Sender: TObject);
begin

end;

procedure TForm1.DirectoryEdit1AcceptDirectory(Sender: TObject;
  var Value: String);
begin
  PathEditor.SetFocus;
  PathEditor.Text := Value;
  PathEditorDirText := Value;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  StatusBar1.Panels[0].Text := 'User Access List';
end;

procedure TForm1.CheckBox1Change(Sender: TObject);
begin

end;

procedure TForm1.CheckBox1Enter(Sender: TObject);
begin
  StatusBar1.Panels[0].Text := 'Enable BCD for Numeric/Decimal fields';
end;

procedure TForm1.ComboBox1Enter(Sender: TObject);
begin
  StatusBar1.Panels[0].Text := 'Driever tried first';
end;

procedure TForm1.DrawGrid1DrawCell(Sender: TObject; aCol, aRow: Integer;
  aRect: TRect; aState: TGridDrawState);
var
  R: TRect;
begin
  if (aCol = 0) and (aRow = 0) then
  begin
    with DrawGrid1 do begin
      Canvas.Font.Bold := true;
      Canvas.FillRect(aRect);
      Canvas.TextOut(aRect.Left + 5, aRect.Top + 2,'Typ ');
      if gdFocused in aState then
      Canvas.DrawFocusRect(aRect);
    end;
  end;

  if (aCol = 1) and (aRow = 0) then
  begin
    with DrawGrid1 do begin
      Canvas.FillRect(aRect);
      Canvas.TextOut(aRect.Left + 5, aRect.Top + 2,dbTypeText);
      if gdFocused in aState then
      Canvas.DrawFocusRect(aRect);
    end;
    if gdFocused in aState then
    StatusBar1.Panels[0].Text := 'Datenbanktyp';
  end;

  if (aCol = 0) and (aRow = 1) then
  begin
    with DrawGrid1 do begin
      Canvas.Font.Bold := true;
      Canvas.FillRect(aRect);
      Canvas.TextOut(aRect.Left + 5, aRect.Top + 2,
      'DEFAULT DRIVER ');
      if gdFocused in aState then
      Canvas.DrawFocusRect(aRect);
    end;
  end;

  if (aCol = 0) and (aRow = 2) then
  begin
    with DrawGrid1 do begin
      Canvas.Font.Bold := true;
      Canvas.FillRect(aRect);
      Canvas.TextOut(aRect.Left + 5, aRect.Top + 2,
      'ENABLE BCD ');
      if gdFocused in aState then
      Canvas.DrawFocusRect(aRect);
    end;
  end;

  if (aCol = 0) and (aRow = 3) then
  begin
    with DrawGrid1 do begin
      Canvas.Font.Bold := true;
      Canvas.FillRect(aRect);
      Canvas.TextOut(aRect.Left + 5, aRect.Top + 2,
      'PATH');
      if gdFocused in aState then
      Canvas.DrawFocusRect(aRect);
    end;
  end;

  if (aCol = 0) and (aRow = 4) then
  begin
    with DrawGrid1 do begin
      Canvas.Font.Bold := true;
      Canvas.FillRect(aRect);
      Canvas.TextOut(aRect.Left + 5, aRect.Top + 2,
      'PORT');
      if gdFocused in aState then
      Canvas.DrawFocusRect(aRect);
    end;
  end;

  if (aCol = 0) and (aRow = 5) then
  begin
    with DrawGrid1 do begin
      Canvas.Font.Bold := true;
      Canvas.FillRect(aRect);
      Canvas.TextOut(aRect.Left + 5, aRect.Top + 2,
      'USERLIST');

      if gdFocused in aState then
      Canvas.DrawFocusRect(aRect);
    end;
  end;


  R := DrawGrid1.CellRect(aCol, aRow);
  Inc(R.Right, DrawGrid1.GridLineWidth);
  Inc(R.Bottom, DrawGrid1.GridLineWidth);

  // list drivers
  if (aCol = 1) and (aRow = 1) then
  begin
    with DrawGrid1 do begin
      if ListDriver = nil then
      begin
        ListDriver := TComboBox.Create(DrawGrid1);
        ListDriver.Items.Add('PARADOX');
        ListDriver.Items.Add('DBASE');
        ListDriver.Items.Add('FOXPRO');
        ListDriver.Items.Add('ASCIIDRV');
      end;
      ListDriver.onEnter := @ComboBox1Enter;
      ListDriver.ReadOnly := true;
      ListDriver.BoundsRect := R;
      ListDriver.Parent := DrawGrid1;
      ListDriver.Visible := true;
    end;
    if gdFocused in aState then
    StatusBar1.Panels[0].Text := 'Driever tried first';
  end;

  // bcd
  if (aCol = 1) and (aRow = 2) then
  begin
    with DrawGrid1 do begin
      if BCDChekBox = nil then
      BCDChekBox := TCheckBox.Create(DrawGrid1);
      BCDChekBox.onEnter := @CheckBox1Enter;
      BCDChekBox.Checked := false;
      BCDChekBox.BoundsRect := R;
      BCDChekBox.Parent := DrawGrid1;
      BCDChekBox.Visible := true;
    end;
    if gdFocused in aState then
    StatusBar1.Panels[0].Text := 'Enable BCD for Numeric/Decimal fields';
  end;

  // path ...
  if (aCol = 1) and (aRow = 3) then
  begin
    with DrawGrid1 do begin
      if PathEditor = nil then
      PathEditor := TDirectoryEdit.Create(DrawGrid1);
      PathEditor.OnAcceptDirectory := @DirectoryEdit1AcceptDirectory;
      PathEditor.Directory := PathEditorDirText;
      PathEditor.BoundsRect := R;
      PathEditor.Parent := DrawGrid1;
      PathEditor.Visible := true;
    end;
    if gdFocused in aState then
    StatusBar1.Panels[0].Text := 'Database Location';
  end;

  // port
  if (aCol = 1) and (aRow = 4) then
  begin
    with DrawGrid1 do begin
      if PortEditor = nil then
      PortEditor := TSpinEdit.Create(DrawGrid1);
      PortEditor.onEnter := @SpinEdit1Enter;
      PortEditor.BoundsRect := R;
      PortEditor.MaxValue := 65535;
      PortEditor.MinValue := 1;
      PortEditor.Value := 1979;
      PortEditor.Parent := DrawGrid1;
      PortEditor.Visible := true;
    end;
    if gdFocused in aState then
    StatusBar1.Panels[0].Text := 'Port number for server';
  end;

  // user liste
  if (aCol = 1) and (aRow = 5) then
  begin
    with DrawGrid1 do begin
      if Button = nil then
      Button := TButton.Create(DrawGrid1);
      Button.onEnter := @Button1Click;
      Button.BoundsRect := R;
      Button.Caption := 'Ändern';
      Button.Parent := DrawGrid1;
      Button.Visible := true;
    end;
    if gdFocused in aState then
    StatusBar1.Panels[0].Text := 'User Access List';
  end;
end;

procedure TForm1.FormClose(Sender: TObject; var CloseAction: TCloseAction);
begin
  try
    if (Clients.Count > 0) and (tcpServer.Active) then
    begin
      CloseAction := caNone;
      ShowMessage('Can''t close CBServ while server is online.');
    end else
    Clients.Free;
  except
    Close;
  end;
end;



procedure TForm1.createDatabase(dbname: String);
var
  ini: TIniFile;
  filename: String;
begin
  try
    filename := ExtractFilePath(ParamStr(0)) + 'kdb.ini';
    ini := TIniFile.Create(filename);
    ini.WriteString('Databases', dbname, dbname);
    ini.WriteString(dbname,'port','1979');
    ini.WriteString(dbname,'path','c:/Projekte');
    ini.WriteString(dbname,'driver','dbase');
    ini.WriteString(dbname,'bcd','false');

    getSettings;
  finally
    ini.Free;
  end;
end;

procedure TForm1.getSettings;
var
  ini: TIniFile;
  filename: String;
  tmpliste: TStringList;
  strliste: TStringList;
  datastr: String;
  i, dataint: Integer;
  nd: TTreeNode;
begin
  try
    filename := ExtractFilePath(ParamStr(0)) + 'kdb.ini';
    ini := TIniFile.Create(filename);
    tmpliste := TStringList.Create;
    strliste := TStringList.Create;
    ini.ReadSection('Databases', tmpliste);

    for i := 0 to tmpliste.count - 1 do
    strliste.Add(tmpliste[i]);
    TreeView1.Items.Clear;

    nd := TreeView1.TopItem;
    nd := TreeView1.Items.AddChild(nd,'Datenbanken');

    for i := 0 to strliste.Count - 1 do
    TreeView1.Items.AddChild(nd,strliste[i]);
    nd.Expand(true);

    for i := 0 to strliste.Count - 1 do
    begin
      if strliste[i] = actualNodeText then
      begin
        datastr := ini.ReadString (strliste[i],'bcd','false');
        if datastr = 'false' then
        BCDChekBox.Checked := false else
        BCDChekBox.Checked := true;

        datastr := ini.ReadString (strliste[i],'driver','DBASE');
        ListDriver.Text := datastr;

        dataint := ini.ReadInteger(strliste[i],'port',1979);
        PortEditor.Value := dataint;

        PathEditorDirText := ini.ReadString(strliste[i],'path','C:\');
        PathEditor.Directory := PathEditorDirText;

        break;
      end;
    end;
  except
    ShowMessage('Fehler: INI Datei fehlerhaft.');
  end;
  FreeAndNil(tmpliste);
  FreeAndNil(ini);
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  tcpServer:=TIdTCPServer.create(self);
  IdThreadMgrDefault1 := TIdThreadMgrDefault.create(self);
  tcpserver.threadmgr := idthreadmgrdefault1;
  tcpserver.OnConnect := @tcpServerConnect;
  tcpserver.OnExecute := @tcpServerExecute;
  tcpserver.OnDisconnect := @tcpServerDisconnect;
  tcpserver.defaultport := 1979;

  Clients := TList.Create;

  dbTypeText := 'STANDARD';
  PathEditorDirText := 'C:\';

  currentUsers := 0;
end;

procedure TForm1.tcpServerConnect(AThread: TIdPeerThread);
var
  Client : TSimpleClient;
begin
{ Send a welcome message, and prompt for the users name }
  AThread.Connection.WriteLn('ISD Connection Established...');
  AThread.Connection.WriteLn('Please send valid login sequence...');
  AThread.Connection.WriteLn('User Name:');
  AThread.Connection.WriteLn('Password:');
{ Create a client object }
  Client := TSimpleClient.Create;
{ Assign its default values }
  Client.DNS  := AThread.Connection.LocalName;
  Client.Name := '@Guest_'+TimeToStr(Now);
  Client.ListLink := lbClients.Items.Count;
{ Assign the thread to it for ease in finding }
  Client.Thread := AThread;
{ Add to our clients list box }
  lbClients.Items.Add(Client.Name);
{ Assign it to the thread so we can identify it later }
  AThread.Data := Client;
  Clients.Add(Client);
end;


procedure Error(aThread: TIdPeerThread; ErrorText : String);
begin
  Form1.Memo1.Lines.Add(Format('%d: ' + ErrorText, [Line]));
  AThread.Connection.Disconnect;
end;

procedure TForm1.tcpServerExecute(AThread: TIdPeerThread);
var
  Client : TSimpleClient;
  Msg    : String;
  str    : String;
  flag   : Boolean;

var
  ID: String;
  Ch : Char;
  Line, pos,i: Integer;
  InFile : TextFile;


  procedure GetSymbol(filename: String);
    procedure GetCh;
    begin
      repeat
        Read(InFile,ch);

        if ch = '*' then
        begin
          id := '@:star:@';
          break;
        end else

        if (ch = chr(10)) then inc(Line) else
        if (ch = chr(9) )
        or (ch = chr(32)) then
        begin
          if Length(id) > 1 then
          begin
            break;
          end;
        end else
        id := id + UpperCase(ch);
        inc(pos);
      until pos >= FileSize(filename);
    end;

    function GetIdent: String;
    begin
      id := '';
      result := ''; GetCh;
      result := Trim(id);
    end;

  begin
    pos := 0;
    id := GetIdent;
    if id = 'CREATE' then
    begin
      id := GetIdent;
      if id = 'DATABASE' then
      begin
        id := GetIdent;
        createDatabase(id);
        athread.connection.WriteLn('@sqlnoerror');
      end;
    end else if id = 'SELECT' then
    begin
      id := GetIdent;
      if id = '@:star:@' then
      begin
        id := GetIdent;
        if id = 'FROM' then
        begin
          id := GetIdent;
          //Client.dbfTable
        end;
      end;
    end;
  end;

  procedure parse_sql(str:String; sclient: TSimpleClient);
  var
  tfs: TFileStream;
  fns: String;
  begin
    Client.SQLfile := Client.Name + TimeToStr(Now);
    Client.SQLfile := StringReplace(Client.SQLfile,'.','',[rfReplaceAll]);
    Client.SQLfile := StringReplace(Client.SQLFile,':','',[rfReplaceAll]);

    str := StringReplace(str,chr(10),' ',[rfReplaceAll]);

    tfs := TFileStream.Create(Client.SQLFile,fmCreate);
    tfs.Write(str[1],Length(str));
    tfs.Free;

    AssignFile(InFile, Client.SQLfile);
    Reset(InFile);

    Memo1.Lines.Add(UpperCase(str));

    Ch := ' ';
    Line := 1;
    GetSymbol(Client.SQLfile);
    Memo1.lines.add(client.name + ' unbekannt');


    Memo1.Lines.Add(Client.Name + ' sql DONE.');
    CloseFile(InFile);
  end;

var
  login_ok: Boolean = false;
  user,pass: String;
begin
  Client := TSimpleClient(AThread.Data);
  flag   := false;

  repeat
    user := AThread.Connection.ReadLn;
    pass := AThread.Connection.ReadLn;

    for i := 0 to currentUsers do
    begin
      if  (MyUserList[i].user = user)
      and (MyUserList[i].pass = pass)
      and (Length(Trim(user)) > 0)
      and (Length(Trim(pass)) > 0) then
      begin
        login_ok := true;
        break;
      end;
    end;

    if login_ok = false then
    begin
      Memo1.Lines.Add(DateTimeToStr(Now) +
      ' Error: ' + user + ' invalid login.');
      aThread.Connection.Writeln('@loginerror');
      aThread.Connection.Disconnect;
      exit;
    end;

    if login_ok = true then
    begin
      login_ok := true;
      for i := 0 to lbClients.Count - 1 do
      begin
        if lbClients.Items[i] = user then
        begin
          Memo1.Lines.Add(DateTimeToStr(Now) + ' Error: ' + user + ' already login.');
          athread.Connection.WriteLn('@loginerror');
          athread.Connection.Disconnect;
          login_ok := false;
          break;
        end;
      end;

      if login_ok = true then
      begin
        Client.Name := Msg;
        UpdateClientList;
        Memo1.Lines.Add(DateTimeToStr(Now) + ' ' + user + ' has just logged in.');
        lbClients.Items.Delete(lbClients.Items.IndexOf(Client.Name));
        Client.Name := user;
        lbClients.Items.Add(user);
        flag := true;
      end;
    end;
  until flag = true;

  repeat
    Msg := AThread.Connection.ReadLn;
    if Msg = '@sqlbegin' then
    begin
      str := '';
      repeat
        msg := AThread.Connection.ReadLn;
        if msg = '@sqlend' then break;
        str := str + #10 + msg;
        Memo1.Lines.Add(msg);
      until msg = '@sqlend';

      if msg = '@sqlend' then
      parse_sql(str,Client);
    end else if msg = '@exit' then
    begin
      AThread.Connection.Disconnect;
      break;
    end;
  until msg = '@exit';
end;


procedure TForm1.tcpServerDisconnect(AThread: TIdPeerThread);
var
  Client : TSimpleClient;
begin
{ Retrieve Client Record from Data pointer }
  Client := TSimpleClient(AThread.Data);
{ Remove Client from the Clients TList }
  Clients.Delete(Client.ListLink);
{ Remove Client from the Clients List Box }
  lbClients.Items.Delete(lbClients.Items.IndexOf(Client.Name));
  Memo1.Lines.Add(DateTimeToStr(Now) + ' ' + Client.Name + ' has left.');
{ Free the Client object }
  Client.Free;
  AThread.Data := nil;

end;

procedure TForm1.UpdateClientList;
var
  Count : Integer;
begin
{ Loop through all the clients connected to the system and set their names }
  for Count := 0 to lbClients.Items.Count -1 do
    if Count < Clients.Count then
      lbClients.Items.Strings[Count] := TSimpleClient(Clients.Items[Count]).Name;
end;

procedure TForm1.FormResize(Sender: TObject);
begin
  DrawGrid1.DefaultColWidth := (DrawGrid1.Width div 2) - 10;
end;

procedure TForm1.FormShow(Sender: TObject);
var
  InFile: TextFile;
  p: Integer;
  str,
  user,pass: String;
begin
  DrawGrid1.DefaultColWidth := (DrawGrid1.Width div 2) - 10;

  try
    if Length(MyUserList) > 0 then
    exit;

    AssignFile(InFile, ExtractFilePath(ParamStr(0)) + '\passwords');
    Reset(InFile);

    SetLength(MyUserList,32);
    p := 0;
    repeat
      ReadLn(InFile,str);
      if Length(str) > 1 then
      begin
        user := Copy(str,1,Pos(':',str)-1);
        pass := Copy(str,Pos(':',str)+1,Length(str));

        MyUserList[p] := TUserPassword.Create;
        MyUserList[p].user := user;
        MyUserList[p].pass := pass;

        inc(p);
        if p >= 32 then
        break;
      end;
    until Eof(InFile) = true;

    currentUsers := p-1;
    CloseFile(InFile)
  except
    ShowMessage('Password fule error');
  end;
end;

procedure TForm1.MenuItem2Click(Sender: TObject);
begin
  TreeView1.Items.AddChild(TreeView1.TopItem,'Neue Datenbank');
end;

procedure TForm1.MenuItem6Click(Sender: TObject);
begin
  Close;
end;

procedure TForm1.SpeedButton4Click(Sender: TObject);
begin
  try
    UpdateBindings;
    tcpServer.Active := not tcpServer.Active;
    if SpeedButton4.Caption = 'Start Server' then
    begin
      SpeedButton4.Caption := 'Stop Server';
      Memo1.Lines.Add(DateTimeToStr(Now) + ' server start...');
    end else
    begin
      SpeedButton4.Caption := 'Start Server';
      Memo1.Lines.Add(DateTimeToStr(Now) + ' server stop');
    end;
  except
  end;
end;

procedure TForm1.SpinEdit1Enter(Sender: TObject);
begin
  StatusBar1.Panels[0].Text := 'Port number for server';
end;

procedure TForm1.TreeView1AdvancedCustomDrawItem(Sender: TCustomTreeView;
  Node: TTreeNode; State: TCustomDrawState; Stage: TCustomDrawStage;
  var PaintImages, DefaultDraw: Boolean);
  var
     Rec: TRect;
     Style: TTextStyle;
begin

    PaintImages := True;
    FillChar(Style, SizeOf(TTextStyle), 0);
    Style.Opaque := True;

    case node.Level of
      0:
      begin
        TCustomTreeView(Sender).canvas.Font.Color := $000000F0; //clRed;
        TCustomTreeView(Sender).canvas.Font.Style := [fsbold];
      end;
      1:
      begin
        if (cdsSelected in State)
        or (cdsFocused in State) then
        TCustomTreeView(Sender).canvas.Font.Style := [fsBold] else
        TCustomTreeView(Sender).canvas.Font.Style := [];
        TCustomTreeView(Sender).canvas.Font.Color := clblack;
        end;
    end;
    Rec := Node.DisplayRect(True);
    rec.Right:=rec.right-1;
    rec.Bottom:=rec.bottom-1;
    if node.selected = true then
    begin
         TCustomTreeView(Sender).canvas.Brush.Color:=clGradientActiveCaption; //clBlue;
         TCustomTreeView(Sender).canvas.Font.Color:=clWhite;
         TCustomTreeView(Sender).canvas.TextRect(Rec, Rec.Left+2, Rec.Top+1, Node.Text, Style);
    end else begin
        TCustomTreeView(Sender).canvas.TextRect(Rec, Rec.Left+2, Rec.Top+1, Node.Text, Style);
    end;
end;

procedure TForm1.TreeView1Change(Sender: TObject; Node: TTreeNode);
begin

end;

procedure TForm1.TreeView1Click(Sender: TObject);
begin
  TreeView1.Items[0].expand(true);
  getSettings;
end;

procedure TForm1.TreeView1Enter(Sender: TObject);
begin
  TreeView1Click(Sender);
end;

procedure TForm1.TreeView1GetSelectedIndex(Sender: TObject; Node: TTreeNode);
begin
  ShowMessage(node.Text);
end;

procedure TForm1.TreeView1SelectionChanged(Sender: TObject);
begin
  if TreeView1.Selected <> nil then
  begin
    actualNodeText := TreeView1.Selected.Text;
    dbTypeText := 'STANDARD : ' + actualNodeText;
    DrawGrid1.Repaint;
    getSettings;
  end;
end;

end.

