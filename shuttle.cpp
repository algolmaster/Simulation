#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string>
using namespace std;

#define START_HOUR 9
#define START_MIN 0

#define HOUR 60

class Time {
public:
    int hour;
    int min;
    Time() {};
    Time(string strTime) {
        hour = stoi(strTime.substr(0, 2));
        min = stoi(strTime.substr(3));
    }
    Time(int hour, int min) {
        this->hour = hour;
        this->min = min;
    }
};

class Bus {
public:
    int limit;
    Time time;
    int numOfPassengers;
    vector<Time> passengers;

    Bus(int limit, int hour, int min) {
        this->limit = limit;
        this->time = Time(hour, min);

        numOfPassengers = 0;
    }

    bool isFull(Time passenger) {
        this->passengers.push_back(passenger);
        numOfPassengers++;

        if (this->passengers.size() == limit) return true;
        else return false;
    }

    bool isInTime(int pHour, int pMin) {
        if ((pHour == time.hour) && (pMin <= time.min)) return true;
        else if(pHour < time.hour) return true;
        else return false;
    }
};

class ShuttleTable {
public:
    vector<Bus> buses;

    ShuttleTable(int n, int t, int m);
};

ShuttleTable::ShuttleTable(int n, int t, int m) {
    int hour = START_HOUR;
    int min = START_MIN;

    for (int i = 0; i < n; i++) {
        buses.push_back(Bus(m, hour, min));

        min += t;

        if (min >= HOUR) {
            min -= HOUR;
            hour++;
        }
    }
}

void getLastTime(ShuttleTable shuttle, int limit) {
    Bus lastBus = shuttle.buses.back();
    Time lastTime;

    if (lastBus.numOfPassengers < limit) {
        lastTime = lastBus.time;
    }
    else {
        Time lastPassenger = lastBus.passengers.back();

        int hour = lastPassenger.hour;
        int min = lastPassenger.min;

        min -= 1;

        if (min < 0) {
            hour--;
            min += 60;
        }

        lastTime.hour = hour;
        lastTime.min = min;
    }

    cout << lastTime.hour << ":" << lastTime.min;
}

int main() {
    int n = 2, t = 10, m = 2;
//    vector<string> timeTableStr = {"08:00", "08:01", "08:02", "08:03"};
    vector<string> timeTableStr = {"09:10", "09:09", "08:00"};

    sort(timeTableStr.begin(), timeTableStr.end());

    vector<Time> timeTable;
    for (int i = 0; i < timeTableStr.size(); i++) {
        timeTable.push_back(Time(timeTableStr[i]));
    }

    ShuttleTable shuttle(n, t, m);

    int index = 0;

    for (int i = 0; i <timeTable.size(); i++) {
        int hour = timeTable[i].hour;
        int min = timeTable[i].min;

        while(shuttle.buses[index].isInTime(hour, min)) {
            index++;

            if (index >= shuttle.buses.size()) {

                // 모든 버스가 꽉 찬 경우!!!!
                getLastTime(shuttle, m);
                return 0;
            }
        }

        if (shuttle.buses[index].isFull(timeTable[i])) {
            index++;
        }
    }

    getLastTime(shuttle, m);
}