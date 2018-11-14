/*
��ó : ����(codexpert.ort/willtek)
����:
������ ������ �߰��� ��ũ ������ ������ ã�� ������. ������ ������ �Ʒ� �׸��� ���� ���簢�� ����̸� ���� ĭ���� �������� �ִ�. �� ĭ�� ����(L)�� �ٴ�(W)�� ǥ�õǾ� �ִ�. �� �������� �̵��� �����¿�� �̿��� �����θ� �����ϸ�, �� ĭ �̵��ϴµ� �� �ð��� �ɸ���.
������ ���� ���� �ִ� �Ÿ��� �̵��ϴµ� �־� ���� �� �ð��� �ɸ��� ���� �� ���� ������ �����ִ�. ������ ��Ÿ���� �� �� ���̸� �ִ� �Ÿ��� �̵��Ϸ��� ���� ���� �� �� �̻� �������ų�, �ָ� ���ư����� �ȵȴ�.
���� ������ �־��� ��, ������ ���� �ִ� �� �� ���� �ִ� �Ÿ��� �̵��ϴ� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�:
ù° �ٿ��� ���� ������ ������ ũ��� ������ ũ�Ⱑ ��ĭ�� ���̿� �ΰ� �־�����.
�̾� L�� W�� ǥ�õ� ���� ������ �Ʒ��� ���� ���� �־�����, �� ���� ���̿��� �� ĭ�� ����. ���� ������ ����, ������ ũ��� ���� 50�����̴�.
���:
ù° �ٿ� ������ ���� �ִ� �� �� ���̸� �ִ� �Ÿ��� �̵��ϴ� �ð��� ����Ѵ�.
*/

#include <stdio.h>
#include <string.h>

#define MAX 55
int R, C;
char map[MAX][MAX];
int visit[MAX][MAX];

typedef struct xy{
	int r, c;
}POS;
POS que[MAX*MAX];
POS land[MAX*MAX];

int wp, rp;
int lwp, lrp;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
void inque(int i, int j)
{
	que[wp].r = i;
	que[wp].c = j;
	wp++;
}

void input(void)
{
	int i, j;
	scanf("%d %d", &R, &C);

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'L') {
				land[lwp].r = i;
				land[lwp].c = j;
				lwp++;
			}
		}
	}
}

int BFS(void)
{
	POS lout;
	POS out;
	int nr, nc, i;
	int max = 0;

	while (lwp > lrp)
	{
		lout = land[lrp++];
		wp = rp = 0;
		inque(lout.r, lout.c);
		visit[lout.r][lout.c] = 1;
		while (wp > rp) {
			out = que[rp++];
			for (i = 0; i < 4; i++) {
				nr = out.r + dr[i];
				nc = out.c + dc[i];

				if (map[nr][nc] == 'L' && visit[nr][nc] == 0) {
					inque(nr, nc);
					visit[nr][nc] = visit[out.r][out.c] + 1;

				}
			}
			if (max < visit[out.r][out.c]) max = visit[out.r][out.c];

		}
		memset(visit, 0, sizeof(visit));
	}
	return max - 1;
}

int main(void)
{
	int sol;
	input();
	sol = BFS();
	printf("%d", sol);

	return 0;
}