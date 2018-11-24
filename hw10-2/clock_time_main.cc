#include <iostream>
#include<array>
#include <vector>

#include "clock_time.h"

using namespace std;

/*
 * vector<Clock*>에 SundialClock, CuckooClock, GrandFatherClock, WristClock, AtomicClock의 객체를 각각 하나씩 순서대로 생성하여 넣는다.
 * 생성할 때의 시간은 0시 0분 0초이다.
 *
 * 우선 모든 시계 객체를 reset한다.
 * 시뮬레이션을 진행하기 전에, “Reported clock times after resetting:”을 출력한 후 각 시계의 현재 시간을 displayTime()을 이용해 출력한다.
 *
 * “Running the clocks...”를 출력한 후 사용자에게 입력 받은 시간 (초) 만큼 tick()을 호출하여 시뮬레이션을 진행한다 (1초당 1 tick)
 * 시뮬레이션이 끝난 후, “Reported clock times after running:”을 출력한 후 각 시계의 현재 시간을 displayTime()을 이용해 출력한다.
 * 시계 객체들을 delete한다.

 */

int main() {
    int seconds;
    cin >> seconds;

    vector<Clock *> clocks;
    clocks.emplace_back(new SundialClock(0, 0, 0));
    clocks.emplace_back(new CuckooClock(0, 0, 0));
    clocks.emplace_back(new GrandFatherClock(0, 0, 0));
    clocks.emplace_back(new WristClock(0, 0, 0));
    clocks.emplace_back(new AtomicClock(0, 0, 0));
    cout << "Reported clock times after resetting:" << endl;
    for (auto clock : clocks) {
        clock->reset();
        clock->displayTime();
    }
    cout << endl << "Running the clocks..." << endl << endl;
    while (seconds > 0) {
        seconds -= 1;
        for (auto clock : clocks) {
            clock->tick();
        }
    }
    for (auto clock : clocks) {
        clock->displayTime();
        delete clock;
    }
    return 0;
}
