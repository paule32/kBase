/* this is a comment block
**
**/
#ifndef __TEST_PRG__
#define __TEST_PRG__

// this is a comment line
parameter bModal

// a new array with 2 dimensions
// 1 - 4 deep items
// 2 - 8 deep items ...
ArrayA = new array(2,4,8)
ArrayB = new array(2,4,8)

ArrayA[0][0] = 2
ArrayA[1][0] = ArrayA[0][0]
ArrayB[0][0] = 12.24
				
if (not bModal)
  varA = 42
  varB += 21 + 9 * 2 - varA
  varA = varB + 1
endif

? "Hallo Welt!"
? ArrayB[0][0]
? 42.312

for varA = ArrayA[1][0] to 5
  msgbox("title","hallo")
endfor

local f
f = new Form1()
f.show()

class KlasseA of Form
    with (this)
	height = 500
	width = 500
	menuFile = "gehalt.mnu"
    endwith

    this.Session1 = new Session(this)
    with (this.Session1)
        onTimer = class::Session1_OnTimer

        host = "127.0.0.1"
        user = "jens"
        pass = "secret"

        port = 7945

        TimeOut = ((1000 * 60) * 3)  // 3 min.
        active = .T.
    endwith

    this.DataBase1 = new DataBase(this)
    with (this.DataBase1)
        session = form.Session1
        databaseName = "Beispiel"
        active = .t.
    endwith

    function zuzu
    return 32

    function Session1_OnTimer
        msgbox("GuGU","Alfonso")
    return zuzu
endclass

class Formular1 of KlasseA
    this.PushButton1 = new PushButton(this)
    with (this.PushButton1)
	onClick = class::PushButton1_OnClick

	top = 30
	visible = true
	text = "Press " + "Me1"
    endwith

    function PushButton1_OnClick()
	msgbox("Hallo","DUDU")
    return (2 * 3)
endclass

class Form1 of Formular1

    this.Query1 = new Query(this)
    with (this.Query1)
    endwith

    this.PushButton2 = new PushButton(this)
    with (this.PushButton2)
	top = 30
	left = 30
	text = "Press"
	visible = true
    endwith

    this.Entryfield1 = new EntryField(this)
    with (this.Entryfield1)
    	dataLink = form.Query1.rowset.fields["name"]
	top = 20
	left = 100
	width = 100
	height = 25
    endwith

    this.Container1 = new Container(this)
    with (this.Container1)
	top = 60
	left = 100
	width = 300
	height = 300
    endwith

    this.Container1.PushButton1 = new PushButton(this.Container1)
    with (this.Container1.PushButton1)
	//top = 10
	//left = 10
	//height = 25
	//width = 90
    endwith

    this.Container1.Container1 = new Container(this.Container1)
    with (this.Container1.Container1)
	top = 50
	left = 100
	width = 200
	height = 200
    endwith

    this.Container1.Container1.Entryfield1 = new EntryField(this.Container1.Container1)
    with (this.Container1.Container1.Entryfield1)
	top = 20
	left = 20
	width = 100
	height = 25
    endwith

endclass


#endif
