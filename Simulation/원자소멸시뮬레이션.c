/*
출처 : 삼성 SW Academy [모의 SW 역량테스트] #5648
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRFInKex8DFAUo
*/

#include <stdio.h>
#include <string.h>
int N;
typedef struct info {
	int r, c;
	int dir;
	int energy;
	int death;
} A;
typedef struct pos {
	int r, c;
} P;
P pose[800];
A atom[1010];
int map[2010][2010];
int ans;
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int cdir[] = { 1, 0, 3, 2 };

void input()
{
	register int i;
	ans = 0;
	scanf("%d", &N);
	memset(map, 0, sizeof(map));

	for (i = 1; i <= N; i++) {
		scanf("%d %d %d %d", &atom[i].c, &atom[i].r, &atom[i].dir, &atom[i].energy);
		atom[i].death = 0;
		atom[i].r += 1000; atom[i].c += 1000;
		map[atom[i].r][atom[i].c] = i;
	}
}

void collision()
{
	register int i, j;
	int nr, nc;
	int catom;
	int d;
	int tmp;

	catom = N;
	for (i = 1; i <= 2001; i++) {
		if (catom == 0) break;
		for (j = 1; j <= N; j++) {
			if (atom[j].death) continue;
			d = atom[j].dir;
			nr = atom[j].r + dr[d]; nc = atom[j].c + dc[d];
			if (nr < 0 || nc < 0 || nr>2000 || nc>2000) {
				atom[j].death = 1; catom--;
				continue;
			}

			if (map[atom[j].r][atom[j].c] == j) {
				map[atom[j].r][atom[j].c] = 0;
			}

			tmp = map[nr][nc];
			//이동중 충돌
			if (j < tmp && cdir[d] == atom[tmp].dir) {
				atom[tmp].death = atom[j].death = 1;
				ans += atom[tmp].energy;
				ans += atom[j].energy;
				map[nr][nc] = 0;
				catom -= 2;
			}
			//이동
			map[nr][nc] = j;
			atom[j].r = nr; atom[j].c = nc;
		}

		//충돌 원자 정리
		for (j = 1; j <= N; j++) {
			int temp = map[atom[j].r][atom[j].c];
			if (atom[j].death) continue;
			if (temp != j) {
				if (temp) {
					ans += atom[temp].energy;
					ans += atom[j].energy;
					atom[temp].death = 1;
					atom[j].death = 1;
					map[atom[j].r][atom[j].c] = 0;
					catom -= 2;
				}
				else {
					ans += atom[j].energy;
					atom[j].death = 1;
					catom--;
				}
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
		collision();
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
