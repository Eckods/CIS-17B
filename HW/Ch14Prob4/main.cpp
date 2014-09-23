/* Steve Sanchez
 * September 17th, 2014
 * Purpose: Ch 14 Review Problem 04- NumDays Class
 */
#include "NumDays.h"
#include <cmath>

int main()
{
    int workHours = 0;
    int workHours2 = 0;
    int hoursTogether = 0;
    int hoursDifference = 0;
    float workDay = 0;
    float workDay2 = 0;

    NumDays worker(workHours);
    NumDays worker2(workHours2);

    // Obtain number of hours & set
    workHours = worker.getHours();
    worker.setHours(workHours);

    workHours2 = worker2.getHours();
    worker2.setHours(workHours2);

    // Obtain number of days & set
    workDay = worker.getDays();
    worker.setDays(workDay);

    workDay2 = worker2.getDays();
    worker2.setDays(workDay2);

    // Display the hours to day conversion
    cout << "\nThe first worker worked ";
    worker.displayDays();

    cout << "The second worker worked ";
    worker2.displayDays();

    // Add the workers hours together
    hoursTogether = worker + worker2;
    cout << "Together they worked " << hoursTogether << " hours.\n\n";

    // Subtract the workers hours
    hoursDifference = worker - worker2;
    cout << "The difference between their work is " << abs(hoursDifference) << " hours.\n\n";

    // Increment workers hours
    worker++; // Postfix
    cout << "After incrementation the first worker worked ";
    worker.displayDays();
    ++worker; // Prefix
    cout << "After incrementation the first worker worked ";
    worker.displayDays();

    // Decrement workers hours
    --worker2; // Prefix
    cout << "After decrementation the second worker worked ";
    worker2.displayDays();
    worker2--; // Postfix
    cout << "After decrementation the second worker worked ";
    worker2.displayDays();

    return 0;
}
