#include "Payroll.h"

Payroll::Payroll()
{
    payRate = 0;
    hours = 0;
    totalPay = 0;
}

Payroll::~Payroll(){}

void Payroll::setHours(int hours){
    this->hours = hours;
}

void Payroll::setPayRate(float payRate){
    this->payRate = payRate;
}
void Payroll::calcPay(){
    totalPay = hours * payRate;
}

void Payroll::displayEmployees(int i)const{
            cout << left << setw(10) << i+1 << right << setw(10) << fixed << setprecision(2)
                      << showpoint << "$ " << totalPay << endl;
            cout << "============================" << endl;
}


