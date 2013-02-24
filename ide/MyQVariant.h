#ifndef __MYQVARIANT_H__
#define __MYQVARIANT_H__

#include "mingw/include/boost/multi_array.hpp"
#include "mingw/include/boost/array.hpp"

#include <QString>

class MyQVariant;

extern void print_console (double);
extern void print_console (QString);
extern void print_console (MyQVariant&);

#define MYQVAR_TYPE_DOUBLE 1
#define MYQVAR_TYPE_STRING 2

class MyQVariant
{
public:
    MyQVariant() { }
    MyQVariant(MyQVariant *);
    MyQVariant(double);
    MyQVariant(QString&);

    MyQVariant& operator += (MyQVariant&);
    MyQVariant& operator -= (MyQVariant&);
    MyQVariant& operator *= (MyQVariant&);
    MyQVariant& operator /= (MyQVariant&);

    MyQVariant& operator += (double);
    MyQVariant& operator -= (double);
    MyQVariant& operator *= (double);
    MyQVariant& operator /= (double);

    MyQVariant& operator += (QString&);

    MyQVariant& operator = (double);
    MyQVariant& operator + (double);
    MyQVariant& operator - (double);
    MyQVariant& operator * (double);
    MyQVariant& operator / (double);

    MyQVariant& operator = (QString);
    MyQVariant& operator + (QString);

    MyQVariant& operator = (MyQVariant&);

public:
    int     value_type;

    double  value_double;
    QString value_string;
};

#ifdef __MAIN_RUN__
template <typename Array>
void print(const Array& A)
{
    typename Array::const_iterator i;
    char buffer[2048];
    strcpy(buffer,atoi(A.index_range()));
    strcpy(buffer,"[");
    for (i = A.begin(); i != A.end(); ++i)
    {
        //strcat(buffer,*i); // fehler
        if (boost::next(i) != A.end())
            strcat(buffer,",");
    }
    strcat(buffer,"]");

    print_console(QString("%1").arg(buffer));
}

MyQVariant::MyQVariant(MyQVariant *c)
{
    this->value_double = c->value_double;
    this->value_string = c->value_string;

    this->value_type = c->value_type;
}

MyQVariant::MyQVariant(double val)
{
    this->value_type = MYQVAR_TYPE_DOUBLE;
    this->value_double = val;
}

MyQVariant::MyQVariant(QString& str)
{
    print_console(QString("<--33-->"));
    this->value_type = MYQVAR_TYPE_STRING;
    this->value_string = str;
}

MyQVariant& MyQVariant::operator += (MyQVariant& rhs)
{
    if (value_type == MYQVAR_TYPE_DOUBLE)
    this->value_double =
    this->value_double +
    rhs.  value_double ; return *this;
}

MyQVariant& MyQVariant::operator += (QString& rhs)
{
    print_console(QString("<--55-->"));
    if (this->value_type == MYQVAR_TYPE_DOUBLE) {
        this->value_double =
        this->value_double + rhs.size() ;
        this->value_type  = MYQVAR_TYPE_DOUBLE; } else
    if (this->value_type == MYQVAR_TYPE_STRING) {
        this->value_string =
        this->value_string + rhs;
        this->value_type  = MYQVAR_TYPE_STRING;
    }

    return *this;
}

MyQVariant& MyQVariant::operator -= (MyQVariant& rhs)
{
    if (value_type == MYQVAR_TYPE_DOUBLE)
    this->value_double =
    this->value_double -
    rhs.  value_double ; return *this;
}

MyQVariant& MyQVariant::operator *= (MyQVariant& rhs)
{
    if (value_type == MYQVAR_TYPE_DOUBLE)
    this->value_double =
    this->value_double *
    rhs.  value_double ; return *this;
}

MyQVariant& MyQVariant::operator /= (MyQVariant& rhs)
{
    if (value_type == MYQVAR_TYPE_DOUBLE)
    this->value_double =
    this->value_double /
    rhs.  value_double ; return *this;
}

MyQVariant& MyQVariant::operator += (double val)
{
    if (value_type == MYQVAR_TYPE_DOUBLE)
    this->value_double =
    this->value_double + val; return *this;
}

MyQVariant& MyQVariant::operator -= (double val)
{
    if (value_type == MYQVAR_TYPE_DOUBLE)
    this->value_double =
    this->value_double - val; return *this;
}

MyQVariant& MyQVariant::operator *= (double val)
{
    if (value_type == MYQVAR_TYPE_DOUBLE)
    this->value_double =
    this->value_double * val; return *this;
}

MyQVariant& MyQVariant::operator /= (double val)
{
    if (value_type == MYQVAR_TYPE_DOUBLE)
    this->value_double =
    this->value_double / val; return *this;
}

MyQVariant& MyQVariant::operator = (double rhs)
{
    print_console(QString("<--22-->"));
    this->value_double = rhs;
    this->value_type = MYQVAR_TYPE_DOUBLE;
    return *this;
}

MyQVariant& MyQVariant::operator = (QString rhs)
{
    print_console(QString("<--11-->"));
    this->value_type = MYQVAR_TYPE_STRING;
    this->value_string = rhs;
    return *this;
}

MyQVariant& MyQVariant::MyQVariant::operator + (QString val)
{
    print_console(QString("<--66-->"));
    this->value_type = MYQVAR_TYPE_STRING;
    this->value_string = this->value_string + val;
    return *this;
}

MyQVariant& MyQVariant::MyQVariant::operator + (double val)
{
    this->value_double = this->value_double + val;
    return *this;
}

MyQVariant& MyQVariant::MyQVariant::operator - (double val)
{
    this->value_double = this->value_double - val;
    return *this;
}

MyQVariant& MyQVariant::MyQVariant::operator * (double val)
{
    this->value_double = this->value_double * val;
    return *this;
}

MyQVariant& MyQVariant::MyQVariant::operator / (double val)
{
    if (value_type == MYQVAR_TYPE_DOUBLE)
    this->value_double = this->value_double / val;
    return *this;
}

MyQVariant& MyQVariant::operator = (MyQVariant& rhs)
{
    if (rhs.value_type == MYQVAR_TYPE_STRING)
    rhs.value_string = this->value_string;
    return *this;
}

double operator - (double lhs, MyQVariant& rhs)
{
    rhs.value_type = MYQVAR_TYPE_DOUBLE;
    rhs.value_double -= lhs;
    return rhs.value_double;
}

double operator + (double lhs, MyQVariant& rhs)
{
    rhs.value_double += lhs;
    return rhs.value_double;
}

double operator * (double lhs, MyQVariant& rhs)
{
    rhs.value_double *= lhs;
    return rhs.value_double;
}

double operator / (double lhs, MyQVariant& rhs)
{
    rhs.value_double /= lhs;
    return rhs.value_double;
}

#endif

#endif
