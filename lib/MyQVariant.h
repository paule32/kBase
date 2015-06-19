/*
   (c) Copyright 2013-2014  Kallup Software.
   All rights reserved.

   Written by Jens Kallup <jkallup@web.de>,

   This file is subject to the terms and conditions of the MIT License:

   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without restriction,
   including without limitation the rights to use, copy, modify, merge,
   publish, distribute, sublicense, and/or sell copies of the Software,
   and to permit persons to whom the Software is furnished to do so,
   subject to the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

   Credits to code snippet(s) freenode.irc:
   ----------------------------------------
   * jesypa
   * NinjaPenguin
*/
#ifndef __MYQVARIANT_H__
#define __MYQVARIANT_H__

#include "pch.h"

using namespace std;
using namespace boost;

extern void print_console(double);

//extern int  my_strlen (MyQVariant);

extern QString my_date_now(void);
extern QString my_time_now(void);

extern void my_set_time   (QString);

extern void msgbox(QString tstr, QString mstr);

extern void console_get_line(void);

class MyQVariant;

extern void print_console(MyQVariant);
extern void print_console(QString);
extern void print_console(std::string);
extern void print_console(char*);
extern void print_console(double);

#define MYQVAR_TYPE_DOUBLE 1
#define MYQVAR_TYPE_STRING 2

typedef boost::variant<double, std::string, QString> my_types;

class MyQVariant {
public:
    using variant = boost::variant<double, std::string, QString>;
    variant data;

    struct invalid_conversion_helper : boost::static_visitor<MyQVariant> {
        template<typename P>
        MyQVariant operator()(P&&) const {
            throw std::runtime_error{"invalid conversion"};
        }

        template<typename P1, typename P2>
        MyQVariant operator()(P1&&, P2&&) const {
            throw std::runtime_error{"invalid conversion"};
        }
    };


    struct print_visitor : boost::static_visitor<my_types>
    {
        std::string& os;
        double value;

	print_visitor(std::string& ps) : os(ps), value(0.00) {}
	print_visitor(double val) : value(val) {}
	print_visitor(QString s) {
	    os += s.toStdString();
	}

    	my_types operator()(std::string op) const {
            os += std::string(op);
    	}
    	my_types operator()(QString op) const {
            os = os + op.toStdString();
    	}
    	my_types operator()(double op) const {
            os = value + double(op);
    	}
    };

public:
    MyQVariant(void) { }
    MyQVariant(double i) : data(i) {}
    MyQVariant(std::string s) : data(std::move(s)) {}
    MyQVariant(QString s) : data(std::move(s.toStdString())) {}

    friend MyQVariant operator + (MyQVariant const& lhs, MyQVariant const& rhs) {
        struct add_visitor : invalid_conversion_helper {
            using invalid_conversion_helper::operator();

            MyQVariant operator()(double x, double y) const {
                return x + y;
            }

            MyQVariant operator()(double x, std::string const& y) const {
                return std::to_string(x) + y;
            }

            MyQVariant operator()(std::string const& x, double y) const {
		QString str = x.c_str();
		double  val = str.toDouble();
		double  res = val + y;
			str = QString("%1").arg(res);
                return  str.toStdString();
            }

            MyQVariant operator()(std::string const& x, std::string const& y) const {
                return x + y;
            }
	    MyQVariant operator()(QString const& x, QString const& y) const {
		return x + y;
	    }
	    MyQVariant operator()(QString const& x, double v) {
		double v1 = v;
		double v2 = x.toDouble();
		return MyQVariant(v1 + v2);
	    }
        };
        return boost::apply_visitor(add_visitor{}, lhs.data, rhs.data);
    }

    friend MyQVariant operator-(MyQVariant const& lhs, MyQVariant const& rhs) {
        struct sub_visitor : invalid_conversion_helper {
            using invalid_conversion_helper::operator();

            MyQVariant operator()(double x, double y) const {
                return x - y;
            }
        };
        return boost::apply_visitor(sub_visitor{}, lhs.data, rhs.data);
    }

    friend MyQVariant operator*(MyQVariant const& lhs, MyQVariant const& rhs) {
        struct mul_visitor : invalid_conversion_helper {
            using invalid_conversion_helper::operator();

            MyQVariant operator()(double x, double y) const {
                return x * y;
            }
        };
        return boost::apply_visitor(mul_visitor{}, lhs.data, rhs.data);
    }


    friend std::string& operator<<(std::string ps, MyQVariant const& wv) {
        boost::apply_visitor(print_visitor(ps), wv.data);
        return ps;
    }
    friend double operator<<(double ps, MyQVariant const& wv) {
	boost::apply_visitor(print_visitor(ps), wv.data);
	return ps;
    }
    friend QString operator<<(QString ps, MyQVariant const& wv) {
	boost::apply_visitor(print_visitor(ps), wv.data);
	return ps;
    }

    std::string toUpper(void)
    {
	MyQVariant& wv = *this;
	std::string value = boost::get<std::string>(wv.data);
	QString str = QString(value.c_str());
	return str.toUpper().toStdString();
    }
};

extern double floor(MyQVariant&);

#endif
