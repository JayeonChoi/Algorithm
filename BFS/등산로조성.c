/*
출처 : 삼성 SW Expert Academy 모의 SW 역량테스트#1949
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq
*/

#include <stdio.h>
int N, K;
int topn;
int map[10][10];
int visit[10][10];
int ans;
typedef struct pos {
	int r, c;
} P;
P top[5];
int wp, rp;
P que[1000];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int tmax;
int BFS();

void init_visit()
{
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			visit[i][j] = 0;
		}
	}
}

void input()
{
	int i, j;
	int max = 0;
	tmax = 0;
	topn = 0;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > tmax) tmax = map[i][j];
		}
	}
	//봉우리 찾기
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (map[i][j] == tmax) {
				top[topn++] = (P){ i, j };
			}
		}
	}
	//공사 안했을 때 ans구하기
	ans = BFS();
}

int BFS()
{
	//봉우리 개수만큼 BFS돌리기
	int nr, nc, i;
	int j;
	P out;
	int max = 0;
	int n1, n2;

	for (j = 0; j < topn; j++) {
		wp = rp = 0;
		que[wp++] = top[j];
		if (map[top[j].r][top[j].c] != tmax) continue;
		visit[top[j].r][top[j].c] = 1;
		while (wp > rp) {
			out = que[rp++];
			n1 = map[out.r][out.c];
			for (i = 0; i < 4; i++) {
				nr = out.r + dr[i];
				nc = out.c + dc[i];
				if (nr<1 || nc<1 || nr>N || nc>N) continue;
				n2 = map[nr][nc];
				if (n1 > n2 && visit[out.r][out.c] >= visit[nr][nc]) {
					visit[nr][nc] = visit[out.r][out.c] + 1;
					que[wp++] = (P){ nr, nc };
				}
			}
		}
		if (visit[out.r][out.c] > max) max = visit[out.r][out.c];
		init_visit();
	}
	return max;
}

void get_ans()
{
	int i, j, n;
	int max;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (n = 1; n <= K; n++) {
				if (map[i][j] < n) break;
				map[i][j] -= n;
				max = BFS();
				if (max > ans) {
					//printf("고친곳 : %d %d, 깊이: %d\n", i, j, n);
					ans = max;
				}
				map[i][j] += n;
			}
		}
	}
}

int main()
{
	int t, testcase;
	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		input();
		get_ans();
		printf("#%d %d\n", t, ans);
	}
	return 0;
}