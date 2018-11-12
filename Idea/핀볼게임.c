/*
출처 : 삼성 SW Academy [모의 SW 역량테스트] #5650
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo
*/


#include <string.h>
#include <stdio.h>
int N;
int map[110][110];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int block[6][4] = { { 1, 0, 3, 2 }, { 1, 3, 0, 2 }, { 3, 0, 1, 2 }, { 2, 0, 3, 1 }, { 1, 2, 3, 0 }, { 1, 0, 3, 2 } };
struct st {
	int r1, c1;
	int r2, c2;
};
struct st wormhole[15];

void input()
{
	register int i, j;
	int tmp;
	scanf("%d", &N);
	memset(wormhole, 0, sizeof(wormhole));

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &tmp);
			map[i][j] = tmp;
			if (tmp > 5) {
				if (wormhole[tmp].r1 == 0) {
					wormhole[tmp].r1 = i;
					wormhole[tmp].c1 = j;
				}
				else {
					wormhole[tmp].r2 = i;
					wormhole[tmp].c2 = j;
				}
			}
		}
	}
}

int pinball(int sr, int sc, int dir)
{
	register int r, c;
	int nr, nc;
	int score = 0;
	int tmp;
	r = sr; c = sc;

	do {
		nr = r + dr[dir]; nc = c + dc[dir];
		tmp = map[nr][nc];
		//벽인 경우
		if (nr == 0 || nc == 0 || nr>N || nc>N) {
			dir = block[0][dir];
			r = nr; c = nc;
			score++;
		}
		//블랙홀, 빈공간
		else if (tmp == 0 || tmp == -1) { r = nr; c = nc; }
		//블록일 때
		else if (tmp <= 5) {
			dir = block[tmp][dir];
			score++;
			r = nr; c = nc;
		}
		//웜홀일때
		else {
			if (nr == wormhole[tmp].r1 && nc == wormhole[tmp].c1) {
				r = wormhole[tmp].r2; c = wormhole[tmp].c2;
			}
			else {
				r = wormhole[tmp].r1; c = wormhole[tmp].c1;
			}
		}
	} while (tmp != -1 && (r != sr || c != sc));

	return score;
}

int get_ans()
{
	register int i, j, k;
	int max = 0;
	int score;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (map[i][j]) continue;
			for (k = 0; k < 4; k++) {
				score = pinball(i, j, k);
				if (score > max) max = score;
			}
		}
	}

	return max;
}


int main()
{
	int t, testcase;
	int sol;
	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		input();
		sol = get_ans();
		printf("#%d %d\n", t, sol);
	}
	return 0;
}