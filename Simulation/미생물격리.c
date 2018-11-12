/*
출처 : 삼성 SW Academy [모의 SW 역량테스트] #2382
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl
*/

#include <stdio.h>
int N, M, K; //맵 크기, 시간, 군집개수
int dr[] = { 0, -1, 1, 0, 0 }; //상,하,좌,우
int dc[] = { 0, 0, 0, -1, 1 };
int map[110][110];
typedef struct st {
	int r, c;
	int num;
	int dir;
	int max;
} info;
info micro[1010];

void input()
{
	register int i;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= K; i++) {
		scanf("%d %d %d %d", micro[i].r, micro[i].c, micro[i].num, micro[i].dir);
		map[micro[i].r][micro[i].c] = i;
		micro[i].max = micro[i].num;
	}
}

void move()
{
	register int i, j;
	int nr, nc, d, w;

	for (i = 0; i < M; i++) {
		for (j = 1; j <= K; j++) {
			if (!micro[j].num) continue;
			d = micro[j].dir;
			nr = micro[j].r + dr[d];
			nc = micro[j].c + dc[d];
			w = map[nr][nc];
			if (map[micro[j].r][micro[j].c] == j) {
				map[micro[j].r][micro[j].c] = 0;
			}
			micro[j].r = nr; micro[j].c = nc;

			//상대 군집
			if (w != 0 && w < j) {
				if (micro[w].max > micro[j].max) {
					micro[w].num += micro[j].num;
					micro[j].num = 0;
				}
				else {
					micro[j].num += micro[w].num;
					micro[w].num = 0;
					map[nr][nc] = j;
				}
			}

			//약품
			else if (nr == 0 || nc == 0 || nr == N - 1 || nc == N - 1) {
				if (d % 2 == 1) d += 1;
				else d -= 1;
				map[nr][nc] = j;
				micro[j].dir = d;
				micro[j].num /= 2;
			}

			//그외(그냥 이동)
			else {
				map[nr][nc] = j;
			}
		}

		//max 갱신
		for (j = 1; j <= K; j++) {
			if (!micro[j].num) continue;
			micro[j].max = micro[j].num;
		}
	}
}

int get_ans()
{
	register int i;
	int ans = 0;
	for (i = 1; i <= K; i++) {
		ans += micro[i].num;
	}
	return ans;
}

void init_map()
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
}

int main()
{
	int t, testcase;
	int sol;

	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		move();
		sol = get_ans();
		printf("#%d %d\n", t, sol);
		init_map();
	}
	return 0;
}