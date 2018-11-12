/*
출처 : 삼성 SW Academy 난이도 D4 #4301
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWLv-yZah48DFAVV
*/

#include <stdio.h>
#define MAX 1010
typedef struct xy{
	int r, c;
} P;
P que[MAX*MAX * 10];
int wp, rp;
int bat[MAX][MAX];
int R, C;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int dr2[] = { -2, 2, 0, 0 };
int dc2[] = { 0, 0, -2, 2 };

void BFS(int sr, int sc) {
	P out;
	int nr, nc;
	int jr, jc;
	int i;

	wp = rp = 0;
	que[wp++] = { sr, sc };

	while (wp > rp) {
		out = que[rp++];
		if (bat[out.r][out.c] == 0) {
			bat[out.r][out.c] = 2;
		}
		for (i = 0; i < 4; i++) {
			jr = out.r + dr2[i];
			jc = out.c + dc2[i];
			if (jr<1 || jc<1 || jr>R || jc>C) continue;
			if (bat[jr][jc] == 0) {
				bat[jr][jc] = 1;
			}
		}

		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i];
			nc = out.c + dc[i];
			if (nr<1 || nc<1 || nr>R || nc>C) continue;
			if (bat[nr][nc] == 0) {
				que[wp++] = { nr, nc };
			}
		}
	}
}

int kong()
{
	register int i, j;
	int k = 0;

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			if (bat[i][j] == 2) k++;
		}
	}
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			bat[i][j] = 0;
		}
	}
	return k;
}
int main()
{
	int testcase, t;
	int cong;
	int i, j;

	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		scanf("%d %d", &C, &R);
		for (i = 1; i <= R; i++) {
			for (j = 1; j <= C; j++) {
				if (bat[i][j] != 0) continue;
				BFS(i, j);
			}
		}

		cong = kong();
		printf("#%d %d\n", t, cong);
	}
	return 0;
}