#include "date.h"

#include <tuple>

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

Date ParseDate(istream& in_stream) {
    int year, month, day;

    in_stream >> year;
    in_stream.ignore(1);

    in_stream >> month;
    in_stream.ignore(1);

    in_stream >> day;

    return Date(year, month, day);
}

ostream& operator<<(ostream& out_stream, const Date& date) {
    out_stream << date.GetYear()  << '-'
               << date.GetMonth() << '-'
               << date.GetDay();

    return out_stream;
}

bool Date::operator<(const Date& o) const { return tie(year, month, day) < tie(o.year, o.month, o.day); }
bool Date::operator<=(const Date& o) const { return tie(year, month, day) <= tie(o.year, o.month, o.day); }
bool Date::operator>(const Date& o) const { return tie(year, month, day) > tie(o.year, o.month, o.day); }
bool Date::operator>=(const Date& o) const { return tie(year, month, day) >= tie(o.year, o.month, o.day); }
bool Date::operator==(const Date& o) const { return tie(year, month, day) == tie(o.year, o.month, o.day); }
bool Date::operator!=(const Date& o) const { return tie(year, month, day) != tie(o.year, o.month, o.day); }