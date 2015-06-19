#ifndef MYXBASE_H
#define MYXBASE_H

#include "pch.h"

extern void    xbase_add_path(QString);
extern QString xbase_open_dbf(QString);
extern int     xbase_count_records(QString, QString);
extern void    xbase_select(int);
extern void    xbase_print_field(QString);

class MyQMemoryTable
{
public:
    MyQMemoryTable() { }
    QString value_text;
    void setText(QString);
    int    value_type;
    struct tm *value_time;
};

class MyQWorkArea
{
public:
    MyQWorkArea(QString);

    void dbf_read_header(void);
    void dbf_read_fields(void);

    void dbf_write_header(void);

    QString dbFile;
    int     dbHandle;
    int     dbVersion;

    class   QMap<QString , QVector<MyQMemoryTable> > content;

    class   Node
    {
    public:
	        int  type;
            char *name;
            QString value;
            
	struct tm *value_time;

            int  length;
            int  prec;
    		bool index;
    };

    class   QMap<QString, Node> map_field;
    class   QMap<int,  QString> map_head;

    struct  DB_HEADER db_buf, *db;
    struct  DB_FIELD *header[2048];

    int     header_length;
    int     record_length;

    int     record_count;
};

class MyTableVectorClass
{
public:
    MyTableVectorClass(void) { }
    int     field_type;
    QString field_name;
};

extern QVector <MyTableVectorClass> table_vector;
extern void create_dbf_table(QString);

#ifndef USE_DEF_XBASE
namespace mydata
{
    extern class QStringList  data_paths;
    extern class QVector<MyQWorkArea*> wa;
    extern int   MyQCurrentWorkArea;
}
#else
namespace mydata
{
    class QStringList  data_paths;
    class QVector<MyQWorkArea*> wa;
    int   MyQCurrentWorkArea = 0;
}
#endif
#endif