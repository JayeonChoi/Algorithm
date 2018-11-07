/*
출처: 백준 알고리즘(삼성 알고리즘 테스트 기출)
https://www.acmicpc.net/problem/15684
*/

#include <stdio.h>
#include <string.h>

int N, M, H;
int ans;
int map[35][15];
int flag;

void input()
{
	int i;
	int r, c;

	memset(map, 0, sizeof(map));
	scanf("%d %d %d", &N, &M, &H);
	flag = 0;
	for (i = 0; i < M; i++) {
		scanf("%d %d", &r, &c);
		map[r][c] = 1;
	}
}

int check()
{
	int i, j;
	int s;

	for (i = 1; i <= N; i++) {
		s = i;
		for (j = 1; j <= H; j++) {
			if (map[j][s]) s++;
			else if (map[j][s - 1]) s--;
		}
		if (s != i) return 0;
	}
	return 1;
}

void DFS(int L, int r)
{
	int i, j;

	if (flag) return;
	if (L >= ans) {
		if (check()) {
			flag = 1;
		}
		return;
	}
	//------------------------------------

	for (i = r; i <= H; i++) {
		for (j = 1; j <= N - 1; j++) {
			if (map[i][j] || map[i][j - 1]) continue;
			map[i][j] = 1;
			DFS(L + 1, i);
			map[i][j] = 0;
		}
	}
}

int get_ans()
{
	int i;
	ans = 0;
	for (i = 0; i <= 3; i++) {
		DFS(0, 1);
		if (flag) return ans;
		ans++;
	}

	return -1;
}

int main()
{
	int sol;
	input();
	sol = get_ans();
	printf("%d", sol);
	return 0;
}