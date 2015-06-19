#include "xbase.h"

extern "C" void DisplayErrorMessage(int line,char *msg)
{
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Programmfehler!");
    msgBox->setText(QString("Error: %1: %2").arg(line).arg(msg));
    msgBox->exec();
}

void save_all_browsers(QList<MyQDataBrowser*> ptr)
{
    ptr[0]->workArea->dbf_write_header();
}

void xbase_add_path(QString str)
{
    mydata::data_paths << str;
}

void xbase_select(int w)
{
    if (w <= 0)
    {
        if ((mydata::wa.count() <= 0))
	    {
	        print_console("Fehler: keine Tabellen offen.");
	        return;
	    }
	    w = 1;
    }
    mydata::MyQCurrentWorkArea = w;
}

int xbase_count_records(QString field, QString filter)
{
    if (mydata::MyQCurrentWorkArea <= 0)
    {
	print_console("Fehler: Es ist keine Tabelle ge�ffnet.");
	exit(1);
    }

    int  i, cnt = 0 ;
    for (i = 0; i < mydata::wa.at(mydata::MyQCurrentWorkArea-1)->content[field].count(); i++)
    {
	if (mydata::wa.at(mydata::MyQCurrentWorkArea-1)->content[field].at(i).value_text.trimmed() == filter.trimmed())
	++cnt;
    }

    if (cnt <= 0) {
    	print_console("Warnung: Datenbankfeld \"" + field + "\"nicht gefunden.");
	return -1;
    }

    mydata::wa.at(
    mydata::MyQCurrentWorkArea-1)->record_count = cnt;

    return cnt;
}

QString xbase_open_dbf(QString str)
{
    QString dbf;

    if (!str.endsWith(".dbf"))
        str = str + QString(".dbf");

    if (!mydata::data_paths.contains(QCoreApplication::applicationDirPath())) {
         mydata::data_paths << QCoreApplication::applicationDirPath() + "/";
         mydata::data_paths << QCoreApplication::applicationDirPath() + "/data/";
    }

    int i;
    FILE *data = NULL;
    bool found = false;

    for (i = 0; i < mydata::data_paths.count(); i++)
    {
	if (found == true) break;

        dbf = QString(mydata::data_paths.at(i) + str);
        if ((data = fopen(QString(dbf).toStdString().c_str(),"rb")) != NULL)
        {
            fclose(data);
            found = true;
        }
    }

    if (found == false) {
    str = str + QString(" not found");  } else {
    str = str + QString(" was found");  }

    print_console(str);

    MyQWorkArea *WA = new MyQWorkArea(dbf);
    mydata::wa.append(WA);

    if (mydata::MyQCurrentWorkArea <= 0)
        mydata::MyQCurrentWorkArea = mydata::wa.count();

    return dbf;
}

MyQWorkArea::MyQWorkArea(QString dbf)
{
    this->dbFile = dbf;

    mydata::data_paths << QCoreApplication::applicationDirPath();
    mydata::data_paths << QCoreApplication::applicationDirPath() + "/data";

    if ((dbHandle = open(dbf.toStdString().c_str(), O_RDONLY)) == -1) {
        msgbox("Fehler",QString("Kann Datei: %1\nnicht �ffnen").arg(dbf));
        return;
    }

    db = &db_buf;

    dbf_read_header();
    dbf_read_fields();
}

void MyQWorkArea::dbf_read_header(void)
{
    if ((read(dbHandle, (char *)db, sizeof(struct DB_HEADER))) == -1 ) {
        msgbox("Fehler!","kann dbf Header nicht lesen.");
        return;
    }

    this->dbVersion     = db->version;
    this->header_length = rotate2b(db->header_length) / 32;
    this->record_length = rotate2b(db->record_length);
}

void MyQWorkArea::dbf_write_header(void)
{
    FILE *h;
    int r,c;

    if (!(h = fopen("./data/test.dbf","wb"))) {
        msgbox("Fehler!", "kann Datenbankdatei nicht schreibend offnen.");
        return;
    }

    if ((fwrite(db,1,sizeof(struct DB_HEADER),h)) == -1) {
        msgbox("Fehler!", "kann dbf Header nicht schreiben.");
        return;
    }

    for (r = 0; r < map_head.count(); r++)
    {
        if((fwrite(header[r],1,sizeof(struct DB_FIELD),h)) == -1) {
            msgbox("Fehler","kann Felddaten nicht schreiben.");
            return;
        }
    }

    char d = 0x0d;
    fwrite(&d,1,1,h);

    for (r = 0; r < db->records; r++)
    {
        d = 0x20;
        fwrite(&d,1,1,h); // delete flag

        for (c = 0; c < map_field.count(); c++)
        {
            int pad = map_field[map_head[c]].length;
            int ft  = header[c]->field_type;

            if (ft == FIELD_CHAR)
            {
                content[map_head[c]][r].value_text.toStdString().insert(0, pad -
                content[map_head[c]][r].value_text.size(), ' ');

                fwrite(
                content[map_head[c]][r].value_text.toStdString().c_str(),1,strlen(
                content[map_head[c]][r].value_text.toStdString().c_str() ),h);
            }
            else if (ft == FIELD_NUMERIC)
	        {
                content[map_head[c]][r].value_text.toStdString().insert(0, pad -
                content[map_head[c]][r].value_text.size(), ' ');

                fwrite(
                content[map_head[c]][r].value_text.toStdString().c_str(),1,strlen(
                content[map_head[c]][r].value_text.toStdString().c_str() ),h);
            }
	        else if (ft == FIELD_LOGIC)
	        {
                fwrite(
                content[map_head[c]][r].value_text.toStdString().c_str(),1,1,h);
            }
	        else if (ft == FIELD_DATE)
	        {
                QString str    = content[map_head[c]][r].value_text;
	            QChar * data   = str.data();

                QString year4  = QString(data[9]);
                QString year3  = QString(data[8]);
                QString year2  = QString(data[7]);
                QString year1  = QString(data[6]);
	            QString month2 = QString(data[4]);
	            QString month1 = QString(data[3]);
	            QString day2   = QString(data[1]);
	            QString day1   = QString(data[0]);

	            str = QString(
                year1  + year2  +
                year3  + year4  +
                month1 + month2 +
                day1   + day2  );

                fwrite(
                str.toStdString().c_str(),1,strlen(
                str.toStdString().c_str() ),h);
            }
            else if (ft == FIELD_TIME)
            {
                QString str  = content[map_head[c]][r].value_text;
	            QChar * data = str.data();

                QString hs = QString("%1%2").arg(data[0]).arg(data[1]);
                QString ms = QString("%1%2").arg(data[3]).arg(data[4]);
                QString ss = QString("%1%2").arg(data[6]).arg(data[7]);

                int h2 = hs.toInt() * 3600000;
                int m2 = ms.toInt() *   60000;
                int s2 = ss.toInt() *    1000;

                long int t  = h2 + m2 + s2;
                long int p  = 0;

                fwrite(&p,1,sizeof(long int),h); // date
                fwrite(&t,1,sizeof(long int),h); // time
            }
        }
    }

    d = 0x1a;
    fwrite(&d,1,1,h);

    fclose(h);
}

void MyQWorkArea::dbf_read_fields(void)
{
    struct DB_FIELD *hdr;
    unsigned char *record;

    int a,k=0;
    for (a = 0; a < 127; a++)
    header[a] = (struct DB_FIELD*) malloc(sizeof(struct DB_FIELD) * header_length);

    if (header[k] == NULL) {
        msgbox("Fehler","kann kein Speicher anfordern.");
        return;
    }

    char c[1];
    int h = 1;

    lseek(dbHandle, header_length, SEEK_SET);
    int pos = 0;
    while (1)
    {
        read(dbHandle,c,1);
        if (c[0] == 0x0d) break;
        pos++;
    }
    int psize = pos / sizeof(struct DB_FIELD);
    h = --psize;
    lseek(dbHandle, 0, SEEK_SET);
    dbf_read_header();

    //print_console(QString("\n::> %1, %2").arg(pos).arg(psize));
    pos = 0;
    for (hdr = header[k] + 1; --header_length; hdr++, k++)
    {
        if (psize-- < 1) break;
        if((read(dbHandle, header[k], sizeof(struct DB_FIELD))) == -1) {
            msgbox("Fehler","kann Feld nicht einlesen.");
            return;
        }

        //print_console(QString("--> %1").arg(int(header->field_type)));

        Node nfield;
        nfield.name   = new char[strlen((char*)header[k]->field_name)+1];
        strcpy(nfield.name,(char*)header[k]->field_name);

        nfield.type   = header[k]->field_type;
        nfield.length = header[k]->length_binary;
        nfield.prec   = header[k]->dec_count_binary;

        map_field.insert(QString((char*)header[k]->field_name), nfield);
        map_head .insert(pos++, QString((char*)header[k]->field_name));
    }

    if ((record = (unsigned char*) malloc(record_length + 1)) == NULL)	{
        perror("malloc");
        exit(1);
    }
    record[record_length] = '\0';

    char *flag_byte;
    lseek(dbHandle, rotate2b(db->header_length), SEEK_SET);

    if ( (flag_byte = (char*)malloc(1)) == NULL ) {
        msgbox("Fehler!","kann kein Speicher zuweisen.");
        exit(1);
    }

    if (read(dbHandle, flag_byte, 1) == -1) {
        msgbox("Fehler","reading Flag Byte");
        exit(1);
    }

    *flag_byte = *(record + record_length - 1);

    MyQMemoryTable mt;
    QVector<class MyQMemoryTable> memtab[200];
    int f, oldfptr = 0;

    for (int i = 0; i < db->records; i++)
    {
        read(dbHandle, record, record_length-1);

        QString fr = QString((char*)record);
        QString fv;
        int l1 = 0;

        for (f = 0; f < map_field.count(); f++)
        {
            mt.value_type = map_field[map_head[f]].type;

            if (mt.value_type == FIELD_NUMERIC)
            {
                if (l1 == 0)
                {
                    fv = fr.mid(0,map_field[map_head[f]].length); l1++;
                    l1 = l1 + fv.length();
                } else {
                    fv = fr.mid(l1,map_field[map_head[f]].length);
                    l1 = l1 + fv.length();
                }
            }
            else if (mt.value_type == FIELD_LOGIC)
            {
                if (l1 == 0)
                {
                    fv = fr.mid(0,map_field[map_head[f]].length);
                    l1 = l1 + 1;
                } else {
                    fv = fr.mid(l1,1);
                    l1 = l1 + 1;
                }
            }
            else if (mt.value_type == FIELD_CHAR)
            {
                if (l1 == 0)
                {
                    fv = fr.mid(0,map_field[map_head[f-0]].length);
                    l1 = l1 + fv.length();
                } else {
                    fv = fr.mid(l1,map_field[map_head[f]].length);
                    l1 = l1 + fv.length();
                }
            }
            else if (mt.value_type == FIELD_TIME)
            {
                long int time;

		        if (l1 == 0)
		        {
		            fv = fr.mid(0,map_field[map_head[f-0]].length);
		            l1 = l1 + fv.length();
		        } else {
		            fv = fr.mid(l1,map_field[map_head[f]].length);
		            l1 = l1 + fv.length();
		        }

                #define MA 0
                char b1 = record[record_length-0];
                char b2 = record[record_length-1];
                char b3 = record[record_length-2];
                char b4 = record[record_length-3];

                unsigned char data[4] = { b1, b2, b3, b4 };

                int final = *(int *)data;
                fv = QString(final);

                printf("0x%x  ==> 0x%x : 0x%x\n", final, 2*36, 2*36);
            }
	        else if (mt.value_type == FIELD_DATE)
	        {
		        if (l1 == 0)
		        {
		            fv = fr.mid(0,map_field[map_head[f-0]].length);
		            l1 = l1 + fv.length();
		        } else {
		            fv = fr.mid(l1,map_field[map_head[f]].length);
		            l1 = l1 + fv.length();
		        }

		        QString year   = fv.left(4);
		        QChar * data   = fv.data();
		        QString month1 = QString(data[4]);
		        QString month2 = QString(data[5]);
		        QString day1   = QString(data[6]);
		        QString day2   = QString(data[7]);

		        QString str   = QString(
		        day1   + day2   + "." +
		        month1 + month2 + "." + year);

		        fv = str;
		        l1 = l1 + fv.length();
	            }
	            else if (mt.value_type == FIELD_TIME)
	            {
		        if (l1 == 0)
		        {
		            fv = fr.mid(0,map_field[map_head[f-0]].length);
		            l1 = l1 + fv.length();
		        } else {
		            fv = fr.mid(l1,map_field[map_head[f]].length);
		            l1 = l1 + fv.length();
		        }

		        if (fv.trimmed().length() < 1)
		        fv = "0";

		        long int h    = (fv.toInt() / ((60 * 60) * 1000));
		        long int r    = (fv.toInt() % ((60 * 60) * 1000));
		        long int m    = (r / 60000);  r =  r     % 60000 ;
		        long int s    = (r /  1000);

		        fv = QString("%1:%2:%3").arg(h).arg(m).arg(s);
	        }
            
            map_field[map_head[f]].value = fv;

            mt.value_text = fv;
            memtab[f].append(mt);
            content.insert(map_head[f],memtab[f]);

            int k = content.count();
            int r = f;
        }
    }

    //free(record);
}

void xbase_print_field(QString field)
{
    MyQWorkArea *wa = mydata::wa.at(0);

    print_console(wa->dbFile);
    print_console(wa->record_length);
    print_console(field);
    //print_console(wa->content["name"].at(0).value_text);
}

void MyQMemoryTable::setText(QString str)
{
    value_text = str;
}

