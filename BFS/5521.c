//상원이의 생일 파티가 곧 열린다!
//그렇기에 상원이는 반 친구들에게 생일 파티 초대장을 주려고 한다.
//그러나 파티가 어색하게 되는 것을 원치 않는 상원이는 모든 친구들에게 초대장을 줄 생각이 없다.
//같은 반에 있지만, 서로 친한 친구가 아닐 수도 있기 때문이다.
//상원이는 우선 자신과 친한 친구들에게는 모두 초대장을 주기로 했다.
//여기에 더해서 친한 친구의 친한 친구인 경우에도 초대장을 주기로 했다.
//총 몇 명의 친구들에게 초대장을 주어야 하는지 구하는 프로그램을 작성하라.
//상원이의 반에는 N명이 있으며, 각 학생들은 1번에서 N번까지의 번호가 붙어 있다.
//여기서 1번 학생이 상원이다.
//
//[입력]
//첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
//각 테스트 케이스의 첫 번째 줄에 두 정수 N, M(2 ≤ N ≤ 500, 1 ≤ M ≤ 104) 이 공백으로 구분되어 주어진다.
//M은 친한 친구 관계의 수 이다.
//다음 M개의 줄의 각 줄에는 두 정수 a, b(1 ≤ a ＜ b ≤ N) 이 주어진다.
//이는 a번 학생과 b번 학생이 서로 친한 친구 관계에 있다는 의미이다.

//[출력]
//각 테스트 케이스마다 #T를 출력하고 한 칸을 띄운 후, 각 테스트 케이스마다 상원이의 생일 파티 초대장을 받는 친구의 수를 출력한다.
//*상원이의 친구가 없을 수도 있다는 점에 유의해야 한다.그리고 상원이는 초대장을 받는 사람에 속하지 않는다.


#include <stdio.h>
#include <string.h>
#define MAX (500+10)
int relation[MAX][MAX];
int visit[MAX];
typedef struct st {
	int num;
	int jump;
} P;
P que[MAX*MAX];
int wp, rp;
int ans;
int N, M;

void input()
{
	int i;
	int tmpa, tmpb;
	memset(relation, 0, sizeof(relation));
	memset(visit, 0, sizeof(visit));

	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &tmpa, &tmpb);
		relation[tmpa][tmpb] = relation[tmpb][tmpa] = 1;
	}
}

int BFS(int start)
{
	P out;
	int i;
	int chodae = 0;
	wp = rp = 0;
	que[wp++] = (P) { start, 0 };
	visit[start] = 1;

	while (wp > rp) {
		out = que[rp++];
		if (out.jump >= 2) continue;
		for (i = 1; i <= N; i++) {
			if (visit[i]) continue;
			if (!relation[out.num][i]) continue;
			visit[i] = 1;
			chodae++;
			que[wp++] = (P){ i, out.jump + 1 };
		}
	}
	return chodae;
}

int main()
{
	int t, testcase;
	int sol;

	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		sol = BFS(1);
		printf("#%d %d\n", t, sol);
	}
	return 0;
}