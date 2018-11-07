/*
출처: 백준 알고리즘(삼성 알고리즘 테스트 기출)
https://www.acmicpc.net/problem/15686



문제


크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. r과 c는 1부터 시작한다.

이 도시에 사는 사람들은 치킨을 매우 좋아한다. 따라서, 사람들은 "치킨 거리"라는 말을 주로 사용한다. 치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다. 즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다. 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.

임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.

예를 들어, 아래와 같은 지도를 갖는 도시를 살펴보자.
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2


0은 빈 칸, 1은 집, 2는 치킨집이다.

(2, 1)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |2-1| + |1-2| = 2, (5, 5)에 있는 치킨집과의 거리는 |2-5| + |1-5| = 7이다. 따라서, (2, 1)에 있는 집의 치킨 거리는 2이다.

(5, 4)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |5-1| + |4-2| = 6, (5, 5)에 있는 치킨집과의 거리는 |5-5| + |4-5| = 1이다. 따라서, (5, 4)에 있는 집의 치킨 거리는 1이다.

이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다. 오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.

도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.




입력


첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.

둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.

도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.




출력


첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.

*/

#pragma warning (disable:4996)
#include <stdio.h>
int N;
int M;
int map[55][55];
int chicr[15];
int chicc[15];
int visit[15];
int houser[110];
int housec[110];
int c = 1, h = 1;
int min;

void input()
{
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				chicr[c] = i;
				chicc[c++] = j;
			}
			else if (map[i][j] == 1) {
				houser[h] = i;
				housec[h++] = j;
			}
		}
	}
	min = 0x7fffffff;
}

int abs(int a)
{
	return a >= 0 ? a : -a;
}

int get_dist()
{
	int i, j;
	int d;
	int minsum = 0;

	for (i = 1; i < h; i++) {
		int mindist = 0x7fffffff;
		for (j = 1; j < c; j++) {
			if (!visit[j]) continue;
			d = abs(chicc[j] - housec[i]) + abs(chicr[j] - houser[i]);
			if (mindist>d) mindist = d;
		}
		minsum += mindist;
	}

	return minsum;
}
void DFS(int L, int start)
{
	int i;
	if (L > M) {
		int dist;
		dist = get_dist();
		if (min > dist) min = dist;
		return;
	}
	//--------------------
	for (i = start; i < c; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		DFS(L + 1, i + 1);
		visit[i] = 0;
	}
}
int main()
{
	input();
	DFS(1, 1);
	printf("%d", min);
	return 0;
}