/*
출처 : 윌텍(codexpert.ort/willtek)

문제:
철수의 농장은 N*N 크기이며 목초지들로 구성되어 있다. 각 목초지는 두 가지 유형의 풀 중 하나가 자라고 있다. 두 가지 유형의 풀을 ‘(‘ 와 ‘)’ 문자로 표현할 것이다. 예를 들어 철수의 농장이 4*4 크기라면 다음과 같이 표현할 수 있다.

(())
)()(
)(((
))))

암소가 농장을 돌아다닐 때, 인접한(즉, 동서남북 한 칸) 같은 유형의 풀이 자라는 목초지로 이동하는 시간을 A라고 하고, 인접한 다른 유형의 풀이 자라는 목초지로 이동하는 시간을 B라고 한다. 암소는 항상 한 목초지에서 다른 목초지로 이동할 때, 최소 시간이 걸리는 경로로 이동을 한다.

철수는 암소를 운동시키기 위해 어떤 목초지에서 출발시켜 다른 먼 목초지에 도착하게 하려고 한다. 이때, 암소를 가장 많이 걷게 할 수 있는 시간을 구하시오.
*/

#include <stdio.h>
#include <string.h>

int N, A, B;
int ans;
char map[35][35];
int visit[35][35];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
typedef struct st{
	int r, c;
}P;
P que[35 * 35 * 10];
int wp, rp;

void input()
{
	int i;
	scanf("%d %d %d", &N, &A, &B);
	for (i = 1; i <= N; i++) {
		scanf("%s", map[i] + 1);
	}
	ans = 0;
}

void BFS(int sr, int sc)
{
	int i, j, nr, nc;
	P out;
	int tmp;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			visit[i][j] = 0x7fffffff;
		}
	}
	wp = rp = 0;
	que[wp++] = (P){ sr, sc };
	visit[sr][sc] = 0;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i]; nc = out.c + dc[i];
			if (nr<1 || nc < 1 || nr>N || nc>N) continue;
			if (map[out.r][out.c] == map[nr][nc]) tmp = visit[out.r][out.c] + A;
			else tmp = visit[out.r][out.c] + B;
			if (visit[nr][nc] > tmp) {
				visit[nr][nc] = tmp;
				que[wp++] = (P){ nr, nc };
			}
		}
	}
}

int get_ans()
{
	int i, j, k, l;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			BFS(i, j);
			for (k = 1; k <= N; k++) {
				for (l = 1; l <= N; l++) {
					if (visit[k][l] > ans) ans = visit[k][l];
				}
			}
		}
	}
	return ans;
}

int main()
{
	int t, testcase;
	int sol;
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		sol = get_ans();
		printf("%d\n", sol);
	}
	return 0;
}
