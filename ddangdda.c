#include <stdio.h>
#include <string.h>

int board[101][101]; //실제 보드판
int path[101][101]; //갈 수 있는지의 여부를 판단하는 판
int n;

int cango(int y, int x) {
	if ((y > n - 1) || (x > n - 1)) {
		return 0;
	}

	int check = path[y][x];
	if (check != -1) {
		return check;
	}

	int amount = board[y][x];
	return check = (cango(y + amount, x) || cango(y, x + amount)); //한 곳이라도 갈 수 있으면 
}

int main() {
	int C;
	scanf_s("%d", &C);

	for (int i = 0; i < C; i++) {
		scanf_s("%d", &n);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				scanf_s("%d", &board[j][k]);
			}
		}

		memset(path, -1, sizeof(path)); //초기는 -1로 세팅

		path[n - 1][n - 1] = 1; //맨 마지막은 성공이므로 1로 세팅
		int check = cango(0, 0); //맨 처음부터 갈수 있는지 성공
		if (check == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				printf("%d ", path[j][k]);
			}
			printf("\n");
		}
	}

	return 0;
}