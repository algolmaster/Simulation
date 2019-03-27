#include <stdio.h>
#include <string.h>

int board[101][101]; //���� ������
int path[101][101]; //�� �� �ִ����� ���θ� �Ǵ��ϴ� ��
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
	return check = (cango(y + amount, x) || cango(y, x + amount)); //�� ���̶� �� �� ������ 
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

		memset(path, -1, sizeof(path)); //�ʱ�� -1�� ����

		path[n - 1][n - 1] = 1; //�� �������� �����̹Ƿ� 1�� ����
		int check = cango(0, 0); //�� ó������ ���� �ִ��� ����
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