library helper;

uses
  Classes, Strings, Db, dbf
  { you can add units after this };

var
  kBase_DBF_Files: Array[1..2048] of TDbf;
  kBase_DBF_Area: Integer;

procedure set_work_area(a: Integer);
begin
    if kBase_DBF_Area - 1 < 1 then
       kBase_DBF_Area := 1 else
       kBase_DBF_Area := a;

    if kBase_DBF_Files[kBase_DBF_Area] = nil then
       kBase_DBF_Files[kBase_DBF_Area] := TDbf.Create(nil);
end;

procedure set_data_path(p: Pchar); cdecl; export;
begin
    if kBase_DBF_Area - 1 < 1 then
       kBase_DBF_Area := 1;
    if kBase_DBF_Files[kBase_DBF_Area] = nil then
       kBase_DBF_Files[kBase_DBF_Area] := TDbf.Create(nil);
       kBase_DBF_Files[kBase_DBF_Area].FilePath := strnew(PChar(p));
end;

procedure set_table_name(n: PChar); cdecl; export;
begin
    kBase_DBF_Files[kBase_DBF_Area].TableLevel := 7;
    kBase_DBF_Files[kBase_DBF_Area].Exclusive  := True;
    kBase_DBF_Files[kBase_DBF_Area].TableName  := strnew(PChar(n));
end;

procedure open_table; cdecl; export;
begin
    try
        kBase_DBF_Files[kBase_DBF_Area].Open;
    except
        with kBase_DBF_Files[kBase_DBF_Area] do
        begin
            Active := false;
            TableLevel := 7;
            with FieldDefs do
            begin
                clear;
                Add('id', ftInteger, 10, false);
            end;
            CreateTable;
            Active := true;
        end;
    end;
end;

procedure close_table; cdecl export;
begin
    kBase_DBF_Files[kBase_DBF_Area].Close;
end;

procedure create_table; cdecl; export;
begin
    kBase_DBF_Files[kBase_DBF_Area].CreateTable;
end;

procedure add_index(idxname: PChar; fname: PChar); cdecl; export;
begin
    kBase_DBF_Files[kBase_DBF_Area].AddIndex(
        StrNew(PChar(idxname)),
        StrNew(PChar(fname)),
        []
    );
end;

Function WordCount(CText: pchar): Longint; cdecl; export;
  Function Seps(As_Arg: Char): Boolean;
  Begin
    //Seps := As_Arg In
    //[#0..#$1F, ' ', '.', ',', '?', ':', ';', '(',')', '/', ''];
    if As_Arg = ''  then result := true else
    if As_Arg = ' ' then result := true else
    if As_Arg = ',' then result := true else
    if As_Arg = ']' then result := true else
    if As_Arg = #9  then result := true else
    if As_Arg = #10 then result := true else
    result := false;
  End;

Var
  Ix: Word;
  Work_Count: Longint;
Begin
  Work_Count := 0;
  Ix := 1;
  While Ix <= Length(CText) Do
    Begin
      While (Ix <= Length(CText)) And (Seps(CText[Ix])) Do
        Inc(Ix);
      If Ix <= Length(CText) Then
        Begin
          Inc(Work_Count);
          While (Ix <= Length(CText)) And
                (Not Seps(CText[Ix])) Do
            Inc(Ix);
        End;
    End;
  Result := Work_Count;
End;

exports
  add_index, create_table, close_table, open_table, set_table_name, set_data_path,
  set_work_area,
  WordCount;

begin
end.

