#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    QWidget *menuWidget;
    QWidget *gameWidget;
    QStackedWidget *stack;
    QGroupBox *scoreGroupBox;
};
#endif // MAINWINDOW_H
