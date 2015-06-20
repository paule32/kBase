unit main;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, Menus,
  ComCtrls, Buttons, PairSplitter, ExtCtrls, StdCtrls, Grids, EditBtn, Spin;

type

  { TForm1 }

  TForm1 = class(TForm)
    DrawGrid1: TDrawGrid;
    MainMenu1: TMainMenu;
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
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    SpeedButton3: TSpeedButton;
    Splitter1: TSplitter;
    StaticText1: TStaticText;
    StaticText2: TStaticText;
    StatusBar1: TStatusBar;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
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
    procedure FormResize(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure MenuItem1Click(Sender: TObject);
    procedure MenuItem2Click(Sender: TObject);
    procedure MenuItem6Click(Sender: TObject);
    procedure SpinEdit1Enter(Sender: TObject);
  private
    ListDriver: TComboBox;
    BCDChekBox: TCheckBox;
    PortEditor: TSpinEdit;
    PathEditor: TDirectoryEdit;
    Button: TButton;
  public
    { public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

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
      Canvas.TextOut(aRect.Left + 5, aRect.Top + 2,'STANDARD');
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
      PathEditor.Directory := 'c:\';
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
  end;;
end;

procedure TForm1.FormResize(Sender: TObject);
begin
  DrawGrid1.DefaultColWidth := (DrawGrid1.Width div 2) - 10;
end;

procedure TForm1.FormShow(Sender: TObject);
begin
  DrawGrid1.DefaultColWidth := (DrawGrid1.Width div 2) - 10;
end;

procedure TForm1.MenuItem2Click(Sender: TObject);
begin
  TreeView1.Items.AddChild(TreeView1.TopItem,'Neue Datenbank');
end;

procedure TForm1.MenuItem6Click(Sender: TObject);
begin
  Close;
end;

procedure TForm1.SpinEdit1Enter(Sender: TObject);
begin
  StatusBar1.Panels[0].Text := 'Port number for server';
end;

end.

