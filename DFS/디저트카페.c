/*
출처 : 삼성 SW Expert Academy 모의 SW 역량테스트#2105
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5VwAr6APYDFAWu
*/

#include <stdio.h>
int N;
int region[25][25];
int mapvisit[25][25];
int visit[110];
int dr[] = { 1, 1, -1, -1 };
int dc[] = { 1, -1, -1, 1 };
int sr, sc;
int max;
int list[110];
int tmplist[110];

void input()
{
	register int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", region[i][j]);
		}
	}
	max = 1;
}

void DFS(int dessert, int r, int c, int start)
{
	register int i;
	int nr, nc, tmp;
	//----------------------
	for (i = start; i < 4; i++) {
		nr = r + dr[i]; nc = c + dc[i];
		tmp = region[nr][nc];

		if (nr == sr && nc == sc && dessert >= 4) {
			if (dessert > max) max = dessert;
			return;
		}
		if (nr <= 0 || nc <= 0 || nr > N || nc > N) continue;
		if (mapvisit[nr][nc]) continue;
		if (visit[tmp]) continue;
		mapvisit[nr][nc] = 1;
		visit[tmp] = 1;
		DFS(dessert + 1, nr, nc, i);
		visit[tmp] = 0;
		mapvisit[nr][nc] = 0;
	}
}

void get_max()
{
	register int i, j;
	for (i = 1; i <= N - 2; i++) {
		sr = i;
		for (j = 2; j <= N - 1; j++) {
			sc = j;
			visit[region[i][j]] = 1;
			mapvisit[sr][sc] = 1;
			DFS(1, i, j, 0);
			mapvisit[sr][sc] = 0;
			visit[region[i][j]] = 0;
		}
	}
	if (max == 1) max = -1;
}

int main()
{
	int t, testcase;
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		get_max();
		printf("#%d %d\n", t, max);
	}
	return 0;
}