#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H

#include <QDialog>

class QDialogButtonBox;
class QTableWidget;

class HighScoreWindow : public QDialog{
    Q_OBJECT
public:
    explicit HighScoreWindow(QWidget *parent = 0);
    ~HighScoreWindow();

private:
    QDialogButtonBox *buttonBox;
    QTableWidget *scoreTable;
    QStringList scoreTableHeader;
};
#endif // HIGHSCOREWINDOW_H
