#include "pch.h"

int double2int(double val)
{
    return val<0?val=.5:val+.5;
}

QString string_format(QString str, double p1, double p2)
{
    int s = floor(p1);
    int e = floor(p2);

    return str.mid(s-1,e+1);
}

