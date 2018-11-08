/*
출처 : 삼성 SW Expert Academy 모의 SW 역량테스트#2117
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu
*/

#include <stdio.h>
int map[25][25];
int N, M;
int ans;
int maxk;
int K;
int cost;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int h;
typedef struct st {
	int r, c;
} P;
P que[1000];
int wp, rp;
int lookup[21];

void input()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	ans = 0;
}

int get_cost(int K)
{
	return K*K + (K - 1)*(K - 1);
}

int BFS(int r, int c)
{
	register int nr, nc, i;
	int visit[25][25] = { 0 };
	P out;
	int zip;

	if (map[r][c] == 1) zip = 1;
	else zip = 0;

	wp = rp = 0;
	que[wp++] = (P) { r, c };
	visit[r][c] = 1;

	while (wp > rp) {
		out = que[rp++];
		if (visit[out.r][out.c] == maxk) break;
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i]; nc = out.c + dc[i];
			if (nr <= 0 || nc <= 0 || nr > N || nc > N) continue;
			if (visit[nr][nc]) continue;
			visit[nr][nc] = visit[out.r][out.c] + 1;
			que[wp++] = (P){ nr, nc };
			if (map[nr][nc] == 1) zip++;
		}
	}

	if (zip*M < cost) zip = 0;
	return zip;
}

void get_ans()
{
	register int i, j;
	for (maxk = N + 1; maxk >= 1; maxk--) {
		if (ans>lookup[maxk]) break;
		cost = get_cost(maxk);
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				h = BFS(i, j);
				if (h > ans) ans = h;
			}
		}
	}
}

int main()
{
	int t, testcase;
	int i;
	for (i = 1; i <= 20; i++) lookup[i] = i*i;
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++){
		input();
		get_ans();
		printf("#%d %d\n", t, ans);
	}
	return 0;
}