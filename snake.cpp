#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

struct Point {
    int y;
    int x;

    Point(){};
    Point(int y, int x) {
        this->y = y;
        this->x = x;
    }

    bool operator==(const Point& rhs) {
        if ((this->y==rhs.y) && (this->x==rhs.x)) return true;
        else return false;
    }
};

struct Redirection {
    int sec;
    int direction;
};

bool isGameEnded(int n, int y, int x, vector<Point> v) {
    if (find(v.begin(), v.end(), Point(y, x)) != v.end()) return true;

    else if ((0 < y) && (n >= y) && (0 < x) && (n >= x)) return false;
    else return true;
}

int main() {
    int n, k, l;
    cin >> n >> k;

    Point toward[4] = {Point(0, +1), Point(+1, 0),
                          Point(0, -1), Point(-1, 0)};

    vector<Point> appleP;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;

        appleP.push_back(Point(y, x));
    }

    cin >> l;
    Redirection *redirection = new Redirection[l];
    for (int i = 0; i < l; i++) {
        char direction;

        cin >> redirection[i].sec >> direction;

        if (direction == 'D') redirection[i].direction = +1;
        else redirection[i].direction = -1;
    }

    int time = 0, direction = 0, redirectionIdx = 0;

    vector<Point> v;
    v.push_back(Point(1, 1));

    while(true) {
        time++;

        int tempY = v.back().y + toward[direction].y;
        int tempX = v.back().x + toward[direction].x;

        if ((redirectionIdx < l) && (time == redirection[redirectionIdx].sec)) {
            direction = (direction + 4 + redirection[redirectionIdx].direction) % 4;
            redirectionIdx++;
        }

        if (isGameEnded(n, tempY, tempX, v)) break;

        auto it = find(appleP.begin(), appleP.end(), Point(tempY, tempX));
        if (it != appleP.end()) {
            appleP.erase(it);
        }
        else {
            v.erase(v.begin());
        }

//        if (isGameEnded(n, tempY, tempX, v)) break;

        v.push_back(Point(tempY, tempX));
    }

    cout << time;
}