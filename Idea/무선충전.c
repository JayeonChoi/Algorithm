/*
출처 : 삼성 SW Academy [모의 SW 역량테스트] #5644
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRDL1aeugDFAUo
*/

#include <stdio.h>
#include <string.h>

int M, A;
int Amove[110], Bmove[110];
int dr[] = { 0, -1, 0, 1, 0 };
int dc[] = { 0, 0, 1, 0, -1 };
int map[11][11];
typedef struct charger {
	int r, c;
	int charge;
	int P;
	int num;
} B;
typedef struct pinfo {
	int r, c;
	int time;
} P;
B bat[10];
P people[2];

void input()
{
	int i, j, k;
	B temp;
	people[0] = (P) { 1, 1, 0 };
	people[1] = (P) { 10, 10, 0 };
	memset(map, 0, sizeof(map));
	scanf("%d %d", &M, &A);
	for (i = 1; i <= M; i++) scanf("%d", &Amove[i]);
	for (i = 1; i <= M; i++) scanf("%d", &Bmove[i]);
	for (i = 1; i <= A; i++) {
		scanf("%d %d %d %d", &bat[i].c, &bat[i].r, &bat[i].charge, &bat[i].P);
		bat[i].num = i;
	}

	//P에 따라 정렬
	for (i = 1; i < A; i++) {
		for (j = i + 1; j <= A; j++) {
			if (bat[i].P > bat[j].P) {
				temp = bat[i];
				bat[i] = bat[j];
				bat[j] = temp;
			}
		}
	}
	//마름모 그리기
	for (i = 1; i <= A; i++) {
		int centr, centc, cnt;
		centr = bat[i].r; centc = bat[i].c; cnt = -1;
		for (j = centr - bat[i].charge; j <= centr + bat[i].charge; j++) {
			if (j <= centr) cnt += 2;
			else cnt -= 2;
			if (j < 1 || j>10) continue;
			for (k = centc - cnt / 2; k <= centc + cnt / 2; k++) {
				if (k < 1 || k>10) continue;
				if (!map[j][k]) map[j][k] = i;
				else map[j][k] = map[j][k] * 10 + i;
			}
		}
	}
}

//디버깅용
void printmap()
{
	int i, j;
	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= 10; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void get_time(int n1, int n2)
{
	int i, j;
	int a, b;
	int max = 0;
	int tmpa, tmpb, t1, t2;
	int arrA[10] = { 0 }, arrB[10] = { 0 };

	i = 0;
	for (; n1 != 0;) {
		arrA[i++] = n1 % 10;
		n1 /= 10;
	}
	j = 0;
	for (; n2 != 0;) {
		arrB[j++] = n2 % 10;
		n2 /= 10;
	}

	if (i == 0) {
		people[1].time += bat[arrB[0]].P;
		return;
	}
	if (j == 0) {
		people[0].time += bat[arrA[0]].P;
		return;
	}

	//경우의 수 비교
	for (a = 0; a < i; a++) {
		for (b = 0; b < j; b++) {
			if (arrA[a] != arrB[b]) {
				t1 = bat[arrA[a]].P; t2 = bat[arrB[b]].P;
			}
			else {
				t1 = t2 = bat[arrA[a]].P / 2;
			}
			if (t1 + t2 > max) {
				max = t1 + t2;
				tmpa = t1; tmpb = t2;
			}
		}
	}

	people[0].time += tmpa;
	people[1].time += tmpb;
	return;
}

int move()
{
	int i;
	int dir1, dir2;
	int n1, n2;

	for (i = 0; i <= M; i++) {
		dir1 = Amove[i]; dir2 = Bmove[i];
		people[0].r += dr[dir1]; people[0].c += dc[dir1];
		people[1].r += dr[dir2]; people[1].c += dc[dir2];
		n1 = map[people[0].r][people[0].c]; n2 = map[people[1].r][people[1].c];
		//둘다 배터리 영역x
		if (!n1 && !n2) continue;
		//같은 배터리 영역
		if (n1 == n2) {
			if (n1 < 10) {
				people[0].time += bat[n1].P / 2;
				people[1].time += bat[n1].P / 2;
			} //둘다 한개 영역만 있음
			else {
				people[0].time += bat[n1 % 10].P;
				people[1].time += bat[n1 / 10 % 10].P;
			} //둘다 둘이상
		}
		//다른 배터리 영역
		else {
			if (n1 < 10 && n2 < 10) {
				people[0].time += bat[n1].P;
				people[1].time += bat[n2].P;
			}
			else {
				get_time(n1, n2);
			}
		}
		//printf("T : %d, Atime : %d , Btime : %d\n", i, people[0].time, people[1].time);
	}

	return people[0].time + people[1].time;
}

int main()
{
	int t, testcase;
	int sol;
	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		input();
		//printmap();
		sol = move();
		printf("#%d %d\n", t, sol);
	}
	return 0;
}