/*
출처 : 윌텍(codexpert.ort/willtek)
문제:
보물섬 지도를 발견한 후크 선장은 보물을 찾아 나섰다. 보물섬 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 각 칸은 육지(L)나 바다(W)로 표시되어 있다. 이 지도에서 이동은 상하좌우로 이웃한 육지로만 가능하며, 한 칸 이동하는데 한 시간이 걸린다.
보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다. 육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안된다.
보물 지도가 주어질 때, 보물이 묻혀 있는 두 곳 간의 최단 거리로 이동하는 시간을 구하는 프로그램을 작성하시오.

입력:
첫째 줄에는 보물 지도의 세로의 크기와 가로의 크기가 빈칸을 사이에 두고 주어진다.
이어 L과 W로 표시된 보물 지도가 아래의 예와 같이 주어지며, 각 문자 사이에는 빈 칸이 없다. 보물 지도의 가로, 세로의 크기는 각각 50이하이다.
출력:
첫째 줄에 보물이 묻혀 있는 두 곳 사이를 최단 거리로 이동하는 시간을 출력한다.
*/

#include <stdio.h>
#include <string.h>

#define MAX 55
int R, C;
char map[MAX][MAX];
int visit[MAX][MAX];

typedef struct xy{
	int r, c;
}POS;
POS que[MAX*MAX];
POS land[MAX*MAX];

int wp, rp;
int lwp, lrp;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
void inque(int i, int j)
{
	que[wp].r = i;
	que[wp].c = j;
	wp++;
}

void input(void)
{
	int i, j;
	scanf("%d %d", &R, &C);

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'L') {
				land[lwp].r = i;
				land[lwp].c = j;
				lwp++;
			}
		}
	}
}

int BFS(void)
{
	POS lout;
	POS out;
	int nr, nc, i;
	int max = 0;

	while (lwp > lrp)
	{
		lout = land[lrp++];
		wp = rp = 0;
		inque(lout.r, lout.c);
		visit[lout.r][lout.c] = 1;
		while (wp > rp) {
			out = que[rp++];
			for (i = 0; i < 4; i++) {
				nr = out.r + dr[i];
				nc = out.c + dc[i];

				if (map[nr][nc] == 'L' && visit[nr][nc] == 0) {
					inque(nr, nc);
					visit[nr][nc] = visit[out.r][out.c] + 1;

				}
			}
			if (max < visit[out.r][out.c]) max = visit[out.r][out.c];

		}
		memset(visit, 0, sizeof(visit));
	}
	return max - 1;
}

int main(void)
{
	int sol;
	input();
	sol = BFS();
	printf("%d", sol);

	return 0;
}