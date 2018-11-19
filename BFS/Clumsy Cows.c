/*
USACO 2012 November Contest, Silver
Problem 1. Clumsy Cows
http://www.usaco.org/index.php?page=viewproblem2&cpid=190
*/

#include <stdio.h>
#include <string.h>

int N, A, B;
int ans;
char map[35][35];
int visit[35][35];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
typedef struct st{
	int r, c;
}P;
P que[35 * 35 * 10];
int wp, rp;

void input()
{
	int i;
	scanf("%d %d %d", &N, &A, &B);
	for (i = 1; i <= N; i++) {
		scanf("%s", map[i] + 1);
	}
	ans = 0;
}

void BFS(int sr, int sc)
{
	int i, j, nr, nc;
	P out;
	int tmp;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			visit[i][j] = 0x7fffffff;
		}
	}
	wp = rp = 0;
	que[wp++] = (P){ sr, sc };
	visit[sr][sc] = 0;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i]; nc = out.c + dc[i];
			if (nr<1 || nc < 1 || nr>N || nc>N) continue;
			if (map[out.r][out.c] == map[nr][nc]) tmp = visit[out.r][out.c] + A;
			else tmp = visit[out.r][out.c] + B;
			if (visit[nr][nc] > tmp) {
				visit[nr][nc] = tmp;
				que[wp++] = (P){ nr, nc };
			}
		}
	}
}

int get_ans()
{
	int i, j, k, l;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			BFS(i, j);
			for (k = 1; k <= N; k++) {
				for (l = 1; l <= N; l++) {
					if (visit[k][l] > ans) ans = visit[k][l];
				}
			}
		}
	}
	return ans;
}

int main()
{
	int t, testcase;
	int sol;
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		sol = get_ans();
		printf("%d\n", sol);
	}
	return 0;
}
