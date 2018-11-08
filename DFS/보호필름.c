/*
출처 : 삼성 SW Expert Academy 모의 SW 역량테스트#2112
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu
*/

#include <stdio.h>
#include <string.h>
char film[15][25];
int D, W, K;
int flag;
char med_A[25];
char med_B[25];
char temp[15][25];

void input()
{
	int i, j;
	scanf("%d %d %d", &D, &W, &K);
	for (i = 1; i <= D; i++) {
		for (j = 1; j <= W; j++) {
			scanf(" %c", &film[i][j]);
		}
	}
	memcpy(temp, film, sizeof(temp));
	flag = 0;
}

void printfilm() //디버깅용
{
	int i, j;
	for (i = 1; i <= D; i++) {
		for (j = 1; j <= W; j++) {
			printf("%c", film[i][j]);
		}
		printf("\n");
	}
}

int check()
{
	int i, j;
	int cnt;
	char past;

	for (i = 1; i <= W; i++) {
		cnt = 1;
		past = film[1][i];
		for (j = 2; j <= D; j++) {
			if (film[j][i] == past) cnt++;
			else {
				past = film[j][i];
				cnt = 1;
			}
			if (cnt >= K) break;
		}
		if (cnt < K) return 0;
	}
	return 1;
}

void DFS(int L, int start, int min)
{
	int i;

	if (flag) return;
	if (L >= min) {
		flag = check();
		return;
	}
	//--------------------------------
	for (i = start; i <= D; i++) {
		strcpy(film[i] + 1, med_A);
		DFS(L + 1, i + 1, min);
		strcpy(film[i] + 1, temp[i] + 1);

		strcpy(film[i] + 1, med_B);
		DFS(L + 1, i + 1, min);
		strcpy(film[i] + 1, temp[i] + 1);
	}
}

int get_sol()
{
	int i;
	if (check()) return 0;
	for (i = 1; i <= K; i++) {
		DFS(0, 1, i);
		if (flag) return i;
	}
}
int main()
{
	int t, testcase;
	int i;
	int sol;

	scanf("%d", &testcase);
	for (i = 0; i <= 20; i++) {
		med_A[i] = '0';
		med_B[i] = '1';
	}

	for (t = 1; t <= testcase; t++) {
		input();
		//printfilm();
		sol = get_sol();
		printf("#%d %d\n", t, sol);
	}
	return 0;
}