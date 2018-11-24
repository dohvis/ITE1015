#ifndef CLOCK_TIME_H
#define CLOCK_TIME_H

#include <iostream>

using namespace std;
// Define a set of symbolic constants used to specify various values related
// to time keeping.
#define SECONDS_PER_MINUTE      60
#define MINUTES_PER_HOUR        60
#define HOURS_PER_DAY           24

class ClockTime
// ClockTime is a concrete identity class used to keep track of current
// time as it is moves forward.  Note that time cannot be regressed.
//
// NOTE: Copying an instance of this class is bit-wise.
{
public:
    ClockTime();

    ClockTime(int hour, int minute, int second, int secondsPerTick);

    ~ClockTime() { hour_ = minute_ = second_ = secondsPerTick_ = startTime_ = 0; }

    int const hour() const { return hour_; }

    int const minute() const { return minute_; }

    int const second() const { return second_; }

    int const secondsPerTick() const { return secondsPerTick_; }

    unsigned int startTime() const { return startTime_; }

    unsigned int deltaTime() const { return deltaTime_; }

    void setTime(ClockTime const &initialTime) {
        hour_ = initialTime.hour_;
        minute_ = initialTime.minute_;
        second_ = initialTime.second_;
        secondsPerTick_ = initialTime.secondsPerTick_;
        deltaTime_ = 0;
    }

    void setTime(int hour, int minute, int second, int secondsPerTick) {
        hour_ = hour;
        minute_ = minute;
        second_ = second;
        secondsPerTick_ = secondsPerTick;
        deltaTime_ = 0;
    }

    void reset();

    void increment();

    void display() const;

private:
    int hour_;
    int minute_;
    int second_;
    int secondsPerTick_;
    unsigned int startTime_;
    unsigned int deltaTime_;

    void recordStartTime();
};

class Clock {
public:
    Clock(int hour, int minute, int second, double driftPerSecond) :
            _clockTime(hour, minute, second, 1), _driftPerSecond(driftPerSecond), _totalDrift(0) {
    }

    void reset() {
        this->_clockTime.reset();
    };

    void tick() {
        this->_clockTime.increment();
        _totalDrift += _driftPerSecond;
    };

    virtual ~Clock() = default;

    virtual void displayTime() = 0;

protected:
    ClockTime _clockTime;
    double _driftPerSecond;
    double _totalDrift;
};

class NaturalClock : public Clock {
public:
    NaturalClock(int hour, int minute, int second, double driftPerSecond) :
            Clock(hour, minute, second, driftPerSecond) {}

};

class MechanicalClock : public Clock {
public:
    MechanicalClock(int hour, int minute, int second, double driftPerSecond) :
            Clock(hour, minute, second, driftPerSecond) {

    }

};

class DigitalClock : public Clock {
public:
    DigitalClock(int hour, int minute, int second, double driftPerSecond) :
            Clock(hour, minute, second, driftPerSecond) {}

};

class QuantumClock : public Clock {
public:
    QuantumClock(int hour, int minute, int second, double driftPerSecond) :
            Clock(hour, minute, second, driftPerSecond) {}
};

class SundialClock : public NaturalClock {
public:
    SundialClock(int hour, int minute, int second) :
            NaturalClock(hour, minute, second, 0.0) {}

    void displayTime() override {
        cout << "SundialClock ";
        this->_clockTime.display();
        cout << " total drift: " << this->_totalDrift << endl;
    }
};

class CuckooClock : public MechanicalClock {
public:
    CuckooClock(int hour, int minute, int second) :
            MechanicalClock(hour, minute, second, 0.0) {}

    void displayTime() override {
        cout << "CuckooClock ";
        this->_clockTime.display();
        cout << " total drift: " << this->_totalDrift << endl;
    }
};

class GrandFatherClock : public MechanicalClock {
public:
    GrandFatherClock(int hour, int minute, int second) :
            MechanicalClock(hour, minute, second, 0.000694444) {}

    void displayTime() override {
        cout << "GrandFatherClock ";
        this->_clockTime.display();
        cout << " total drift: " << this->_totalDrift << endl;
    }
};

class WristClock : public DigitalClock {
public:
    WristClock(int hour, int minute, int second) :
            DigitalClock(hour, minute, second, 0.000347222) {}

    void displayTime() override {
        cout << "WristClock ";
        this->_clockTime.display();
        cout << " total drift: " << this->_totalDrift << endl;
    }
};

class AtomicClock : public QuantumClock {
public:
    AtomicClock(int hour, int minute, int second) :
            QuantumClock(hour, minute, second, 0.000034722) {}

    void displayTime() override {
        cout << "AtomicClock ";
        this->_clockTime.display();
        cout << " total drift: " << this->_totalDrift << endl;
    }
};


#endif  // CLOCK_TIME_H
