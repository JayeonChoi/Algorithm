/*
출처: 백준 알고리즘(삼성 알고리즘 테스트 기출)
https://www.acmicpc.net/problem/15683
*/

#include <stdio.h>
#include <string.h>

int N, M;
int map[10][10];
int cam;
int bspot;
int min;
int ndir[6] = { 0, 4, 2, 4, 4, 1 };
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

typedef struct pos
{
	int num;
	int r, c;
} P;
P camera[10];

typedef struct _dir
{
	int dir[4][4];
} D;
D lookup[6];

void input()
{
	int i, j;

	scanf("%d %d", &N, &M);
	cam = 0;
	bspot = 0;
	min = 0x7fffffff;
	memset(map, 0, sizeof(map));

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				camera[cam++] = (P) { map[i][j], i, j };
			}
			if (!map[i][j]) bspot++;
		}
	}

	//6으로 벽 두르기
	for (i = 0; i <= N + 1; i++) {
		for (j = 0; j <= M + 1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
				map[i][j] = 6;
			}
		}
	}
}

int get_spot(int n, int d)
{
	int ncam, i;
	int nr, nc;
	int sr, sc;
	int spot = 0;

	ncam = camera[n].num;
	sr = camera[n].r; sc = camera[n].c;

	for (i = 0; i < 4; i++) {
		if (lookup[ncam].dir[d][i] == 0) continue;
		nr = sr + dr[i]; nc = sc + dc[i];
		while (map[nr][nc] != 6) {
			if (map[nr][nc] == 0) {
				map[nr][nc] = -1;
				spot++;
			}
			nr += dr[i]; nc += dc[i];
		}
	}
	return spot;
}


void DFS(int nc, int blindspot)
{
	int i;
	int tempmap[10][10];
	int n;

	if (nc >= cam) {
		if (min > blindspot) min = blindspot;
		return;
	}
	//------------------------------------
	n = ndir[camera[nc].num];

	for (i = 0; i < n; i++) {
		int spot;
		memcpy(tempmap, map, sizeof(map));
		spot = get_spot(nc, i);
		DFS(nc + 1, blindspot - spot);
		memcpy(map, tempmap, sizeof(map));
	}
}

int main()
{
	lookup[1] = (D) { {{1, 0, 0, 0}, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 }} };
	lookup[2] = (D) { {{0, 0, 1, 1}, { 1, 1, 0, 0 }} };
	lookup[3] = (D) { {{1, 0, 0, 1}, { 1, 0, 1, 0 }, { 0, 1, 0, 1 }, { 0, 1, 1, 0 }} };
	lookup[4] = (D) { {{1, 1, 1, 0}, { 1, 1, 0, 1 }, { 1, 0, 1, 1 }, { 0, 1, 1, 1 }} };
	lookup[5] = (D) { {1, 1, 1, 1} };

	input();
	DFS(0, bspot);
	printf("%d", min);

	return 0;
}