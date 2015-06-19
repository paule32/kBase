#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T23:48:38
#
#-------------------------------------------------

QT       += core gui widgets help

TARGET = dbase
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    designerform.cpp \
    childwindow.cpp \
    editorform.cpp \
    childwindoweditor.cpp \
    codeeditor.cpp \
    options.cc \
    propertyform.cpp \
    childwindowproperty.cpp \
    childwindowcomponents.cpp \
    componentsform.cpp \
    designergraphicsview.cpp \
    designeritem.cpp \
    designerresizer.cpp

HEADERS  += mainwindow.h \
    ui_mainwindow.h \
    designerform.h \
    ui_designerform.h \
    editorform.h \
    childwindow.h \
    childwindoweditor.h \
    codeeditor.h \
    pch.h \
    childwindowproperty.h \
    propertyform.h \
    ui_propertyform.h \
    childwindowcomponents.h \
    componentsform.h \
    ui_componentsform.h \
    designergraphicsview.h \
    designeritem.h \
    designerresizer.h

FORMS    += mainwindow.ui \
    designerform.ui \
    editorform.ui \
    propertyform.ui \
    componentsform.ui

FLEXSOURCES  = pcode.l
BISONSOURCES = pcode.y

win32:flex.commands = flex.exe -i pcode.l $$escape_expand(\\n\\t) $(COPY) lex.yy.c lex.yy.cpp
flex.input = FLEXSOURCES
flex.output = lex.yy.cpp
flex.variable_out = SOURCES
flex.depends = y.tab.h
flex.name = flex
QMAKE_EXTRA_COMPILERS += flex

win32:bison.commands = bison.exe -d -t -y pcode.y $$escape_expand(\\n\\t) $(COPY) y.tab.c y.tab.cpp
bison.input = BISONSOURCES
bison.output = y.tab.cpp
bison.variable_out = SOURCES
bison.name = bison
QMAKE_EXTRA_COMPILERS += bison

bisonheader.commands = @true
bisonheader.input = BISONSOURCES
bisonheader.output = y.tab.h
bisonheader.variable_out = HEADERS
bisonheader.name = bison header
bisonheader.depends = y.tab.cpp
QMAKE_EXTRA_COMPILERS += bisonheader

QMAKE_EXTRA_TARGETS += helper flex bison

QMAKE_CXXFLAGS += \
        -Wno-unused-parameter \
        -Wno-unused-local-typedefs \
        -Wno-unused-variable \
        -Wno-unused-function \
        -Wno-write-strings \
        -Wno-extra \
        -frtti -fexceptions -fpermissive -std=gnu++11 \
	\
	-DQT_COMPILING_QSTRING_COMPAT_CPP

OTHER_FILES += \
        $$BISONSOURCES \
        $$FLEXSOURCES

win32:LIBS += -L. -lkbase -lhelper -ly -lfl
