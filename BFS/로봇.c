/*
정올(정보올림피아드) > 알고리즘 > BFS
http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=285&sca=30&sfl=wr_hit&stx=1006&sop=and
*/

#include <stdio.h>
int N, M;
int map[110][110];
int cost[110][110];
int sr, sc, sd;
int er, ec, ed;
int cdir[] = { 0, 2, 1, 4, 3 };
int dr[] = { 0, 0, 0, 1, -1 };
int dc[] = { 0, 1, -1, 0, 0 };
typedef struct st {
	int r, c, d;
	int cost;
} P;
P que[100 * 100 * 100];

int wp, rp;
void input()
{
	int i, j;
	scanf("%d %d", &M, &N);
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			cost[i][j] = 0x7fffffff;
		}
	}
	scanf("%d %d %d", &sr, &sc, &sd);
	scanf("%d %d %d", &er, &ec, &ed);
	for (i = 0; i <= M + 1; i++) {
		for (j = 0; j <= N + 1; j++) {
			if (i == 0 || j == 0 || i == M + 1 || j == N + 1) map[i][j] = 1;
		}
	}
}

int BFS(int sr, int sc)
{
	P out;
	int i, j, nr, nc;
	int tmpcost;

	wp = rp = 0;
	que[wp++] = (P){ sr, sc, sd };
	cost[sr][sc] = 0;

	while (wp > rp) {
		out = que[rp++];
		if (out.r == er && out.c == ec) return out.d;

		for (i = 1; i <= 4; i++) {
			tmpcost = cost[out.r][out.c];
			if (tmpcost < out.cost) continue;
			nr = out.r + dr[i]; nc = out.c + dc[i];
			if (map[nr][nc]) continue;

			//cost
			if (i == cdir[out.d]) tmpcost += 3;
			else if (i == out.d) tmpcost += 1;
			else tmpcost += 2;

			//이동
			for (j = 1; j <= 3; j++)
			{
				if (map[nr][nc]) break;
				if (cost[nr][nc] > tmpcost || (cost[nr][nc] == tmpcost && i != out.d)) {
					cost[nr][nc] = tmpcost;
					que[wp++] = (P){ nr, nc, i, tmpcost };
				}
				nr += dr[i];
				nc += dc[i];
			}
		}
	}
}

int main()
{
	int sol, td;
	int i, j;

	input();
	td = BFS(sr, sc);
	sol = cost[er][ec];

	if (ed == cdir[td]) sol += 2;
	else if (td != ed) sol += 1;

	printf("%d", sol);
	return 0;
}