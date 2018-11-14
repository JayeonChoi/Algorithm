/*
출처 : 윌텍(codexpert.ort/willtek)

<문제>
N개의 노드로 구성된 그래프의 정보가 주어지고, 숫자 M이 주어진다. 이 때, 서로 인접한 노드들 간에는 같은 색을 칠하지 않으면서 M개의 색으로 N개의 노드를 전부 칠할 수 있는지 판단하라. 가능한 경우에는 첫 번째 노드부터 색상 번호(1 ~ M에서 선택)를 출력하고, 불가능한 경우 -1을 출력한다.

노드1부터 순서대로 색을 칠해야 하며 색상 번호도 낮은 번호부터 붙여 나가야 한다.  주어진 색상을 모두 사용할 필요는 없으며 가능하면 낮은 색상 번호를 사용하여 완성하라. 즉, 6개의 색이 주어졌어도 5개의 색으로 모두 칠할 수 있으면 5개색만 사용하여야 한다.

그래프 정보는 triangular matrix로 주어지고, 연결되어 있는 경우 1, 연결되어 있지 않은 경우 0으로 주어진다.

<입력>
첫 줄에 노드 수 N(1≤N≤12)와 색상 번호 M(1≤M≤12)가 주어진다.
<출력>
노드1부터의 칠해진 색상 번호 리스트를 출력한다.
불가능한 경우 -1을 출력한다.
*/

#include <stdio.h>
#define MAX 15
int N;
int M;
int map[MAX][MAX];
int ans[MAX];
int list[MAX];
int flag;
void input()
{
	int i, j;

	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &map[i][j]);
			map[j][i] = map[i][j];
		}
	}
}

void printlist(int L)
{
	int i;
	for (i = 1; i < L; i++) printf("%d ", ans[i]);
	printf("\n");
}

void DFS(int L, int color)
{
	int i, j;
	int check[MAX] = { 0 };

	if (flag == 1) return;
	if (L > N) {
		printlist(L);
		flag = 1;
		return;
	}

	//------------------------------
	for (i = 1; i < L; i++) {
		if (map[L][i]) check[ans[i]] = 1;
	}

	for (j = 1; j < color; j++) {
		if (check[j]) continue;
		ans[L] = j;
		DFS(L + 1, color);
	}

	if (color <= M) {
		ans[L] = color;
		DFS(L + 1, color + 1);
	}
}

int main(void)
{
	input();
	flag = 0;
	DFS(1, 1);
	if (!flag) printf("%d", -1);
	return 0;
}