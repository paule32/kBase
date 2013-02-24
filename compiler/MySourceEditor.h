#ifndef MYSOURCEEDITOR_H
#define MYSOURCEEDITOR_H

#include <QtGui>
#include <QEvent>
#include <QMainWindow>
#include <QSyntaxHighlighter>
#include <QHash>
#include <QTextCharFormat>
#include <QTableView>
#include <QTreeView>
#include <QListView>
#include <QSplitter>
#include <QHeaderView>
#include <QAbstractItemModel>
#include <QFileIconProvider>
#include <QIcon>
#include <QVector>
#include <QPixmap>
#include <QAbstractTableModel>
#include <QProcess>
#include <QPair>
#include <QList>

class Highlighter : public QSyntaxHighlighter
{
     Q_OBJECT

 public:
     Highlighter(QTextDocument *parent = 0);

 protected:
     void highlightBlock(const QString &text);

 private:
     struct HighlightingRule
     {
         QRegExp pattern;
         QTextCharFormat format;
     };
     QVector<HighlightingRule> highlightingRules;

     QRegExp commentStartExpression;
     QRegExp commentEndExpression;

     QTextCharFormat keywordFormat;
     QTextCharFormat classFormat;
     QTextCharFormat singleLineCommentFormat;
     QTextCharFormat multiLineCommentFormat;
     QTextCharFormat quotationFormat;
     QTextCharFormat functionFormat;
 };

class SourceEdit: public QTextEdit
{
  Q_OBJECT
public:
  SourceEdit(QWidget *parent);
  void setCompleter(QCompleter *c);
  QCompleter *completer() const;
  void insertTextByFile(QString file);
protected:
  bool eventFilter(QObject *obj, QEvent *ev);
  bool event(QEvent *e);
  void dropEvent(QDropEvent *event);
  void keyPressEvent(QKeyEvent *e);
  void focusInEvent(QFocusEvent *e);
private slots:
  void insertCompletion(const QString &completion);
private:
  QString textUnderCursor() const;
private:
  QCompleter *c;
};


#endif // MYSOURCEEDITOR_H
