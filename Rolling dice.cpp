#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main() {

	int n, m;
	int x, y;
	int num;
	int i, j, k;
	int dice[6] = { 0 };

	cin >> n >> m >> x >> y >> num;

	int **map = new int*[n];

	for (i = 0; i < n; i++) {
		map[i] = new int[m + 1];
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	int *direction = new int[num];
	
	for (i = 0; i < num; i++) {
		cin >> direction[i];
	}
	int temp[6] = { 0 };
	for (i = 0; i < num; i++) {
		
		for (j = 0; j < 6; j++) {
			temp[j] = dice[j];
		}

		if (direction[i] == 1) {
			y = y + 1;
			if ((0 <= y)&& (y < m)) {
				if (map[x][y] != 0) {
					dice[3] = map[x][y];
					dice[1] = temp[4];
					dice[4] = temp[3];
					dice[5] = temp[1];
					map[x][y] = 0;
				}
				else {
					map[x][y] = temp[5];
					dice[1] = temp[4];
					dice[4] = temp[3];
					dice[5] = temp[1];
					dice[3] = temp[5];
				}
			}
			else {
				y = y - 1;
				continue;
			}
		}
		else if (direction[i] == 2) {

			y = y - 1;
			if ((0 <= y) && (y < m)) {
				if (map[x][y] != 0) {
					dice[3] = map[x][y];
					dice[1] = temp[5];
					dice[4] = temp[1];
					dice[5] = temp[3];
					map[x][y] = 0;
				}
				else{
					map[x][y] = temp[4];
					dice[1] = temp[5];
					dice[3] = temp[4];
					dice[4] = temp[1];
					dice[5] = temp[3];
					
				}
			}
			else {
				y = y + 1;
				continue;
			}
		}
		else if (direction[i] == 3) {
			x = x - 1;
			if ((0 <= x)&&(x < n)) {
				if (map[x][y] != 0) {
					dice[3] = map[x][y];
					dice[1] = temp[2];
					dice[0] = temp[1];
					dice[2] = temp[3];
					map[x][y] = 0;
				
				}
				else {
					map[x][y] = temp[0];
					dice[1] = temp[2];
					dice[0] = temp[1];
					dice[2] = temp[3];
					dice[3] = temp[0];

				}
			}
			else {
				x = x + 1;
				continue;
			}
		}
		else if (direction[i] == 4) {
			x = x + 1;
			if ((0 <= x) && (x < n)) {
				if (map[x][y] != 0) {
					dice[3] = map[x][y];
					dice[1] = temp[0];
					dice[0] = temp[3];
					dice[2] = temp[1];
					map[x][y] = 0;
				}
				else {
					map[x][y] = temp[2];
					dice[1] = temp[0];
					dice[0] = temp[3];
					dice[2] = temp[1];
					dice[3] = temp[2];
				}
			}
			else {
				x = x - 1;
				continue;
			}
		}
/*		for (k = 0; k < 6; k++) {
			cout << dice[k];
		}*/	
		cout << dice[1] << endl;
		//cout << endl;
	}

	return 0;
}