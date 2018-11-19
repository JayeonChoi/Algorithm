/*
삼성 SW 아카데미(난이도 D3: N-Queen)
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GKs06AU0DFAXB
*/
#include <stdio.h>
#define MAX 15

int N;
int visit[MAX];
int list[MAX] = { 15, };
int sol;
int flag;
int k;
int d1[MAX + MAX];
int d2[MAX + MAX];

void printlist(int L){
	int i;
	for (i = 1; i < L; i++) printf("%d ", list[i]);
	printf("\n");
}

void input()
{
	scanf("%d", &N);
}

int abs(int a)
{
	return a >= 0 ? a : -a;
}

void DFS(int L)
{
	register int i;

	if (flag && list[1] > k) return;
	if (L > N) {
		sol++;
		return;
	}

	//---------------------------------------------
	for (i = 1; i <= N; i++) {

		if (visit[i]) continue;
		if (d1[L - i + N] || d2[L + i]) continue; //visit 배열(대각선)
		visit[i] = 1;
		list[L] = i;
		d1[L - i + N] = 1;
		d2[L + i] = 1;
		DFS(L + 1);
		d1[L - i + N] = 0;
		d2[L + i] = 0;
		visit[i] = 0;
		list[L] = 0;
	}
}

int main()
{
	int t, testcase;
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		scanf("%d", &N);
		sol = 0;

		flag = N % 2 == 0 ? 1 : 0;
		k = N / 2;
		DFS(1);
		if (flag) sol *= 2;
		printf("#%d %d\n", t, sol);
	}

}