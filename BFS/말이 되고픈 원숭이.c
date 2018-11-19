/*
출처 : 백준 알고리즘 (1600번 말이 되고픈 원숭이)
https://www.acmicpc.net/problem/1600
*/

#include <stdio.h>
int K;
int W, H;
int map[205][205];
int hr[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hc[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int mr[] = { -1, 1, 0, 0 };
int mc[] = { 0, 0, -1, 1 };
typedef struct pos {
	int r, c;
	int step, k;
} P;
P que[200 * 200 * 35];
int wp, rp;
int visit[33][205][205];

void input()
{
	register int i, j;
	scanf("%d %d %d", &K, &W, &H);
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

int go_to_dest()
{
	register int i, nr, nc;
	P out;

	wp = rp = 0;
	que[wp++] = (P) { 1, 1, 0, 0 };
	visit[0][1][1] = 1;


	while (wp > rp) {
		out = que[rp++];
		if (out.k < K) {
			for (i = 0; i < 8; i++) {
				nr = out.r + hr[i]; nc = out.c + hc[i];
				if (nr<1 || nc <1 || nr>H || nc>W) continue;
				if (map[nr][nc]) continue;
				if (visit[out.k + 1][nr][nc]) continue;
				if (nr == H && nc == W) return out.step + 1;

				visit[out.k + 1][nr][nc] = 1;
				que[wp++] = (P){ nr, nc, out.step + 1, out.k + 1 };
			}
		}

		for (i = 0; i < 4; i++) {
			nr = out.r + mr[i]; nc = out.c + mc[i];
			if (nr<1 || nc <1 || nr>H || nc>W) continue;
			if (map[nr][nc]) continue;
			if (visit[out.k][nr][nc]) continue;
			if (nr == H && nc == W) return out.step + 1;

			que[wp++] = (P){ nr, nc, out.step + 1, out.k };
			visit[out.k][nr][nc] = 1;
		}
	}

	return -1;
}

int main()
{
	int ans;
	input();
	ans = go_to_dest();
	printf("%d", ans);
	return 0;
}
