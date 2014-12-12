#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream outFile;
    string instructions = "<center> <b>Controls:</b> </center>\n"
            "<p align = 'left'> &#x25C0; , &#x25B6; : <i>Move paddle</i> </p>"
            "<p align = 'left'> P: <i>Pause game</i> </p>"
            "<p align = 'left'> R: <i>Reset game</i> </p>"
            "<p align = 'left'> Space: <i>Start game</i> </p>";

    //string instructions = "Press <b>Space</b> to start the game. Move the paddle using the <b>Left</b> "
    //                       "and <b>Right Arrow keys</b> on the keyboard. Upon game over or entry "
    //                       "of high score, press <b>Space</b> again to reset the game or click the reset button.";

    // Creates the output file
    outFile.open("C:\\instructions.txt");

    // Validate that the files open
    if (outFile.fail()) {
        cout << "ERROR! Could not open file! Program closing..." << endl;
        exit(1);
    }

    // Writes what is stored in the instructions string to output
    outFile << instructions << endl;

    cout << endl << "The instructions.txt has been written"
         << endl << "Program closing..." << endl << endl;

    // Closes the file
    outFile.close();

    return 0;
}
