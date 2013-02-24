#--------------------------------------------
# Makefile - Installationsscript für test.prg
# (c) 2013 J. Kallup
#--------------------------------------------
LAUFWERK_PFAD = I:/kbase-bin/5

CC  = $(LAUFWERK_PFAD)/mingw/bin/g++ -mwindows
MOC = $(LAUFWERK_PFAD)/Qt/bin/moc.exe

DEFINES  = -DUNICODE -DQT_LARGEFILE_SUPPORT -DQT_DLL -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_HAVE_MMX -DQT_HAVE_3DNOW -DQT_HAVE_SSE -DQT_HAVE_MMXEXT -DQT_HAVE_SSE2 -DQT_THREAD_SUPPORT -DQT_NEEDS_QMAIN
INCLUDES = \
	-I"$(LAUFWERK_PFAD)/Qt/include/Qt" \
	-I"$(LAUFWERK_PFAD)/Qt/include/QtCore" \
	-I"$(LAUFWERK_PFAD)/Qt/include/QtNetwork" \
	-I"$(LAUFWERK_PFAD)/Qt/include/QtGui" \
	-I"$(LAUFWERK_PFAD)/Qt/include/" \
	-I"$(LAUFWERK_PFAD)/Qt/include/ActiveQt"
LIBS  = \
	-L"$(LAUFWERK_PFAD)/Qt/lib" -lmingw32 -lqtmain -lQtGui4 -lQtNetwork4 -lQtCore4

all: first.exe

first.exe: first.cc first.h session.h session.cc
	$(CC) $(DEFINES) $(INCLUDES) -c first.cc -o first.o 2> m1
	$(CC) $(DEFINES) $(INCLUDES) -c MyDebugFuncs.cc -o MyDebugFuncs.o 2> m1
	$(MOC) $(DEFINES) $(INCLUDES) -D__GNUC__ -DWIN32 -D__MOC_RUN__ first.h -o moc_first.cc
	$(MOC) $(DEFINES) $(INCLUDES) -D__GNUC__ -DWIN32 -D__MOC_RUN__ session.h -o moc_session.cc
	$(MOC) $(DEFINES) $(INCLUDES) -D__GNUC__ -DWIN32 -D__MOC_RUN__ MyQLineEdit.h -o moc_qlineedit.cc
	$(MOC) $(DEFINES) $(INCLUDES) -D__GNUC__ -DWIN32 -D__MOC_RUN__ MyQPushButton.h -o moc_qpushbutton.cc
	$(CC) $(DEFINES) $(INCLUDES) -o moc_first.o   -c moc_first.cc 2> m1
	$(CC) $(DEFINES) $(INCLUDES) -o moc_session.o -c moc_session.cc
	$(CC) $(DEFINES) $(INCLUDES) -o moc_qlineedit.o -c moc_qlineedit.cc
	$(CC) $(DEFINES) $(INCLUDES) -o moc_qpushbutton.o -c moc_qpushbutton.cc
	$(CC) $(DEFINES) $(INCLUDES) -c session.cc -o session.o
	$(CC) -o first.exe first.o session.o \
	MyDebugFuncs.o \
	moc_first.o \
	moc_session.o \
	moc_qlineedit.o \
	moc_qpushbutton.o \
	$(LIBS)
