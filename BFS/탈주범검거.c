/*
출처 : 삼성 SW Expert Academy 모의 SW 역량테스트#1953
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq
*/

#include <stdio.h>
int pipe[8][4] = { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 1, 1, 0, 0 }, { 0, 0, 1, 1 }, \
{1, 0, 0, 1}, { 0, 1, 0, 1 }, { 0, 1, 1, 0 }, { 1, 0, 1, 0 } };
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int c_dir[] = { 1, 0, 3, 2 };
int N, M, R, C, L;
int map[55][55];
int visit[55][55];
typedef struct pos {
	int r, c;
} P;
P que[55 * 55 * 10];
int wp, rp;

void input()
{
	int i, j;
	scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

int BFS(int sr, int sc)
{
	int cnt = 1;
	int nr, nc, i;
	P out;
	int num1, num2;

	wp = rp = 0;
	que[wp++] = (P){ sr, sc };
	visit[sr][sc] = 1;

	while (wp > rp) {
		out = que[rp++];
		if (visit[out.r][out.c] == L) break;
		num1 = map[out.r][out.c];
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i]; nc = out.c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			num2 = map[nr][nc];
			if (pipe[num1][i] == 1 && pipe[num2][c_dir[i]] == 1 && visit[nr][nc] == 0) {
				cnt++;
				visit[nr][nc] = visit[out.r][out.c] + 1;
				que[wp++] = (P) { nr, nc };
			}
		}
	}
	return cnt;
}

void init_visit()
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}

int main()
{
	int t, testcase;
	int sol;
	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		input();
		sol = BFS(R, C);
		init_visit();
		printf("#%d %d\n", t, sol);
	}
}