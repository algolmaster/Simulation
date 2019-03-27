#include <iostream>
#include <vector>
#include<cstdio>
#include<queue>

using namespace std;

class snake_ {
public:
	int length = 1;
	int snake_move = 1;
	int snake_head_x = 0;
	int snake_head_y = 0;
	int snake_tail_x = 0;
	int snake_tail_y = 0;

}snake;

int num;
int *time = new int[num + 1];
char *arrow = new char[num + 1];
int check = 0;
int now_time = 0;

int find_head(int **board);
int check_apple(int **board, int snake_head_x, int snake_head_y, int x, int y, int size);
int find_tail(int **board, int size);


int main() {
	int size;
	int i, j, k;
	cin >> size;

	//board Å©±â µ¿ÀûÇÒ´ç
	int **board = new int*[size];
	for (i = 0; i < size; i++) {
		board[i] = new int[size];
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			board[i][j] = 0;
		}
	}

	//apple °¹¼ö¿Í À§Ä¡ ÀÔ·Â ¹Ş±â
	int apple_num;
	cin >> apple_num;
	int x, y;
	for (i = 0; i < apple_num; i++) {
		cin >> x >> y;
		board[x - 1][y - 1] = -1;
	}

	//ÀÌµ¿ È½¼ö ÀÔ·Â¹Ş±â

	cin >> num;

	for (i = 0; i < num; i++) {
		cin >> time[i] >> arrow[i];

	}

	//int snake_length = 1;
	//¹æÇâ
	//1¿À¸¥ÂÊ, 2¿ŞÂÊ, 3À§ÂÊ, 4¾Æ·¡ÂÊ

	board[0][0] = snake.length;

	while (1) {
		x = snake.snake_tail_x;
		y = snake.snake_tail_y;

		find_head(board);

		//¹ìÀÌ board ¹ÛÀ¸·Î ³Ñ¾î°¬À»¶§
		if ((0 > snake.snake_head_x) || (snake.snake_head_x >= size) || (0 > snake.snake_head_y) || (snake.snake_head_y >= size)) {
			cout << now_time + 1;
			return 0;
		}
		//¹ìÀÌ ¸ö¿¡ ºÎµúÈú¶§
		else if ((board[snake.snake_head_x][snake.snake_head_y] >= 1)) {
			cout << now_time + 1;
			return 0;
		}
		check_apple(board, snake.snake_head_x, snake.snake_head_y, x, y, size);
		now_time += 1;
		//	find_tail(board, size);



	}
	return 0;
}

int find_head(int **board) {
	if ((now_time) == time[check]) {
		if (arrow[check] == 'D') {
			if (snake.snake_move == 1)
			{
				snake.snake_head_x += 1;
				snake.snake_move = 4;
			}
			else if (snake.snake_move == 2) {
				snake.snake_head_x -= 1;
				snake.snake_move = 3;
			}
			else if (snake.snake_move == 3) {
				snake.snake_head_y += 1;
				snake.snake_move = 1;
			}
			else {
				snake.snake_head_y -= 1;
				snake.snake_move = 2;
			}
		}
		else {
			if (snake.snake_move == 1) {
				snake.snake_move = 3;
				snake.snake_head_x -= 1;
			}
			else if (snake.snake_move == 2) {
				snake.snake_move = 4;
				snake.snake_head_x += 1;
			}
			else if (snake.snake_move == 3) {
				snake.snake_move = 2;
				snake.snake_head_y -= 1;
			}
			else {
				snake.snake_move = 1;
				snake.snake_head_y += 1;
			}
		}
		check += 1;
	}
	else {
		if (snake.snake_move == 1) {
			snake.snake_head_y += 1;
		}
		else if (snake.snake_move == 2) {
			snake.snake_head_y -= 1;
		}
		else if (snake.snake_move == 3) {
			snake.snake_head_x -= 1;
		}
		else {
			snake.snake_head_x += 1;
		}
	}
	return 0;
}


int find_tail(int **board, int size) {
	int var1, var2;
	int x1 = snake.snake_tail_x, y1 = snake.snake_tail_y;
	int x2 = snake.snake_tail_x, y2 = snake.snake_tail_y;

	if ((snake.snake_tail_x - 1) < 0)
	{
		var1 = board[snake.snake_tail_x + 1][snake.snake_tail_y];
		x1 += 1;
	}
	else if ((snake.snake_tail_x + 1) >= size) {
		var1 = board[snake.snake_tail_x - 1][snake.snake_tail_y];
		x1 -= 1;
	}
	else {
		if (board[snake.snake_tail_x - 1][snake.snake_tail_y] > board[snake.snake_tail_x + 1][snake.snake_tail_y])
		{
			var1 = board[snake.snake_tail_x - 1][snake.snake_tail_y];
			x1 -= 1;
		}
		else {
			var1 = board[snake.snake_tail_x + 1][snake.snake_tail_y];
			x1 += 1;
		}
	}

	if ((snake.snake_tail_y - 1) < 0)
	{
		var2 = board[snake.snake_tail_x][snake.snake_tail_y + 1];
		y2 += 1;
	}
	else if ((snake.snake_tail_y + 1) >= size) {
		var2 = board[snake.snake_tail_x][snake.snake_tail_y - 1];
		y2 -= 1;
	}
	else {
		if (board[snake.snake_tail_x][snake.snake_tail_y - 1] > board[snake.snake_tail_x][snake.snake_tail_y + 1])
		{
			var2 = board[snake.snake_tail_x][snake.snake_tail_y - 1];
			y2 -= 1;
		}
		else {
			var2 = board[snake.snake_tail_x][snake.snake_tail_y + 1];
			y2 += 1;
		}
	}

	if (var1 > var2) {
		snake.snake_tail_x = x1;
		snake.snake_tail_y = y1;
	}
	else {
		snake.snake_tail_x = x2;
		snake.snake_tail_y = y2;
	}
	return 0;
}

int check_apple(int **board, int snake_head_x, int snake_head_y, int x, int y, int size) {

	if (board[snake_head_x][snake_head_y] == -1) {
		snake.length += 1;
		board[snake_head_x][snake_head_y] = snake.length;
	}
	else {
		board[x][y] = 0;
		board[snake_head_x][snake_head_y] = snake.length;
		find_tail(board, size);
	}
	board[snake_head_x][snake_head_y] = snake.length;
	return 0;
}
