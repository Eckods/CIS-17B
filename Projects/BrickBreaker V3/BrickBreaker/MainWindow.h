#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

class QPushButton;
class QLabel;
class QStackedWidget;
class QGroupBox;

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void startButtonClicked();
    void viewHighScoresButtonClicked();
    void backToMainMenu();
    void aboutGame();
    void takeNotes();
    void viewGlobalScores();

private:
    void createMainWindowMenu();
    void createGameWidget();
    void createMenus();
    void createActions();
    void createStatusBar();

    QLabel *titleName;
    QLabel *scoreCount;
    QPushButton *start;
    QPushButton *viewHighScores;
    QPushButton *quit;
    QPushButton *resetGame;
    QMenu *gameMenu;
    QMenu *aboutMenu;
    QMenu *miscMenu;
    QAction *returnAct;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *noteAct;
    QAction *globalScoresAct;
    QWidget *menuWidget;
    QWidget *gameWidget;
    QStackedWidget *stack;
    QGroupBox *scoreGroupBox;
};
#endif // MAINWINDOW_H
