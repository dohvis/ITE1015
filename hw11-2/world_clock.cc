#include "world_clock.h"

void WorldClock::Tick(int seconds) {
    int total_seconds = getTimestamp() + seconds;
    int h,m,s;
    if (total_seconds < 0) {
        total_seconds += 86400 ;
    }
    h = total_seconds / 3600;
    total_seconds -= h * 3600;
    m = total_seconds / 60;
    total_seconds -= m * 60;
    s = total_seconds;

    h %= 24;
    m %= 60;
    s %= 60;
    this->SetTime(h, m, s);
}

bool WorldClock::SetTime(int hour, int minute, int second) {
    if ((hour < 0 || hour > 23) ||
        (minute < 0 || minute > 59) ||
        (second < 0 || second > 59)) {
        return false;
    }
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    return true;
}

ostream &operator<<(ostream &os, const WorldClock &c) {
    os << c.getHour() << ":" << c.getMinute() << ":" << c.getSecond() << endl;
    return os;
}

istream &operator>>(istream &is, WorldClock &c) {
    int hour, minute, second;
    char colon = ':';
    is >> hour >> colon >> minute >> colon >> second;
    if (!c.SetTime(hour, minute, second)) {
        cout << "Invalid time: " << hour << colon << minute << colon << second << endl;
    } else {
        cout << c << endl;
    }

    return is;
}
