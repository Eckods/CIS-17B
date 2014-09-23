/* Steve Sanchez
 * September 17th, 2014
 * Purpose: Ch 13 Review Problem 12- Payroll
 */
#include "Payroll.h"

int main()
{
    int hours = 0;
    float payRate = 0;

    Payroll Employees[NUM_EMP];

    for(int i = 0; i < NUM_EMP; i++)
    {
        // Get Employee Hours Input
        cout << "Please enter Employee #" << i+1 << "'s the number of hours worked: ";
        cin >> hours;

        // Validate Hours & Set
        while(hours > 60 || hours < 0){
            cout << "Error! Number of hours exceeded maximum!" << endl;
            cout << "Please enter Employee #" << i+1 << "'s the number of hours worked: ";
            cin >> hours;
        }
        Employees[i].setHours(hours);

        // Get Employee Pay Rate
        cout << "Please enter Employee #" << i+1 << "'s pay rate: ";
        cin >> payRate;

        // Validate Pay Rate & Set
        while(payRate > 30 || payRate < 0){
            cout << "Error! Pay rate exceeded maximum!" << endl;
            cout << "Please enter Employee #" << i+1 << "'s pay rate: ";
            cin >> payRate;
        }
        Employees[i].setPayRate(payRate);
        Employees[i].calcPay();
        cout << endl;
    }
    // Display each Employee's total pay
    cout << endl << left << setw(15) << "Employee #" << "\t" << "Gross Wages" << endl;
        cout << "============================" << endl;
    for(int i = 0; i < NUM_EMP; i++){
        Employees[i].displayEmployees(i);
    }
    return 0;
}
