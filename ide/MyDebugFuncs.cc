#include <stdio.h>
#include <windows.h>
#include <QString>
#include "MyQVariant.h"
#include "mingw/include/boost/multi_array.hpp"
#include "mingw/include/boost/array.hpp"

static int debug_console = 1;

void print_console(QString val)
{
    if (debug_console == 1)
    {
        DWORD i;
        AllocConsole();

        char buffer[2048];
        sprintf(buffer,"%s\n",val.toStdString().c_str());

        WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),buffer,strlen(buffer),&i,NULL);
    }
}

void print_console(double val)
{
    if (debug_console == 1)
    {
        DWORD i;
        AllocConsole();

        char buffer[2048];
        sprintf(buffer,"%f\n",val);

        WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),buffer,strlen(buffer),&i,NULL);
    }
}

void print_console(MyQVariant& x)
{
    if (debug_console == 1)
    {                
        if (x.value_type == MYQVAR_TYPE_DOUBLE) print_console(x.value_double); else
        if (x.value_type == MYQVAR_TYPE_STRING) print_console(x.value_string);
    }
}

/*
void print_console(boost::multi_array A)
{

}
*/
