/* Steve Sanchez
 * September 17th, 2014
 * Purpose: Ch 15 Review Problem 13- Pure Abstract Base Class Project
 */
#include "Circle.h"
#include "Rectangle.h"

int main(){
    float radius;
    int centerX, centerY, width, length;

    cout << "Calculating the Area of a Rectangle\n"
         << "===================================\n";

    // Ask to input length and width of Rectangle
    cout << "Enter the length: ";
    cin >> length;
    while (length < 0){
        cout << "ERROR! Please enter a positve length: ";
        cin >> length;
    }
    cout << "Enter the width: ";
    cin >> width;
    while (width < 0){
        cout << "ERROR! Please enter a positve length: ";
        cin >> width;
    }
    // Instantiate the Rectangle and pass width, length
    Rectangle rectangle(width, length);

    // Display the properties of the Rectangle
    cout << "\nThe Rectangle has a width of " << rectangle.getWidth() << " and a length of " << rectangle.getLength() << ".\n";
    cout << "The Rectangle's area is " << rectangle.getArea() << ".\n\n";


    cout << "Calculating the Area of a Circle\n"
         << "==================================\n";

    // Ask user to input the center coordinates and radius
    cout << "Enter the X coordinate: ";
    cin >> centerX;
    cout << "Enter the Y coordinate: ";
    cin >> centerY;
    cout << "Enter the radius: ";
    cin >> radius;

    // Instantiate the Circle and pass centerX, Y, and radius
    Circle circle(centerX, centerY, radius);

    // Display the properties of the Rectangle
    cout << "\nThe Circle has a center at (" << circle.getCenterX() << " , " << circle.getCenterY()
         << ") and a radius of " << radius << ".\n";
    cout << "The Circle's area is "  << circle.getArea() << ".\n\n";

    return 0;
}
