#include "world_clock.h"

void WorldClock::Tick(int seconds) {

}

bool WorldClock::SetTime(int hour, int minute, int second) {
    if ((hour < 0 || hour > 23) &&
        (minute < 0 || minute > 59) &&
        (second < 0 || second > 59)) {
        return false;
    }
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    return true;
}

ostream &operator<<(ostream &os, const WorldClock &c) {
    return os;
}

istream &operator>>(istream &is, WorldClock &c) {
    return is;
}