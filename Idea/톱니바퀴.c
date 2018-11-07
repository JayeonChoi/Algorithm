/*
출처 : 백준 알고리즘(삼성 알고리즘 테스트 기출)
https://www.acmicpc.net/problem/14891
*/

#include <stdio.h>
int K;
int arr[5][10];
int num[105];
int dir[105];
int pointer[5] = { 0, 1, 1, 1, 1 };
int visit[5];

void input()
{
	int i, j;

	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	scanf("%d", &K);
	for (i = 1; i <= K; i++) {
		scanf("%d %d", &num[i], &dir[i]);
	}
}

void init_pointer()
{
	pointer[1] = pointer[2] = pointer[3] = pointer[4] = 1;
}

int clockwise(int p, int n, int dir)
{
	if (dir == 1)
	{
		return p - n <= 0 ? p - n + 8 : p - n;
	}
	else
	{
		return p + n > 8 ? (p + n) - 8 : p + n;
	}
}

void rotate(int magnet, int direction)
{
	int right, left, middle1, middle2;
	visit[magnet] = 1;
	//인접톱니 회전
	if (magnet == 1) {
		right = clockwise(pointer[magnet], 2, -1);
		left = clockwise(pointer[magnet + 1], 2, 1);

		if (arr[magnet][right] != arr[magnet + 1][left] && visit[magnet + 1] == 0) {
			rotate(magnet + 1, -direction);
		}
	}
	else if (magnet == 4) {
		left = clockwise(pointer[magnet], 2, 1);
		right = clockwise(pointer[magnet - 1], 2, -1);

		if (arr[magnet][left] != arr[magnet - 1][right] && visit[magnet - 1] == 0) {
			rotate(magnet - 1, -direction);
		}
	}
	else {
		middle1 = clockwise(pointer[magnet], 2, 1);
		right = clockwise(pointer[magnet - 1], 2, -1);
		middle2 = clockwise(pointer[magnet], 2, -1);
		left = clockwise(pointer[magnet + 1], 2, 1);

		if (arr[magnet][middle1] != arr[magnet - 1][right] && visit[magnet - 1] == 0) {
			rotate(magnet - 1, -direction);
		}
		if (arr[magnet][middle2] != arr[magnet + 1][left] && visit[magnet + 1] == 0) {
			rotate(magnet + 1, -direction);
		}
	}

	//본인 톱니 회전
	pointer[magnet] = clockwise(pointer[magnet], 1, direction);
}

int get_score()
{
	int i;
	int score = 0;
	static int s[5] = { 0, 1, 2, 4, 8 };

	for (i = 1; i <= K; i++) {
		rotate(num[i], dir[i]);
		visit[1] = visit[2] = visit[3] = visit[4] = 0;
	}

	for (i = 1; i <= 4; i++) {
		if (arr[i][pointer[i]]) score += s[i];
	}
	return score;
}

int main()
{
	int sol;

	input();
	sol = get_score();
	printf("%d", sol);
	init_pointer();

	return 0;
}
