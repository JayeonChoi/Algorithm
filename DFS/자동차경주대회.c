/*
출처 : 윌텍(codexpert.ort/willtek)

<문제>
전국 자동차 경주 대회가 매년 열리고 있다. 이 대회에서는 출발지점부터 도착지점까지 거리가 워낙 멀기 때문에 경주 도중에 각 자동차는 정비소를 방문하여 정비를 받아야 한다. 정비소들은 출발지점에서 도착지점으로 가는 길가에 있으며 ①번부터 차례로 번호가 붙어 있다.

이 대회에서는 참가하는 선수의 안전을 위하여 정비를 받지 않고 미리 정한 거리를 초과하여 갈 수 없도록 규칙을 정하였다. 그리고 정비소마다 정비하는데 걸리는 정비 시간이 서로 다를 수 있다.

정비소에서 정비하는데 걸리는 시간을 가장 적게 하려고 할 때 최소 총 정비시간과 방문하는 정비소들을 구하는 프로그램을 작성하시오.

정비할 때 걸리는 시간은 5분이다.

<입력>
입력 시 첫째 줄에는 정비를 받지 않고 갈 수 있는 최대 거리가 주어진다. 둘째 줄에는 정비소의 개수가 입력되는데 정비소 수는 50개 이하이다. 셋째 줄에는 인접한 정비소 사이의 거리가 차례로 주어진다. 넷째 줄에는 정비소 별 정비 시간이 차례로 주어진다. 모든 입력은 양의 정수이다.
<출력>
첫째 줄에 정비소에서 정비하는데 걸리는 총 정비 시간을 출력한다. 둘째 줄에 방문하는 정비소의 개수를 출력한다. 셋째 줄에는 방문하는 정비소의 번호를 한 줄에 차례로 출력하며 정비소 번호 사이에 빈칸을 하나씩 넣는다. 정비소를 전혀 방문하지 않아도 되는 경우에 총 정비 시간은 0이고 정비소 개수와 정비소 번호는 출력하지 않는다.

*/

#include <stdio.h>
#define MAX 60

int K, N;
int t[MAX];
int d[MAX];
int list[MAX];
int m;
int ans[MAX];

void printlist(int L, int ts, int ds)
{
	int i;

	printf("ts : %2d ds :%2d : ", ts, ds);
	for (i = 0; i < L; i++) {
		printf("%2d ", list[i]);
	}
	printf("\n");
}


void input()
{
	int i;
	scanf("%d %d", &K, &N);

	for (i = 0; i <= N; i++) {
		scanf("%d", &d[i]);
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &t[i]);
		m += t[i];
	}
	m++;
}

void DFS(int L, int tS, int dS)
{
	int i;

	if (m <= tS) return;
	if (L > N) {
		//printlist(L, tS, dS); //디버깅용
		if (tS < m) {
			for (i = 1; i <= N; i++) {
				ans[i] = list[i];
			}
			m = tS;
		}
		return;
	}
	//----------------------------------
	if (dS + d[L] <= K) {
		list[L] = 0;
		DFS(L + 1, tS, dS + d[L]); //정비 받지 않는 경우
	}
	list[L] = L;
	DFS(L + 1, tS + t[L], d[L]); //무조건 정비 받아야함
}

int main(void)
{
	int i;
	int k = 0;

	m = 0;
	input();
	DFS(1, 0, d[0]);
	printf("%d\n", m);

	if (m != 0) {
		for (i = 0; i <= N; i++) {
			if (ans[i] != 0) {
				ans[k++] = ans[i];
			}
		}
		printf("%d\n", k);

		for (i = 0; i < k; i++) {
			printf("%d ", ans[i]);
		}
	}

	return 0;
}
