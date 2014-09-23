#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#ifndef PAYROLL_H
#define PAYROLL_H

// Global Constants
const int NUM_EMP = 7;

class Payroll{
private:
    float payRate;
    float hours;
    float totalPay;
public:
    Payroll();
    ~Payroll();
    void setHours(int);
    void setPayRate(float);
    void calcPay();
    void displayEmployees(int)const;
};
#endif // PAYROLL_H
