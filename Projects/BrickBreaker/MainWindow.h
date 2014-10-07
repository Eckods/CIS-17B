#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QLabel;

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void startButtonClicked();
    void viewHighScoresButtonClicked();
    void createMenus();
    void createActions();
    void createStatusBar();
    void backToMainMenu();
    void aboutGame();

private:
    QLabel *titleName;
    QPushButton *start;
    QPushButton *viewHighScores;
    QPushButton *quit;
    QMenu *gameMenu;
    QMenu *aboutMenu;
    QAction *returnAct;
    QAction *exitAct;
    QAction *aboutAct;
    QWidget *menuWidget;
};
#endif // MAINWINDOW_H
