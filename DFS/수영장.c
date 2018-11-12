/*
출처 : 삼성 SW Academy [모의 SW 역량테스트] #1952
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq
*/

#include <stdio.h>
int ans;
int cost[4];
int use[12];

void input()
{
	int i;

	for (i = 0; i < 4; i++) scanf("%d", &cost[i]);
	for (i = 0; i < 12; i++) scanf("%d", &use[i]);
	ans = 0x7fffffff;
}

void DFS(int L, int c)
{
	int i;
	if (c >= ans) return;
	if (L >= 12) {
		if (ans>c) ans = c;
		return;
	}

	for (i = 0; i < 3; i++) {
		if (i == 2) {
			DFS(L + 3, c + cost[2]); //세달 이용하는 경우
		}
		else if (i == 1) {
			DFS(L + 1, c + cost[1]); //한달 이용하는 경우
		}
		else DFS(L + 1, c + cost[0] * use[L]); //1일권 이용하는 경우
	}
}

int main()
{
	int t, testcase;
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		DFS(0, 0);
		if (ans>cost[3]) ans = cost[3]; //1년 이용권과 비교
		printf("#%d %d\n", t, ans);
	}
	return 0;
}