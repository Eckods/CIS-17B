#include "NoteWindow.h"
#include <QtGui>

NoteWindow::NoteWindow(QWidget *parent)
    :QDialog(parent){
    // Creates the Note window label
    topLabel = new QLabel(tr("Write down notes here:"));
    topLabel->setStyleSheet("QLabel{color: white}");

    // Sets up a box to accept user input for note-taking
    noteBox = new QTextEdit;
    noteBox->setFixedSize(350,176);

    // Sets up a button box with Save As and Cancel buttons
    QPushButton *saveAsButton = new QPushButton(tr("Save As.."));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Cancel);
    buttonBox->addButton(saveAsButton, QDialogButtonBox::AcceptRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(saveAs()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Creates the vertical layout for the Note dialog box
    QVBoxLayout *noteLayout = new QVBoxLayout;

    noteLayout->addWidget(topLabel);
    noteLayout->addWidget(noteBox, 0, Qt::AlignHCenter);
    noteLayout->addWidget(buttonBox);
    setLayout(noteLayout);

    // Sets the title & size of the Note window
    setWindowTitle(tr("Notes"));
    setFixedSize(400, 250);
}

NoteWindow::~NoteWindow(){}

bool NoteWindow::saveAs(){
    // Brings up a dialog box to save Text document & accepts user input for the file name
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),QDir::homePath(),tr("Text file (*.txt)"));

    // If empty, returns nothing
    if (fileName.isEmpty()){
        return false;
    }

    // Calls the saveFile function and passes the fileName user input
        return saveFile(fileName);
}

bool NoteWindow::saveFile(const QString &fileName){
    // Creates a QFile for storage / output with the file name passed
    QFile file(fileName);

    // If the file cannot be created, displays an error message
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::information(0, "Error", file.errorString());
        return false;
    }

    // Reads in the text in the QFile and writes it to a text document
    QTextStream out(&file);
    out << noteBox->toPlainText();

    return true;
}
