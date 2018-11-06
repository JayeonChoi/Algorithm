//문제
//이 게임에서 한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것이다.이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다.한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다. (실제 게임에서는 이동을 한 번 할 때마다 블록이 추가되지만, 이 문제에서 블록이 추가되는 경우는 없다)
//마지막으로, 똑같은 수가 세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.예를 들어, 위로 이동시키는 경우에는 위쪽에 있는 블록이 먼저 합쳐지게 된다. <그림 14>의 경우에 위로 이동하면 <그림 15>를 만든다.
//
//이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다.보드의 크기와 보드판의 블록 상태가 주어졌을 때, 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 보드의 크기 N(1 ≤ N ≤ 20)이 주어진다.둘째 줄부터 N개의 줄에는 게임판의 초기 상태가 주어진다. 0은 빈 칸을 나타내며, 이외의 값은 모두 블록을 나타낸다.블록에 쓰여 있는 수는 2보다 크거나 같고, 1024보다 작거나 같은 2의 제곱꼴이다.블록은 적어도 하나 주어진다.
//
//출력
//최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.

#include <stdio.h>
#include <string.h>

int N;
int map[25][25];
int ans;
int list[5];

void input()
{
	int i, j;
	scanf("%d", &N);
	ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void move(i)
{
	int max = 0;
	int r, c;
	int tmpr, tmpc;
	int visit[25][25] = { 0 };

	if (i == 0) {
		for (c = 1; c <= N; c++) {
			for (r = 2; r <= N; r++) {
				if (map[r][c] == 0) continue;
				tmpr = r - 1;
				while (tmpr != 1 && map[tmpr][c] == 0) {
					tmpr--;
				}
				if (map[r][c] == map[tmpr][c] && visit[tmpr][c] == 0) {
					map[tmpr][c] *= 2;
					map[r][c] = 0;
					visit[tmpr][c] = 1;
				}
				else {
					if (map[tmpr][c] == 0) {
						map[tmpr][c] = map[r][c]; map[r][c] = 0;
					}
					else if (tmpr + 1 != r) {
						map[tmpr + 1][c] = map[r][c]; map[r][c] = 0;
					}
				}
			}
		}
	}

	else if (i == 1) {
		for (c = 1; c <= N; c++) {
			for (r = N - 1; r >= 1; r--) {
				if (map[r][c] == 0) continue;
				tmpr = r + 1;
				while (tmpr != N && map[tmpr][c] == 0) {
					tmpr++;
				}
				if (map[r][c] == map[tmpr][c] && visit[tmpr][c] == 0) {
					map[tmpr][c] *= 2;
					map[r][c] = 0;
					visit[tmpr][c] = 1;
				}
				else {
					if (map[tmpr][c] == 0) {
						map[tmpr][c] = map[r][c]; map[r][c] = 0;
					}
					else if (tmpr - 1 != r) {
						map[tmpr - 1][c] = map[r][c]; map[r][c] = 0;
					}
				}
			}
		}
	}

	else if (i == 2) {
		for (r = 1; r <= N; r++) {
			for (c = 2; c <= N; c++) {
				if (map[r][c] == 0) continue;
				tmpc = c - 1;
				while (tmpc != 1 && map[r][tmpc] == 0) {
					tmpc--;
				}
				if (map[r][c] == map[r][tmpc] && visit[r][tmpc] == 0) {
					map[r][tmpc] *= 2;
					map[r][c] = 0;
					visit[r][tmpc] = 1;
				}
				else {
					if (map[r][tmpc] == 0) {
						map[r][tmpc] = map[r][c]; map[r][c] = 0;
					}
					else if (tmpc + 1 != c) {
						map[r][tmpc + 1] = map[r][c]; map[r][c] = 0;
					}
				}
			}
		}
	}

	else {
		for (r = 1; r <= N; r++) {
			for (c = N - 1; c >= 1; c--) {
				if (map[r][c] == 0) continue;
				tmpc = c + 1;
				while (tmpc != N && map[r][tmpc] == 0) {
					tmpc++;
				}
				if (map[r][c] == map[r][tmpc] && visit[r][tmpc] == 0) {
					map[r][tmpc] *= 2;
					map[r][c] = 0;
					visit[r][tmpc] = 1;
				}
				else {
					if (map[r][tmpc] == 0) {
						map[r][tmpc] = map[r][c];
						map[r][c] = 0;
					}
					else if (tmpc - 1 != c) {
						map[r][tmpc - 1] = map[r][c];
						map[r][c] = 0;
					}
				}
			}
		}
	}
}

int get_max()
{
	int max = 0;
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (map[i][j] > max) max = map[i][j];
		}
	}

	return max;
}

void printmap()
{
	int j, k;
	for (j = 1; j <= N; j++) {
		for (k = 1; k <= N; k++) {
			printf("%d ", map[j][k]);
		}
		printf("\n");
	}
}

void DFS(int L)
{
	int i;
	int tmpmap[25][25];
	int max;

	if (L >= 5) {
		max = get_max();
		if (max > ans) {
			ans = max;
		}
		return;
	}
	//----------------------------------------------

	for (i = 0; i < 4; i++) {
		memcpy(tmpmap, map, sizeof(map));
		list[L] = i;
		move(i);
		DFS(L + 1);
		list[L] = 0;
		memcpy(map, tmpmap, sizeof(map));
	}
}

int main()
{
	input();
	DFS(0);
	printf("%d", ans);
	return 0;
}