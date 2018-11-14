/*
출처 : 윌텍(codexpert.ort/willtek)
문제:
최신 패션 트렌드가 가죽에 두 개의 점이 있는 암소라고 들은 농부 존은 두 개의 점이 있는 암소를 대량으로 구매를 했다. 불행하게도, 패션 트렌드가 빠르게 변해서 가장 인기 있는 현재 패션은 점이 하나 있는 암소이다.

존은 자신의 암소들을 현재 패션 트렌드에 맞게 바꾸고 싶다. 그래서 두 개의 점에 색을 칠해서 한 개의 점으로 만들려고 한다.
예를 들어 암소의 가죽이 N(세로) * M(가로) 크기의 격자로 아래와 같이 주어졌을 때:

................
..XXXX....XXX...
...XXXX....XX...
.XXXX......XXX..
........XXXXX...
.........XXX....

여기서 각각의 ‘X’는 점의 일부를 나타낸다. 두 ‘X’가 같은 점으로 취급되는 경우는 상하나 좌우로 연결되어 있을 때 이다. 대각선으로 연결된 것은 같은 점으로 보지 않는다. 그래서 위 그림은 정확히 두 점이다. 농부 존의 모든 암소는 정확히 두 점을 가지고 있다.

존은 두 점을 한 점으로 만들 때 최대한 적게 색칠하고 싶다. 위의 예에서 그는 3군데에 새로운 ‘X’를 추가하면 된다. (새로운 ‘X’는 ‘*’로 대체해서 쉽게 볼 수 있게 했다. 아래 그림 참조)

................
..XXXX....XXX...
...XXXX*...XX...
.XXXX..**..XXX..
........XXXXX...
.........XXX....

당신이 할 일은 농부 존이 두 개의 점을 병합해서 하나의 큰 점을 만들 수 있게 새로운 ‘X’의 최소 수를 정할 수 있게 도와주는 것이다.
*/

#include <stdio.h>
#include <string.h>

int N, M;
char map[55][55];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int flag;
typedef struct st{
	int r, c;
} P;
P que[2500];
int wp, rp;
int visit[55][55];
int visit2[55][55];
int ans;

void input()
{
	int i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%s", map[i] + 1);
	}
	flag = 0;
	ans = 0x7fffffff;
}

void BFS(int sr, int sc)
{
	int i, nr, nc;
	P out;
	wp = rp = 0;
	que[wp++] = (P){ sr, sc };
	visit[sr][sc] = flag;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i]; nc = out.c + dc[i];
			if (nr<1 || nc < 1 || nr>N || nc>M) continue;
			if (visit[nr][nc]) continue;
			if (map[nr][nc] == 'X') {
				visit[nr][nc] = flag;
				que[wp++] = (P){ nr, nc };
			}
		}
	}
}

int get_ans(int sr, int sc)
{
	int i, nr, nc;
	P out;
	wp = rp = 0;
	memset(visit2, 0, sizeof(visit2));
	que[wp++] = (P){ sr, sc };
	visit2[sr][sc] = 1;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i]; nc = out.c + dc[i];
			if (nr<1 || nc < 1 || nr>N || nc>M) continue;
			if (visit2[nr][nc]) continue;
			visit2[nr][nc] = visit2[out.r][out.c] + 1;
			que[wp++] = (P){ nr, nc };
			if (visit[nr][nc] == 2) return visit2[out.r][out.c] - 1;
		}
	}
}

void FF()
{
	int i, j;
	int min;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (map[i][j] == 'X' && visit[i][j] == 0) {
				flag++;
				BFS(i, j);
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (visit[i][j] == 1) {
				min = get_ans(i, j);
				if (ans > min) ans = min;
			}
		}
	}
}


int main()
{
	input();
	FF();
	printf("%d", ans);
	return 0;
}
