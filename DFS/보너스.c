/*
출처 : 윌텍(codexpert.org/willtek)-보너스

<문제>
중소기업인 K 회사에서 직원들에게 보너스를 지급하려고 한다.
그런데 직원들의 자존심이 강해서 상급자들이 직급이 낮은 사람보다는 한 푼이라도 더 받기를 원한다.
단, 자기랑 직접적 관련이 없는 사람의 보너스 금액에는 관심 없다.
중소기업 특성상 정확한 직급이 존재하지 않고 누가 누구 상급자고 하급자인지만 정해져 있는 상황에서 사장은 골치가 아프다.
예를 들어 아래와 같은 조직인 경우에는 아래와 같다.
편의상 이름은 숫자로 대체한다.
1은 언제나 사장이다.
5명이 있고 보너스 금액은 51, 30, 35, 30, 31 일 경우 1번부터 51, 35, 31, 30, 30으로 배정하면 된다.
중소기업 사장을 도와서 모두가 만족할 수 있는 보너스 금액을 배정하자

<입력>
첫 줄에 N과 M이 입력된다. N은 직원 수 (3≤N≤10), M은 상하관계의 개수(2≤M≤100) 이다.
다음 줄부터 M줄에 걸쳐 상하관계가 입력된다. 각 줄에는 상급자 하급자 순으로 입력되며 공백으로 구분된다. (상하관계 오류가 발생하는 입력은 없음)
마지막 줄에는 보너스 금액이 N개만큼 공백으로 구분되어 입력된다. 보너스 금액은 1이상 1,000,000 이하 이다.

<출력>
1번부터 N번까지 순서대로 공백으로 구분하여 보너스 금액을 출력한다. (답이 여러 개일 경우 그 중 한가지만 출력하면 됨)
*/

#include <stdio.h>
#include <stdlib.h>
int N, M;
int map[15][15];
int money[15];
int ans[15];
int sol;

int compare_int(const int *a, const int *b)
{
	return *b - *a;
}

void input()
{
	int i;
	int tr, tc;

	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &tr, &tc);
		map[tr][tc] = 1;
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &money[i]);
	}
	//money 내림차순하기
	qsort(money, N, sizeof(int), compare_int);
}

int check(int node, int L)
{
	int i;
	for (i = 1; i <= N; i++) {
		if (map[i][node] == 0) continue;
		if (ans[i] == 0 || ans[i] <= money[L]) return 0;
	}
	return 1;
}
void DFS(int L)
{
	int i, j;

	if (sol == 1) return;
	if (L == N) {
		for (j = 1; j <= N; j++) printf("%d ", ans[j]);
		sol = 1;
		return;
	}
	//-------------------------
	for (i = 1; i <= N; i++) {
		if (ans[i]) continue;
		if (check(i, L)) {
			ans[i] = money[L];
			DFS(L + 1);
			ans[i] = 0;
		}
	}
}

int main(void)
{
	input();
	ans[1] = money[0];
	DFS(1);
	return 0;
}
