#include "calendar.h"

void Date::NextDay(int n) {
    int year = this->year_;
    int month = this->month_;
    int day = this->day_ + n;

    bool is_valid_date = this->SetDate(year, month, day);
    if (!is_valid_date) {
        if (day != 0) {
            month += 1;
            day = n;
        } else {
            if (month != 1) {
                month -= 1;
                day = days_of_month[month];
                if (GetDaysInYear(year) == 366) day += 1;
            } else {
                year -= 1;
                month = 12;
                day = days_of_month[month];
            }
        }
        is_valid_date = this->SetDate(year, month, day);
        if (!is_valid_date) {
            year += 1;
            month = 1;
            day = n;
            if(!this->SetDate(year, month, day)) {
                cout << "Invalid date: ";
            }
        }
    }
}

bool Date::SetDate(int year, int month, int day) {
    bool is_yoon = GetDaysInYear(year) == 366;
    if (month == 2 && (
            (is_yoon && day > 29) || (!is_yoon && day > 28))) {
        return false;
    }

    if ((month < 1 || month > 12) || (1 > day || 31 < day)) {
        return false;
    }

    this->year_ = year;
    this->month_ = month;
    this->day_ = day;
    return true;
}


ostream &operator<<(ostream &os, const Date &c) {
    os << c.year() << '.' << c.month() << '.' << c.day() << endl;
    return os;
}

istream &operator>>(istream &is, Date &c) {
    char dot;
    int y, m, d;
    is >> y >> dot >> m >> dot >> d;
    bool is_valid_date = c.SetDate(y, m, d);
    if (!is_valid_date) {
        cout << "Invalid date: ";
        cout << y << '.' << m << '.' << d <<endl;
    } else {
        cout << c;
    }
    return is;
}
