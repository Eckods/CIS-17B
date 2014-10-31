#include "AboutWindow.h"
#include <QtGui>

AboutWindow::AboutWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up the label for the About information
    info = new QLabel(tr("<b>Brick Break</b> was developed using Qt and features a start menu,"
                          " menu bar, high score screen, and a simplistic brick breaking experience."));
    info->setStyleSheet("QLabel{color: white}");
    info->setWordWrap(true);

    // Creates a button box with only an Ok button
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));

    // Creates the layout for the About window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(info, 2, Qt::AlignVCenter);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    // Sets the title of the About window
    setWindowTitle(tr("About Brick Break"));
    setFixedSize(300,150);
}

AboutWindow::~AboutWindow(){}
