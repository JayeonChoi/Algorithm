/*
출처 : 삼성 SW Academy [모의 SW 역량테스트] #2115
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu
*/

#include <stdio.h>
#include <string.h>
int N, M, C, tmpC;
int map[15][15];
int visit[15][15];
int honey[7];
int ans;
int m;
int list[2];

void input()
{
	int i, j;

	memset(visit, 0, sizeof(visit));
	ans = 0;
	scanf("%d %d %d", &N, &M, &C);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void DFS_sub(int L, int profit, int start)
{
	//honey 배열에서 가장 이익이 큰 경우 구하기
	int i;
	if (L >= M) {
		if (profit>m) m = profit;
		return;
	}

	for (i = start; i < M; i++) {
		if (tmpC - honey[i] < 0) continue;
		tmpC -= honey[i];
		DFS_sub(L + 1, profit + honey[i] * honey[i], i + 1);
		tmpC += honey[i];
	}

	if (profit>m) m = profit;
}

void DFS(int L, int profit, int start, int comp)
{
	int i, j, k;
	int n;

	if (L >= 2) {
		if (profit > ans) {
			ans = profit;
		}
		return;
	}
	//------------------------------
	for (i = start; i <= N; i++) {
		for (j = 1; j <= N - M + 1; j++) {
			if (i == start && comp >= j) continue;
			if (visit[i][j]) continue;
			if (j + M - 1 > N) break;

			//벌꿀 채취가능한 경우마다 honey 배열 채우기
			n = 0;
			for (k = j; k <= j + M - 1; k++) {
				visit[i][k] = 1;
				honey[n++] = map[i][k];
			}
			m = 0; tmpC = C;
			DFS_sub(0, 0, 0);
			DFS(L + 1, profit + m, i, j + M - 1);
			for (k = j; k <= j + M - 1; k++) visit[i][k] = 0;
		}
	}
}


int main()
{
	int t, testcase;
	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		input();
		DFS(0, 0, 1, 0);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}