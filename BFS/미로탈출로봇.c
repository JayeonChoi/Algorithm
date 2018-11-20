/*
정올(정보올림피아드) > 문제은행
http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=521&sca=50&sfl=wr_hit&stx=1238&sop=and
*/

#include <stdio.h>
int N;
int map[15][15];
int visit[15][15];
int d, dp;
int dir[4];
int dr[] = { 0, 1, 0, -1, 0 };
int dc[] = { 0, 0, -1, 0, 1 };
int wp, rp;
typedef struct pos {
	int r, c;
} P;
P que[15 * 15 * 15];

void input()
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (i = 0; i < 4; i++) scanf("%d", &dir[i]);
	for (i = 0; i <= N + 1; i++) {
		for (j = 0; j <= N + 1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) map[i][j] = 1;
		}
	}
	d = dir[0];
	dp = 0;
}

int BFS(int sr, int sc)
{
	int nr, nc;
	P out;
	int cnt = 0;
	wp = rp = 0;
	map[sr][sc] = 2;
	que[wp++] = (P) { sr, sc };

	while (wp > rp) {
		out = que[rp++];
		nr = out.r + dr[d]; nc = out.c + dc[d];
		if (map[nr][nc] == 2) break;

		if (map[nr][nc] == 1) {
			dp = (dp + 1) % 4;
			d = dir[dp];
			que[wp++] = (P) { out.r, out.c };
		}
		else {
			map[nr][nc] = 2;
			que[wp++] = (P){ nr, nc };
			cnt++;
		}

	}
	return cnt;
}

int main()
{
	int sol;
	input();
	sol = BFS(1, 1);
	printf("%d", sol);
}