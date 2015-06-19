#include "MyQDataBrowser.h"

MyQDataBrowser::MyQDataBrowser(QWidget *parent, QString v) :
    QTableWidget(parent)
{
    bool found = false;
    QString dbf = v;
    view =  v;

    editor = NULL;
    dspinbox = NULL;
    checkBox = NULL;
    workArea = NULL;
    datebox = NULL;
    timebox = NULL;

    old_row = 0;
    old_col = 0;

    if (view.length() < 1)
    {
	#ifdef LANG_DE
        msgbox("Fehler!","Sichtdatei konnte nicht geöffnet werden.");
	#else
	msgbox("Error!","Formview could not open");
	#endif
        return;
    }

    if (view.endsWith(".dbf"))
    {
        dbf = view.left(view.length()-4);
    }

    for (int i = 0; i < mydata::wa.count(); i++)
    {
        if (!mydata::wa.at(i)) break;
        if (mydata::wa.at(i)->dbFile.contains(dbf))
        {
            workArea = mydata::wa.at(i);
            found = true;
            break;
        }
    }

    if (!workArea || !found)
    {
        xbase_add_path(".");
        xbase_add_path("./data/");
        xbase_open_dbf(dbf);
        xbase_select(1);

        for (int i = 0; i < mydata::wa.count(); i++)
        {
            if (!mydata::wa.at(i)) break;
            if (mydata::wa.at(i)->dbFile.contains(dbf))
            {
                workArea = mydata::wa.at(i);
                found = true;
                break;
            }
        }

        if (!workArea || !found) {
            print_console(std::string("workArea = 0x0"));
            return;
        }
    }

    setColumnCount(workArea->map_field.count());
    setRowCount   (workArea->db->records);

    set_header();
}

void MyQDataBrowser::set_header(void)
{
    for (int c = 0; c < workArea->map_field.count(); c++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        setHorizontalHeaderItem(c,item);
        item->setText(workArea->map_head[c]);
    }

    for (int c = 0; c < workArea->db->records; c++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        setVerticalHeaderItem(c,item);

        if (c == 0)
            item->setText(QChar(0x25ba)); else
            item->setText("     ");
    }

    connect(this, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(itemClick(QTableWidgetItem *)));
    connect(this, SIGNAL(cellPressed(int, int)),           this, SLOT(cellPress(int, int)));
    connect(this, SIGNAL(cellDoubleClicked(int,int)),      this, SLOT(openEditLine(int,int)) );


    int f, r;
    for (f = 0; f < workArea->map_field.count(); f++)
    {
        for (r = 0; r < workArea->db->records; r++)
        {
            QTableWidgetItem *it = new QTableWidgetItem;
            setItem(r,f,it);
            it->setFlags(
                        Qt::ItemIsSelectable    |
                        Qt::ItemIsEditable      |
                        Qt::ItemIsDragEnabled   |
                        Qt::ItemIsUserCheckable |
                        Qt::ItemIsEnabled);

            it->setText(workArea->content[
                        workArea->map_head[f]].at(r).value_text);
        }
    }
}

void MyQDataBrowser::itemClick(QTableWidgetItem *i)
{
    QTableWidgetItem *r;

    QFont f("Arial");
    f.setBold(true);
    f.setPointSize(12);

    for (int c = 0; c < workArea->db->records; c++)
    {
        r = verticalHeaderItem(c);
        r->setFont(f);
        r->setText(" ");
    }

    r = verticalHeaderItem(currentRow());
    r->setText(QChar(0x25ba));
}

void MyQDataBrowser::cellPress(int row, int col)
{
    char buffer[255];

    if (dspinbox != NULL)
    if (workArea->map_field[workArea->map_head[old_col]].type == FIELD_NUMERIC)
    {
        sprintf(buffer,"%.7f",dspinbox->value());

        item(old_row,old_col)->setText(QString(buffer));
        workArea->content[
        workArea->map_head[old_col]][old_row].setText(buffer);
    }

    if (timebox != NULL)
    if (workArea->map_field[workArea->map_head[old_col]].type == FIELD_TIME)
    {
	QString h = QString("%1").arg(timebox->time().hour()  ,2,10,QChar('0'));
	QString m = QString("%1").arg(timebox->time().minute(),2,10,QChar('0'));
	QString s = QString("%1").arg(timebox->time().second(),2,10,QChar('0'));

	QString fv = QString(h+":"+m+":"+s);

	if (!timebox->time().isValid(h.toInt(),m.toInt(),s.toInt()))
	fv = "00:00:00";

        item(old_row,old_col)->setText(fv);
        workArea->content[
        workArea->map_head[old_col]][old_row].setText(fv);

cout <<workArea->content[
        workArea->map_head[old_col]][old_row].value_text.toStdString() << endl;
    }

    if (datebox != NULL)
    if (workArea->map_field[workArea->map_head[old_col]].type == FIELD_DATE)
    {
	QString y = QString("%1").arg(datebox->date().year());
	QString m = QString("%1").arg(datebox->date().month(),2,10,QChar('0'));
	QString d = QString("%1").arg(datebox->date().day  (),2,10,QChar('0'));

	QString fv = QString(d+"."+m+"."+y);

        item(old_row,old_col)->setText(fv);
        workArea->content[
        workArea->map_head[old_col]][old_row].setText(fv);
    }

    if (checkBox != NULL)
    checkBox->check();

    removeCellWidget(old_row,old_col);
    itemClick(item(row,col));

    dspinbox = NULL;
    editor = NULL;
    checkBox = NULL;
    datebox = NULL;
    timebox = NULL;
}

void MyQDataBrowser::setAlias(QString str)
{
    this->alias = str;
}

void MyQDataBrowser::openEditLine(int row, int col)
{
    int i = col;
    print_console(col);

    old_row = row;
    old_col = col;

    if (workArea->map_field[workArea->map_head[i]].type == FIELD_CHAR)
    {
        editor = new MyQLineEdit(currentItem()->text(),this);
        editor->setMaxLength(workArea->map_field[workArea->map_head[i]].length);
        setCellWidget(row,col,editor);
        editor->show();
    }
    else if (workArea->map_field[workArea->map_head[i]].type == FIELD_NUMERIC)
    {
        int prec = 7;
        float  d = workArea->content[workArea->map_head[col]][row].value_text.toFloat();

        dspinbox = new MyQDoubleSpinBox(this);
        dspinbox->setDecimals(prec);
        //dspinbox->setMaximum( 999999999.9999999);
        //dspinbox->setMinimum( -99999999.9999999);
        dspinbox->setRange(-9999999999.9999999,9999999999.9999999);
        dspinbox->setSingleStep(1.0);
        dspinbox->setValue(QString("%1").arg(d,0,'f',prec).toFloat());

        setCellWidget(row,col,dspinbox);
        dspinbox->show();
    }
    else if (workArea->map_field[workArea->map_head[i]].type == FIELD_LOGIC)
    {
        checkBox = new MyQCheckBox(this);
        checkBox->browser = this;

        if (currentItem()->text().contains("T"))
        checkBox->setCheckState(Qt::Checked); else
        checkBox->setCheckState(Qt::Unchecked);

        setCellWidget(row,col,checkBox);
        checkBox->show();
    }
    else if (workArea->map_field[workArea->map_head[i]].type == FIELD_TIME)
    {
	QString fv   = workArea->content[workArea->map_head[col]][row].value_text;
	QString h,m,s;
	QChar * data = fv.data();

	h = QString("%1%2").arg(data[0]).arg(data[1]); 
	m = QString("%1%2").arg(data[3]).arg(data[4]);
	s = QString("%1%2").arg(data[6]).arg(data[7]);

	QTime tmp;
	tmp.setHMS(h.toInt(),m.toInt(),s.toInt());

	timebox = new MyQTimeEdit(this);
	timebox->setTime(tmp);

	setCellWidget(row,col,timebox);
	timebox->show();
    }
    else if (workArea->map_field[workArea->map_head[i]].type == FIELD_DATE)
    {
	datebox = new MyQDateEdit(this);
	
	QString fv   = workArea->content[workArea->map_head[col]][row].value_text;
	QString ds,ms,ys;
	QChar * data = fv.data();

	if (data[1] == '.') {
	    ds = QString("%1%2").arg("0")    .arg(data[0]); 
	    ms = QString("%1%2").arg(data[2]).arg(data[3]);
	    ys = QString("%1%2"
			 "%3%4").arg(data[5]).arg(data[6])
			 	.arg(data[7]).arg(data[8]);

	}
	else {
	    ds = QString("%1%2").arg(data[0]).arg(data[1]); 
	    ms = QString("%1%2").arg(data[3]).arg(data[4]);
	    ys = QString("%1%2"
			 "%3%4").arg(data[6]).arg(data[7])
			 	.arg(data[8]).arg(data[9]);
	}
 
	int d = ds.toInt();
	int m = ms.toInt();
	int y = ys.toInt();

	QDate tmp = datebox->date();
	tmp.setDate(y,m,d);

	datebox->setDate(tmp);
	datebox->setDisplayFormat(QString("dd.MM.yyyy"));

	setCellWidget(row,col,datebox);
	datebox->show();
    }
}

void MyQCheckBox::check(void)
{
    if (browser->checkBox->checkState() == Qt::Checked)
    {
	browser->workArea->content[
	browser->workArea->map_head[
	browser->old_col]][
	browser->old_row].setText("T");

        browser->item(
        browser->old_row,
        browser->old_col)->setText("T");
    }
    else {

	browser->workArea->content[
	browser->workArea->map_head[
	browser->old_col]][
	browser->old_row].setText("F");

        browser->item(
        browser->old_row,
        browser->old_col)->setText("F");
    }
}

MyQDoubleSpinBox::MyQDoubleSpinBox(QWidget *parent) : QDoubleSpinBox(parent)
{
    QObject::connect(this, SIGNAL(valueChanged(double)), this, SLOT(valueModified(double)));
    table = dynamic_cast<MyQDataBrowser*>(parent);
    setValue(atof(table->currentItem()->text().toLatin1().data()));
}

void MyQDoubleSpinBox::valueModified(double val)
{
    char buffer[255];
    sprintf(buffer,"%.7f",val);
    setValue(QString("%1").arg(val,0,'f',7).toFloat());

    table->currentItem()->setText(QString(buffer));
    table->workArea->content[
    table->workArea->map_head[table->old_col]][table->old_row].setText(buffer);
}

