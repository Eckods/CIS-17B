#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QDialog>
#include <QString>

class QDialogButtonBox;
class QLabel;
class QTextEdit;
class QLineEdit;

class NoteWindow: public QDialog{
    Q_OBJECT

public:
    explicit NoteWindow(QWidget *parent = 0);
    ~NoteWindow();

private slots:
    bool saveAs();
    void openText();

private:
    bool saveFile(const QString &fileName);

    QDialogButtonBox *buttonBox;
    QLabel *topLabel;
    QTextEdit *noteBox;
};

#endif // NOTEWINDOW_H

