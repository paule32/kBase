#include <windows.h>
#include <Qt>
#include "MySourceEditor.h"

void check_compile(SourceEdit *edit, int mode);

Highlighter::Highlighter(QTextDocument *parent): QSyntaxHighlighter(parent)
{
     HighlightingRule rule;

     keywordFormat.setForeground(Qt::darkBlue);
     keywordFormat.setFontWeight(QFont::Bold);
     QStringList keywordPatterns;
     keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
                     << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                     << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                     << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                     << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                     << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                     << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                     << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                     << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                     << "\\bvoid\\b" << "\\bvolatile\\b";
     foreach (const QString &pattern, keywordPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = keywordFormat;
         highlightingRules.append(rule);
     }

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::darkMagenta);
     rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
     rule.format = classFormat;
     highlightingRules.append(rule);

     singleLineCommentFormat.setForeground(Qt::red);
     rule.pattern = QRegExp("//[^\n]*");
     rule.format = singleLineCommentFormat;
     highlightingRules.append(rule);

     multiLineCommentFormat.setForeground(Qt::red);

     quotationFormat.setForeground(Qt::darkGreen);
     rule.pattern = QRegExp("\".*\"");
     rule.format = quotationFormat;
     highlightingRules.append(rule);

     functionFormat.setFontItalic(true);
     functionFormat.setForeground(Qt::blue);
     rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
     rule.format = functionFormat;
     highlightingRules.append(rule);

     commentStartExpression = QRegExp("/\\*");
     commentEndExpression = QRegExp("\\*/");
 }

void Highlighter::highlightBlock(const QString &text)
{
     foreach (const HighlightingRule &rule, highlightingRules) {
         QRegExp expression(rule.pattern);
         int index = expression.indexIn(text);
         while (index >= 0) {
             int length = expression.matchedLength();
             setFormat(index, length, rule.format);
             index = expression.indexIn(text, index + length);
         }
     }
     setCurrentBlockState(0);

     int startIndex = 0;
     if (previousBlockState() != 1)
         startIndex = commentStartExpression.indexIn(text);

     while (startIndex >= 0) {
         int endIndex = commentEndExpression.indexIn(text, startIndex);
         int commentLength;
         if (endIndex == -1) {
             setCurrentBlockState(1);
             commentLength = text.length() - startIndex;
         } else {
             commentLength = endIndex - startIndex

                             + commentEndExpression.matchedLength();
         }
         setFormat(startIndex, commentLength, multiLineCommentFormat);
         startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
     }
}


SourceEdit::SourceEdit(QWidget *parent)
  : QTextEdit(parent)
{
  c = new QCompleter();
  setViewportMargins(50, 0, 0, 0);

  installEventFilter(this);

  connect(verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(update()));
  connect(this, SIGNAL(textChanged()), this, SLOT(update()));
}

bool SourceEdit::event(QEvent *e)
{
  QTextEdit::event(e);

  if (e->type() == QEvent::Paint)
  {
    QPainter p(this);
    p.fillRect(0, 0, 50, height(), QColor(255, 255, 192));

    int contentsY = verticalScrollBar()->value();
    qreal pageBottom = contentsY+viewport()->height();
    int m_lineNumber(1);
    const QFontMetrics fm=fontMetrics();
    const int ascent = fontMetrics().ascent() +1;

    for (QTextBlock block = document()->begin(); block.isValid(); block=block.next(), m_lineNumber++)
    {
      QTextLayout *layout = block.layout();
      const QRectF boundingRect = layout->boundingRect();
      QPointF position = layout->position();
      if ( position.y() +boundingRect.height() < contentsY ) {
        continue;
      }
      if ( position.y() > pageBottom ) {
        break;
      }
      const QString txt = QString::number(m_lineNumber);
      p.drawText(50-fm.width(txt)-2, qRound(position.y())-contentsY+ascent, txt);
      }
    }

    return true;
}


void SourceEdit::setCompleter(QCompleter *completer)
 {
     if (c)
         QObject::disconnect(c, 0, this, 0);

     c = completer;

     if (!c)
         return;

     c->setWidget(this);
     c->setCompletionMode(QCompleter::PopupCompletion);
     c->setCaseSensitivity(Qt::CaseInsensitive);
     QObject::connect(c, SIGNAL(activated(QString)),
                      this, SLOT(insertCompletion(QString)));
 }

 QCompleter *SourceEdit::completer() const
 {
     return c;
 }

 void SourceEdit::insertCompletion(const QString& completion)
 {
     if (c->widget() != this)
         return;
     QTextCursor tc = textCursor();
     int extra = completion.length() - c->completionPrefix().length();
     tc.movePosition(QTextCursor::Left);
     tc.movePosition(QTextCursor::EndOfWord);
     tc.insertText(completion.right(extra));
     setTextCursor(tc);
 }

 QString SourceEdit::textUnderCursor() const
 {
     QTextCursor tc = textCursor();
     tc.select(QTextCursor::WordUnderCursor);
     return tc.selectedText();
 }

 void SourceEdit::focusInEvent(QFocusEvent *e)
 {
     if (c)
         c->setWidget(this);
     QTextEdit::focusInEvent(e);
 }

bool SourceEdit::eventFilter(QObject *obj, QEvent *ev)
{
    if (obj == this) {
        if (ev->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(ev);
            if (keyEvent->modifiers() & Qt::MetaModifier)
            {
                if (keyEvent->key() == Qt::Key_S)
                {
                    QMessageBox* msgBox = new QMessageBox();
                    msgBox->setWindowTitle("Programm-Info");
                    msgBox->setText(QString("seq: %1  3333").arg(2));
                    msgBox->exec();
                   return true;
                }
            }
        } else {
            return false;
        }
    } else {
        // pass the event on to the parent class
        return SourceEdit::eventFilter(obj, ev);
    }
}

void SourceEdit::keyPressEvent(QKeyEvent *e)
{
    if (e->modifiers() & Qt::ControlModifier)
    {
        if (e->key() == Qt::Key_S)
        {
            //check_compile(this,1);
            QMessageBox* msgBox = new QMessageBox();
            msgBox->setWindowTitle("Programm-Info");
            msgBox->setText(QString("seq: %1").arg(2));
            msgBox->exec();
            return;
        }
    }
     if (c && c->popup()->isVisible()) {
         // The following keys are forwarded by the completer to the widget
        switch (e->key()) {
        case Qt::Key_Enter:
        case Qt::Key_Return:
        case Qt::Key_Escape:
        case Qt::Key_Tab:
        case Qt::Key_Backtab:
             e->ignore();
             return; // let the completer do default behavior
        default:
            break;
        }
     }

     bool isShortcut = ((e->modifiers() & Qt::ControlModifier) && e->key() == Qt::Key_E); // CTRL+E
     if (!c || !isShortcut) // do not process the shortcut when we have a completer
         QTextEdit::keyPressEvent(e);

     const bool ctrlOrShift = e->modifiers() & (Qt::ControlModifier | Qt::ShiftModifier);
     if (!c || (ctrlOrShift && e->text().isEmpty()))
         return;

     static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // end of word
     bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
     QString completionPrefix = textUnderCursor();

     if (!isShortcut && (hasModifier || e->text().isEmpty()|| completionPrefix.length() < 3
                       || eow.contains(e->text().right(1)))) {
         c->popup()->hide();
         return;
     }

     if (completionPrefix != c->completionPrefix()) {
         c->setCompletionPrefix(completionPrefix);
         c->popup()->setCurrentIndex(c->completionModel()->index(0, 0));
     }
     QRect cr = cursorRect();
     cr.setWidth(c->popup()->sizeHintForColumn(0)
                 + c->popup()->verticalScrollBar()->sizeHint().width());
     c->complete(cr); // popup it up!
}


void SourceEdit::dropEvent(QDropEvent *event)
{
    event->ignore();
}

void SourceEdit::insertTextByFile(QString file)
{
    QFile f(file);
    if (!f.exists())
    {
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setWindowTitle("Fehler");
        msgBox->setText(QString("Datei \"%1\" konnte nicht geöffnet werden.").arg(file));
        msgBox->exec();
        return;
    }

    f.open(QFile::ReadOnly | QFile::Text);

    document()->clear();
    while (!f.atEnd())
    {
        QByteArray line = f.readLine();
        insertPlainText(line);
    }

    f.close();
    setDocumentTitle(QString("Editor: %1").arg(file));
}

extern void prepare_compile(const char *argv);
void check_compile(SourceEdit *edit, int mode)
{
    QString fileName = edit->documentTitle();
    fileName.replace("Editor: ","");

    if (edit->document()->isModified())
    {
        FILE *out = fopen(fileName.toStdString().c_str(),"w");
        if (!out)
        {
            QMessageBox* msgBox = new QMessageBox();
            msgBox->setWindowTitle("Systemfehler");
            msgBox->setText(QString(
                            "Datei: \"%1\" kann nicht gespeichert werden.\n"
                            "Eventuell von anderen Programm(en) verwendet?"
                            ).arg(fileName)   );
            msgBox->exec();
            return;
        }
        fprintf(out,"%s",edit->document()->toPlainText().toStdString().c_str());
        fclose(out);
    }

    if (mode == 0)
    prepare_compile(fileName.toStdString().c_str());
}
