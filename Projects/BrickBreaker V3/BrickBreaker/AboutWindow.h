#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

class QDialogButtonBox;
class QLabel;

class AboutWindow : public QDialog{
public:
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();

private:
    QDialogButtonBox *buttonBox;
    QLabel *info;
};
#endif // ABOUTWINDOW_H
