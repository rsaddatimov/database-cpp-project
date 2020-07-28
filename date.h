#pragma once

#include <iostream>

using namespace std;

class Date {
public:
    explicit Date(int year, int month, int day);
    
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

    bool operator<(cons Date& o);
    
private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& in_stream);

ostream& operator<<(ostream& out_stream, const Date& date);