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
#ifndef __ALL_HEADERS_H__
#define __ALL_HEADERS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <math.h>
#include <sys/types.h>
#include <errno.h>

#include "QtCore/QObject"

#include "QtWidgets/QApplication"
#include "QtWidgets/QCheckBox"
#include "QtWidgets/QWidget"
#include "QtWidgets/QDoubleSpinBox"
#include "QtWidgets/QFrame"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QLineEdit"
#include "QtWidgets/QTimeEdit"
#include "QtWidgets/QMenuBar"
#include "QtWidgets/QMessageBox"
#include "QtWidgets/QTableWidget"
#include "QtWidgets/QTableWidgetItem"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QPlainTextEdit"
#include "QtWidgets/QScrollBar"

#include "QtCore/QTranslator"
#include "QtCore/QVector"
#include "QtCore/QString"
#include "QtCore/QStringList"
#include "QtCore/QMap"

#include "QtCore/QFileInfo"
#include "QtCore/QDateTime"

#include "QtCore/QTimer"
#include "QtCore/QByteArray"
#include "QtCore/QDataStream"

#include "QtNetwork/QtNetwork"
#include "QtNetwork/QTcpSocket"

#include "QtGui/QTextCursor"


#include "QtWidgets/QAction"
#include "QtWidgets/QButtonGroup"
#include "QtWidgets/QComboBox"
#include "QtWidgets/QDockWidget"
#include "QtWidgets/QFormLayout"
#include "QtWidgets/QHBoxLayout"
#include "QtWidgets/QHeaderView"
#include "QtWidgets/QLabel"
#include "QtWidgets/QLineEdit"
#include "QtWidgets/QListView"
#include "QtWidgets/QListWidget"
#include "QtWidgets/QMainWindow"
#include "QtWidgets/QMdiArea"
#include "QtWidgets/QMenu"
#include "QtWidgets/QMenuBar"
#include "QtWidgets/QScrollArea"
#include "QtWidgets/QTabWidget"
#include "QtWidgets/QTableWidget"
#include "QtWidgets/QToolButton"
#include "QtWidgets/QTreeWidget"
#include "QtWidgets/QVBoxLayout"
#include "QtWidgets/QHBoxLayout"
#include "QtWidgets/QSplitter"
#include "QtWidgets/QFileIconProvider"

#include "QtCore/QAbstractTableModel"
#include "QtCore/QVariant"
#include "QtCore/QTranslator"
#include "QtCore/QVector"
#include "QtCore/QString"
#include "QtCore/QStringList"
#include "QtCore/QMap"
#include "QtCore/QPair"
#include "QtCore/QList"
#include "QtCore/QHash"

#include "QtCore/QFileInfo"
#include "QtCore/QDateTime"

#include "QtCore/QTimer"
#include "QtCore/QByteArray"
#include "QtCore/QDataStream"

#include "QtWidgets/QHeaderView"
#include "QtGui/QPaintEvent"
#include "QtWidgets/QStyledItemDelegate"
#include "QtWidgets/QScrollBar"

#include "QtCore/QStringListModel"
#include "QtWidgets/QListView"

#include "QtGui/QIcon"
#include "QtGui/QPixmap"
#include "QtGui/QResizeEvent"
#include "QtGui/QSyntaxHighlighter"
#include "QtGui/QTextCharFormat"
#include "QtGui/QTextLayout"

#include "QtWidgets/QGraphicsView"
#include "QtWidgets/QGraphicsEllipseItem"
#include "QtWidgets/QGraphicsItem"
#include "QtWidgets/QGraphicsRectItem"
#include "QtWidgets/QGraphicsTextItem"
#include "QtWidgets/QGraphicsSceneHoverEvent"
#include "QtWidgets/QGraphicsSceneMouseEvent"

#include "QtCore/QDate"
#include "QtCore/QTime"

#include "QtGui/QBrush"
#include "QtGui/QColor"
#include "QtGui/QPainter"
#include "QtGui/QPen"

#include "QtCore/QPointF"

#include "QtNetwork/QtNetwork"
#include "QtNetwork/QTcpSocket"


#include "boost/multi_array.hpp"
#include "boost/array.hpp"

#ifndef WIN32
# include "boost/program_options.hpp"
#endif

#include "boost/fusion/iterator/deref.hpp"
#include "boost/fusion/include/deref.hpp"

#include "boost/function/function0.hpp"

#include "boost/algorithm/string.hpp"

#include "boost/variant.hpp"
#include "boost/variant/variant_fwd.hpp"
#include "boost/variant/variant.hpp"
#include "boost/variant/recursive_variant.hpp"
#include "boost/variant/recursive_wrapper.hpp"
#include "boost/variant/apply_visitor.hpp"
#include "boost/variant/get.hpp"
#include "boost/variant/bad_visit.hpp"
#include "boost/variant/static_visitor.hpp"
#include "boost/variant/visitor_ptr.hpp"
#include "boost/tokenizer.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>

extern int double2int(double);

#endif
