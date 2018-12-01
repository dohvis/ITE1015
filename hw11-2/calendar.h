#include <iostream>

using namespace std;

const int days_of_month[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
public:
    Date() {

    };

    Date(int year, int month, int day) : year_(year), month_(month), day_(day) {

    };

    void NextDay(int n = 1);

    bool SetDate(int year, int month, int day);

    int year() const {
        return this->year_;
    };

    int month() const {
        return this->month_;
    };

    int day() const {
        return this->day_;
    };

private:
// 윤년을 판단하여 주어진 연도에 해당하는 날짜 수(365 또는 366)를 리턴.
// 2월을 29일로 둔 해를 윤년이라고 함
    static int GetDaysInYear(int year) {
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
            return 366;
        } else {
            return 365;
        }
    }

// 해당 날짜가 해당 연도의 처음(1월 1일)부터 며칠째인지를 계산.
    static int ComputeDaysFromYearStart(int year, int month, int day) {
        int days = 0;
        for (int i = 1; i < month; i++) {
            days += days_of_month[i];
            if (i == 2 && GetDaysInYear(year) == 366) {
                days += 1;
            }
        }
        return days;
    }


    int year_, month_, day_;
};

struct InvalidDateException {
    string input_date;

    InvalidDateException(const string &str) : input_date(str) {}
};

// yyyy.mm.dd 형식으로 입출력.
// 사용자 입력 오류시 >> operator는 InvalidDateException을 발생할 수 있음.
ostream &operator<<(ostream &os, const Date &c);

istream &operator>>(istream &is, Date &c);
