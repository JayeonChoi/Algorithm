/*
출처 : 삼성 SW Academy [모의 SW 역량테스트] 5653.줄기세포배양
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo
*/

#include <stdio.h>
#include <string.h>

int N, M, K;
int map[360][360];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int ncell;
typedef struct st {
	int r, c;
	int time;
	int life;
	int death;
} C;
C cell[5000];

void input()
{
	register int i, j;

	scanf("%d %d %d", &N, &M, &K);
	ncell = 0;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &map[i + 150][j + 150]);
			if (map[i + 150][j + 150] > 0) {
				cell[++ncell] = (C) { i + 150, j + 150, 0, map[i + 150][j + 150], 0 };
			}
		}
	}
}

int find_cell(int r, int c)
{
	register int i;
	for (i = 1; i <= ncell; i++) {
		if (cell[i].r == r && cell[i].c == c) return i;
	}
}

void time_goes()
{
	register int i, j;
	register int nr, nc, t;
	int tmp, tmp2;
	int temp;

	for (t = 1; t <= K; t++) {
		temp = ncell;
		for (i = 1; i <= temp; i++) {
			cell[i].time++;
			//번식
			if (cell[i].time == cell[i].life + 1) {
				tmp = cell[i].life;
				for (j = 0; j < 4; j++) {
					nr = cell[i].r + dr[j]; nc = cell[i].c + dc[j];
					tmp2 = map[nr][nc];
					if (tmp2 == 0) {
						map[nr][nc] = t * 10 + tmp;
						cell[++ncell] = (C){ nr, nc, 0, tmp };
					}
					else if ((tmp2 - 1) / 10 == t && tmp > tmp2 - t * 10) {
						int num;
						num = find_cell(nr, nc);
						cell[num].life = tmp;
					}
				}
			}
			//죽음
			if (cell[i].time == cell[i].life * 2) {
				cell[i].death = 1;
			}
		}

		//죽은세포 정리(살아있는 세포들이랑 교체)
		for (i = 1; i <= temp; i++) {
			if (cell[i].death == 1) {
				cell[i].death = 2;
				for (j = ncell; j > i; j--) {
					if (cell[j].death == 0) {
						C celltmp;
						celltmp = cell[i];
						cell[i] = cell[j];
						cell[j] = celltmp;
						break;
					}
				}
				ncell--;
			}
		}
	}
}

int main()
{
	int t, testcase;
	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		input();
		time_goes();
		printf("#%d %d\n", t, ncell);
		memset(map, 0, sizeof(map));
	}
	return 0;
}