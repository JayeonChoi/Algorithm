/*
출처 : 백준 알고리즘 (6987번 월드컵)
https://www.acmicpc.net/problem/6987
*/

#include <stdio.h>
#define N 6
int win[N + 10], lose[N + 10], draw[N + 10];
int flag;
int match1[15];
int match2[15];

void DFS(int L)
{
	int a, b;
	if (flag) return;

	if (L >= 15) {
		int i;
		for (i = 0; i < 6; i++) {
			if (win[i]) return;
			if (lose[i]) return;
			if (draw[i]) return;
		}
		flag = 1;
	}
	//--------------------------------------------
	a = match1[L];
	b = match2[L];

	//a가 이긴 경우
	if (win[a] != 0 && lose[b] != 0) {
		win[a]--; lose[b]--;
		DFS(L + 1);
		win[a]++; lose[b]++;
	}

	//a와 b가 비긴 경우
	if (draw[a] != 0 && draw[b] != 0) {
		draw[a]--; draw[b]--;
		DFS(L + 1);
		draw[a]++; draw[b]++;
	}

	//b가 이긴 경우
	if (lose[a] != 0 && win[b] != 0) {
		lose[a]--; win[b]--;
		DFS(L + 1);
		lose[a]++; win[b]++;
	}
}

int main()
{
	int i, loop;
	int j, k = 0;

	for (i = 0; i < 5; i++) {
		for (j = i + 1; j < 6; j++) {
			match1[k] = i;
			match2[k++] = j;
		}
	}

	for (loop = 0; loop<4; loop++)
	{
		for (i = 0; i<N; i++)
		{
			scanf("%d %d %d", &win[i], &draw[i], &lose[i]);
		}

		flag = 0;
		DFS(0);

		if (flag) printf("1 ");
		else printf("0 ");
	}

	return 0;
}
