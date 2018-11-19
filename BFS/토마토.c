/*
출처 : 백준 알고리즘 (7569번 토마토)
https://www.acmicpc.net/problem/7569
*/

#include <stdio.h>
#define MAX 110

int R, C, H;
int box[MAX][MAX][MAX];
typedef struct xy {
	int r, c, k;
} P;
P que[MAX*MAX * MAX];
int tcount;
int wp, rp;
int dr[6] = { -1, 1, 0, 0, 0, 0 };
int dc[6] = { 0, 0, -1, 1, 0, 0 };
int dk[6] = { 0, 0, 0, 0, -1, 1 };

void input()
{
	int i, j, k;

	scanf("%d %d %d", &C, &R, &H);
	for (k = 0; k < H; k++) {
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				scanf("%d", &box[k][i][j]);
				if (box[k][i][j] == 0) tcount++;
				else if (box[k][i][j] == 1) {
					que[wp++] = (P) { i, j, k };
				}
			}
		}
	}
}

int BFS()
{
	int nr, nc, nk, i;
	P out;

	if (!tcount) return 0;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 6; i++) {
			nr = out.r + dr[i];
			nc = out.c + dc[i];
			nk = out.k + dk[i];
			if (nr < 0 || nc < 0 || nk<0 || nr >= R || nc >= C || nk >= H) continue;
			if (box[nk][nr][nc] == 0) {
				box[nk][nr][nc] = box[out.k][out.r][out.c] + 1;
				que[wp++] = (P){ nr, nc, nk };
				tcount--;
			}

			if (tcount == 0) return box[nk][nr][nc] - 1;
		}
	}

	return -1;
}

int main(void)
{
	int sol;

	input();
	sol = BFS();
	printf("%d", sol);

	return 0;
}