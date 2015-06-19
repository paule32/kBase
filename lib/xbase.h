#ifdef __XBASE_H__
#define __XBASE_H__

#include "pch.h"

extern void    xbase_add_path(QString);
extern QString xbase_open_dbf(QString);
extern int     xbase_count_records(QString,QString);
extern void    xbase_select(int);
extern void    xbase_print_field(QString);

class MyQMemoryTable
{
public:
    MyQMemoryTable() { }
    QString value_text;
    void setText(QString);
    int value_type;
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

#ifdef __MAIN_RUN__
QVector <MyTableVectorClass> table_vector;
#else
extern QVector <MyTableVectorClass> table_vector;
#endif
extern void create_dbf_table(QString);

namespace mydata
{
#ifdef __MAIN_RUN__
    class QStringList  data_paths;
    class QVector<MyQWorkArea*> wa;
    int   MyQCurrentWorkArea = 0;
#else
    extern class QStringList  data_paths;
    extern class QVector<MyQWorkArea*> wa;
    extern int   MyQCurrentWorkArea;
#endif
}

#endif
