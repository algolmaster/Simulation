#include <stdio.h>
#include <stdlib.h>

int N = 0; //���� ����
int M = 0; //���� ����
int x = 0, y = 0, K = 0; //�ֻ��� ��ġ(x,y) , K : ��ɾ� ����
int u=1, b = 3; //�ֻ��� ���� �Ʒ� ��ġ

char out_border(int x, int y) { //�ֻ����� ���� ������� 1
	return (x >= 0 && x <= N - 1) && (y >= 0 && y <= M - 1) ? 0 : 1;
}
char change_ns(int dir) { //��, ������ ������ ��
	if (b < 4) {
		if (b == 1 || b == 2) { //�ظ��� 1,2
			if (dir == 4) {
				b++; u = b - 2;
				return 1;
			}
			else {
				b--; u = b + 2;
				return 1;
			}
		}
		else if (b == 0) { //�ظ��� 0 
			if (dir == 4) {
				b = 1; u = 3;
				return 1;
			}
			else {
				b = 3; u = 1;
				return 1;
			}
		}
		else if (b == 3) { //�ظ��� 0 
			if (dir == 4) {
				b = 0; u = 2;
				return 1;
			}
			else {
				b = 2; u = 0;
				return 1;
			}
		}
	}
	else if (b == 4) { //�ظ��� 4
		if (dir == 3) {
			b = 0; u = 2;
			return 1;
		}
		else {
			b = 2; u = 0;
			return 1;
		}
	}
	else if (b == 5) { //�ظ��� 5
		if (dir == 3) {
			b = 2; u = 0;
			return 1;
		}
		else {
			b = 0; u = 2;
			return 1;
		}
	}
}
char change_we(int dir) { //��, ���� ������ ��
	if (b < 4) { //�ظ��� 0,1,2,3
		if (dir == 1) {
			u = 5; b = 4;
			return 1;
		}
		else {
			u = 4; b = 5;
			return 1;
		}
	}
	else if (b == 4) { //�ظ��� 4
		if (dir == 1) {
			b = 3; u = 1;
			return 1;
		}
		else {
			b = 1; u = 3;
			return 1;
		}
	}
	else if (b == 5) { //�ظ��� 5
		if (dir == 1) {
			b = 1; u = 3;
			return 1;
		}
		else {
			b = 3; u = 1;
			return 1;
		}
	}
}
char pos(int dir) { //�ֻ��� ��ġ ����
	switch (dir) {
		case 1:
			if (out_border(x, ++y)) {
				--y;
				return 0;
			}
			else
				change_we(1);
			break;
		case 2:
			if (out_border(x, --y)) {
				++y;
				return 0;
			}
			else
				change_we(2);
			break;
		case 3:
			if (out_border(--x, y)) {
				++x;
				return 0;
			}
			else
				change_ns(3);
			break;
		case 4:
			if (out_border(++x, y)) {
				--x;
				return 0;
			}
			else
				change_ns(4);
			break;
	}
}
void main(void) {

	scanf_s("%d %d %d %d %d", &N, &M, &x, &y, &K);

	int *board = (int*)malloc(sizeof(int)*N*M); //���� �������迭
	int *result = (int*)malloc(sizeof(int)*K); //���

	for (int i = 0; i < N*M; i++)
		scanf_s("%d",&board[i]);
	
	for(int i=0;i<K;i++)
		scanf_s("%d", &result[i]);
	for (int i = 0; i < K; i++)
		printf("%d", result[i]);

	int dice[6] = { 0 }; //�ֻ��� �迭
	for (int i = 0; i < K; i++) {
		if (pos(result[i])) {
			printf("%d %d\n", x, y);
			if (board[2 * x + y] == 0) { //ĭ�� ������ ���� 0�̸�
				board[2 * x + y] = dice[b];
			}
			else {
				dice[b] = board[2 * x + y];
				board[2 * x + y] = 0;
			}
			printf("%d\n", dice[u]);
		}
	}
	return;
}