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
*/
#ifndef __MYCLASSHANDLER__
#define __MYCLASSHANDLER__

#include "pch.h"

namespace dbase {
template <typename T1>
class RegisterClass {
public:
    RegisterClass(double val=0.00) { Tag = val; }
    double get() { return 42.21; }

    variant<double> Tag;
};

#ifdef __MAIN_RUN__
RegisterClass<double> root_double = 0.00;
#else
extern RegisterClass<double> root_double;
#endif

struct MyClassMapping
{
    std::string ClassName;
    RegisterClass<double> Create;

    operator std::pair<std::string, RegisterClass<double> > () const {
	return make_pair( ClassName, Create);
    }
};

#ifdef __MAIN_RUN__
struct MyClassMapping mapping[] = {
    { "MyBaseObject" , root_double.get() }
};
#endif

}
#endif