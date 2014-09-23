#include "NumDays.h"

NumDays::NumDays(int hours){
    this->hours = hours;
}

NumDays::~NumDays(){}

int NumDays::getHours()const{
    int hour = 0;
    cout << "Please enter the number of work hours you would like to convert: ";
    cin >> hour;

    // Validate hours
    while (hour < 0) {
        cout << "ERROR! Negative hours input!\n";
        cout << "Please enter the number of work hours you would like to convert: ";
        cin >> hour;
    }
    return hour;
}

float NumDays::getDays()const{
    float day = static_cast<float>(hours) / 8;
    return day;
}

void NumDays::setHours(int hours){
    this->hours = hours;
}

void NumDays::setDays(float days){
    this->days = days;
}

void NumDays::displayDays()const{
    cout << hours << " hours or " << fixed
         << setprecision(2) << showpoint << days << " day(s).\n\n";
}

int NumDays::operator + (NumDays& day){
    return (hours + day.hours);
}

int NumDays::operator - (NumDays& day){
    return (hours - day.hours);
}

NumDays& NumDays::operator++(){
    ++hours;
    days = static_cast<float>(hours) / 8;
    return *this;
}

NumDays& NumDays::operator--(){
    --hours;
    days = static_cast<float>(hours) / 8;
    return *this;
}

NumDays NumDays::operator++(int){
    NumDays cDay(hours);
    ++(*this);
    days = static_cast<float>(hours) / 8;
    return cDay;
}

NumDays NumDays::operator--(int){
    NumDays cDay(hours);
    --(*this);
    days = static_cast<float>(hours) / 8;
    return cDay;
}

