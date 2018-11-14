/*
출처 : 윌텍(codexpert.ort/willtek)

<문제>
올해도 치즈 공장들이 치즈 생산을 시작하자, 쥐가 둥지에서 얼굴을 내밀었다. 마을은 동서남북으로 구획 정리가 되어 있고, 각 구획은 둥지, 치즈 공장, 장애물, 공터 중 하나이다. 쥐는 둥지에서 출발하여 모든 치즈 공장을 방문하여 치즈를 1개씩 먹는다.

이 마을에는 N개의 치즈 공장이 있고, 공장마다 1종류의 치즈만 생산하고 있다. 치즈의 경도는 공장에 따라 다르고 경도 1에서 N까지의 치즈를 생산하는 치즈 공장이 각각 하나씩 있다.

쥐의 초기 체력은 1이며, 치즈를 1개 먹을 때마다 체력이 1씩 증가한다. 그러나 쥐는 자신의 체력보다 딱딱한 치즈를 먹을 수 없다.

쥐는 동서남북에 인접한 구획만 이동할 수 있으며 1분이 소요된다. 장애물 구획에는 들어 갈 수 없다. 치즈 공장 치즈를 먹지 못하고 지나갈 수 있다. 모든 치즈를 먹고 끝내는 데 걸리는 최소 시간을 프로그램을 작성하라. 쥐가 치즈를 먹는데 걸리는 시간은 무시한다.

<입력>
첫 번째 줄에 세 개의 정수 H, W, N (1≤H≤1000, 1≤W≤1000, 1≤N≤9)이 공백으로 구분되어 순서대로 입력된다.
두 번째 줄부터 H줄에 걸쳐 W개로 구성된 문자열이 입력된다. 문자열은 각각의 구획의 상태를 나타낸다. 둥지는 ‘S’, 장애물은 ‘X’, 공터는 ‘.’, 치즈 공장은 경도를 나타내는 ‘1’, ‘2’, …, ‘9’로 표시된다.
입력에 둥지와 경도 1, 2, …, N 치즈를 생산하는 공장은 각각 하나씩만 존재한다. 그 외에는 장애물이나 공터뿐이다. 쥐는 모든 치즈를 먹을 수 있다.

<출력>
모든 치즈를 먹고 끝내는 데 걸리는 최소 시간(분)을 나타내는 정수를 한 줄로 출력한다.
*/

#include <stdio.h>
#define MAX 1010

int R, C;
char map[MAX][MAX];
int visit[MAX][MAX];
int N;
int sr, sc;
int er, ec;
typedef struct xy {
	int r, c;
} P;
P que[MAX*MAX * 10];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int wp, rp;
int sol;

void input()
{
	int i, j;

	scanf("%d %d", &R, &C);
	scanf("%d", &N);

	for (i = 0; i <= R + 1; i++) {
		for (j = 0; j <= C + 1; j++) {
			map[i][j] = 'X';
		}
	}

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {
				sr = i;
				sc = j;
			}
		}
	}
}

void init_visit(void)
{
	int i, j;

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			visit[i][j] = 0;
		}
	}
}

int BFS(int sr, int sc, int k)
{
	int nr, nc, i;
	P out;

	wp = rp = 0;
	que[wp++] = (P) { sr, sc };
	visit[sr][sc] = 1;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i];
			nc = out.c + dc[i];
			if (map[nr][nc] != 'X' && visit[nr][nc] == 0) {
				visit[nr][nc] = visit[out.r][out.c] + 1;
				que[wp++] = (P){ nr, nc };
				if (map[nr][nc] == k + '0') {
					er = nr;
					ec = nc;
					visit[nr][nc] = visit[out.r][out.c] + 1;
					return visit[er][ec] - 1;
				}
			}
		}
	}
	return visit[er][ec] - 1;
}

int main(void)
{
	int i;
	input();
	sol = 0;
	for (i = 1; i <= N; i++) {
		sol += BFS(sr, sc, i);
		sr = er;
		sc = ec;
		init_visit();
	}
	printf("%d", sol);
	return 0;
}
