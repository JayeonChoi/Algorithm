//������� ���� ��Ƽ�� �� ������!
//�׷��⿡ ����̴� �� ģ���鿡�� ���� ��Ƽ �ʴ����� �ַ��� �Ѵ�.
//�׷��� ��Ƽ�� ����ϰ� �Ǵ� ���� ��ġ �ʴ� ����̴� ��� ģ���鿡�� �ʴ����� �� ������ ����.
//���� �ݿ� ������, ���� ģ�� ģ���� �ƴ� ���� �ֱ� �����̴�.
//����̴� �켱 �ڽŰ� ģ�� ģ���鿡�Դ� ��� �ʴ����� �ֱ�� �ߴ�.
//���⿡ ���ؼ� ģ�� ģ���� ģ�� ģ���� ��쿡�� �ʴ����� �ֱ�� �ߴ�.
//�� �� ���� ģ���鿡�� �ʴ����� �־�� �ϴ��� ���ϴ� ���α׷��� �ۼ��϶�.
//������� �ݿ��� N���� ������, �� �л����� 1������ N�������� ��ȣ�� �پ� �ִ�.
//���⼭ 1�� �л��� ����̴�.
//
//[�Է�]
//ù ��° �ٿ� �׽�Ʈ ���̽��� �� T�� �־�����.
//�� �׽�Ʈ ���̽��� ù ��° �ٿ� �� ���� N, M(2 �� N �� 500, 1 �� M �� 104) �� �������� ���еǾ� �־�����.
//M�� ģ�� ģ�� ������ �� �̴�.
//���� M���� ���� �� �ٿ��� �� ���� a, b(1 �� a �� b �� N) �� �־�����.
//�̴� a�� �л��� b�� �л��� ���� ģ�� ģ�� ���迡 �ִٴ� �ǹ��̴�.

//[���]
//�� �׽�Ʈ ���̽����� #T�� ����ϰ� �� ĭ�� ��� ��, �� �׽�Ʈ ���̽����� ������� ���� ��Ƽ �ʴ����� �޴� ģ���� ���� ����Ѵ�.
//*������� ģ���� ���� ���� �ִٴ� ���� �����ؾ� �Ѵ�.�׸��� ����̴� �ʴ����� �޴� ����� ������ �ʴ´�.


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