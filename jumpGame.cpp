#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define AT_GOAL 1
#define IN_RANGE 2
#define OUT_RANGE 0

int checkPosition(int y, int x, int n) {
    if ((y == (n - 1)) && (x == (n - 1))) return AT_GOAL;
    else if ((y < n) && (x < n)) return IN_RANGE;
    else return OUT_RANGE;
}

bool move(queue<pair<int, int>> &q, int frontY, int frontX, int n) {
    int position = checkPosition(frontY, frontX, n);

    switch (position) {
        case AT_GOAL :
            return true;
        case IN_RANGE :
            q.push({frontY, frontX});
            break;
        default:
            break;
    }

    return false;
}

bool isHitGoal(int **map, int n) {
    queue<pair<int, int>> q;

    q.push({0, 0});

    while(!q.empty()) {
        int frontY = q.front().first;
        int frontX = q.front().second;
        q.pop();

        if(move(q, frontY, frontX + map[frontY][frontX], n)) return true;
        if(move(q, frontY + map[frontY][frontX], frontX, n)) return true;
    }

    return false;
}

int main() {
    static string RESULT[2] = {"NO", "YES"};

    int c;
    cin >> c;

    int *isPossible = new int[c];

    for (int i = 0; i < c; i++) {
        int n;
        cin >> n;

        // map 동적할당 및 입력
        int **map = new int*[n];
        for (int j = 0; j < n; j++) {
            map[j] = new int[n];

            for (int k = 0; k < n; k++) cin >> map[j][k];
        }

        if (isHitGoal(map, n)) isPossible[i] = 1;
        else isPossible[i] = 0;
    }

    for (int i = 0; i < c; i++) {
        cout << RESULT[isPossible[i]] << endl;
    }
}