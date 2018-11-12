/*
출처 : 삼성 SW Academy [모의 SW 역량테스트] #5656
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo
*/

#include <stdio.h>
#include <string.h>

int N, W, H;
int map[20][20];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
typedef struct pos{
	int r, c;
	int n;
} P;
P que[20 * 20];
int wp, rp;
int min;
int ball;
int shooting(int i);

void input()
{
	register int i, j;
	ball = 0;
	scanf("%d %d %d", &N, &W, &H);
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) ball++;
		}
	}
	min = 0x7fffffff;
}

void DFS(int L, int ball)
{
	register int i;
	int c;
	int pastmap[20][20];
	if (L > N || ball == 0) {
		if (min > ball) min = ball;
		return;
	}
	//-----------------------------

	for (i = 1; i <= W; i++) {
		memcpy(pastmap, map, sizeof(map));
		c = shooting(i);
		if (c == 0) continue;
		DFS(L + 1, ball - c);
		memcpy(map, pastmap, sizeof(map));
	}
}

void maptrim()
{
	register int i, j;
	int flag, k;

	for (i = 1; i <= W; i++) {
		flag = 0;
		for (j = 1; j <= H; j++) {
			if (map[j][i]) flag = 1;
			if (flag && map[j][i] == 0) {
				for (k = j; k >= 1; k--) {
					map[k][i] = map[k - 1][i];
				}
			}
		}
	}
}

int shooting(int i)
{
	int sr, sc, j, k;
	register int nr, nc;
	P out;

	sc = i;
	wp = rp = 0;
	for (j = 1; j <= H; j++) {
		if (map[j][i]) {
			sr = j;
			break;
		}
	}
	if (j == H + 1) return 0;

	que[wp++] = (P){ sr, sc, map[sr][sc] };

	while (wp > rp) {
		out = que[rp++];
		map[out.r][out.c] = 0;
		if (out.n == 1) continue;
		for (j = 0; j < 4; j++) {
			nr = out.r + dr[j]; nc = out.c + dc[j];
			for (k = 1; k <= out.n - 1; k++) {
				if (nr<1 || nc<1 || nr>H || nc>W) break;
				if (map[nr][nc] != 0) {
					que[wp++] = (P) { nr, nc, map[nr][nc] };
					map[nr][nc] = 0;
				}
				nr += dr[j]; nc += dc[j];
			}
		}
	}

	//맵 정리
	maptrim();
	return rp;
}

int main()
{
	int t, testcase;

	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		DFS(1, ball);
		printf("#%d %d\n", t, min);
	}
	return 0;
}