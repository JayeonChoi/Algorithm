/*
출처 : 백준 알고리즘 2643번 색종이 올려 놓기
https://www.acmicpc.net/problem/2643
*/

#include <stdio.h>
int N;
typedef struct st {
	int r, c;
} P;
P rect[25];
int ans;
int visit[25];

void input()
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d %d", &rect[i].r, &rect[i].c);
	ans = 0;
}

void DFS(int L, int cnt, int topr, int topc)
{
	int i;

	if (ans >= cnt + N - L) return;
	if (L >= N) {
		if (cnt>ans) ans = cnt;
		return;
	}
	//-------------------------------
	for (i = 0; i < N; i++) {
		if (visit[i]) continue;
		if (rect[i].r <= topr && rect[i].c <= topc || rect[i].r <= topc && rect[i].c <= topr) {
			visit[i] = 1;
			DFS(L + 1, cnt + 1, rect[i].r, rect[i].c);
		}
		visit[i] = 0;
	}
	if (i == N) DFS(N, cnt, topr, topc);
}

int main(void)
{
	input();
	DFS(0, 0, 0x7fffffff, 0x7fffffff);
	printf("%d", ans);
	return 0;
}