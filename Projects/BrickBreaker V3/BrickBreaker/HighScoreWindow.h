#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H

#include <QDialog>

class QDialogButtonBox;
class QLineEdit;
class QLabel;
class QTextBrowser;

class HighScoreWindow : public QDialog{
    Q_OBJECT
public:
    explicit HighScoreWindow(QWidget *parent = 0);
    ~HighScoreWindow();

private:
    QDialogButtonBox *buttonBox;
    QLineEdit *nameEntry;
    QLabel *nameLabel;
    QTextBrowser *scoreTable;
};
#endif // HIGHSCOREWINDOW_H
