#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

#define NO 0
#define YES 1

int cache[101][101];
int board[101][101];
int n;

int canReach(int y, int x) {
	if ((y > n - 1) || (x > n - 1)) {
		return NO;
	}

	int& ret = cache[y][x];
	if (ret != -1) {
		return ret;
	}

	int amount = board[y][x];
	return ret = (canReach(y + amount, x) || canReach(y, x + amount));
}

int main() {
	int C;
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &board[j][k]);
			}
		}

		memset(cache, -1, sizeof(cache));
		cache[n - 1][n - 1] = YES;
		int ret = canReach(0, 0);
		if (ret == YES) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}