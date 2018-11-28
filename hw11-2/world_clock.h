#include <iostream>

using namespace std;

class WorldClock {
public:
    void Tick(int seconds = 1);

    bool SetTime(int hour, int minute, int second);
    // 잘못된 값 입력시 false 리턴하고 원래 시간은 바뀌지 않음.

    int getHour() const {
        return this->hour;
    };

    int getMinute() const {
        return this->minute;
    };

    int getSecond() const {
        return this->second;
    };

    int getTimestamp() const {
        return (hour * 3600) + (minute * 60) + second;
    };

private:
    int hour;
    int minute;
    int second;
};

ostream &operator<<(ostream &os, const WorldClock &c);

istream &operator>>(istream &is, WorldClock &c);
