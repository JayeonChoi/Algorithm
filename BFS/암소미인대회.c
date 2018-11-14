/*
��ó : ����(codexpert.ort/willtek)
����:
�ֽ� �м� Ʈ���尡 ���׿� �� ���� ���� �ִ� �ϼҶ�� ���� ��� ���� �� ���� ���� �ִ� �ϼҸ� �뷮���� ���Ÿ� �ߴ�. �����ϰԵ�, �м� Ʈ���尡 ������ ���ؼ� ���� �α� �ִ� ���� �м��� ���� �ϳ� �ִ� �ϼ��̴�.

���� �ڽ��� �ϼҵ��� ���� �м� Ʈ���忡 �°� �ٲٰ� �ʹ�. �׷��� �� ���� ���� ���� ĥ�ؼ� �� ���� ������ ������� �Ѵ�.
���� ��� �ϼ��� ������ N(����) * M(����) ũ���� ���ڷ� �Ʒ��� ���� �־����� ��:

................
..XXXX....XXX...
...XXXX....XX...
.XXXX......XXX..
........XXXXX...
.........XXX....

���⼭ ������ ��X���� ���� �Ϻθ� ��Ÿ����. �� ��X���� ���� ������ ��޵Ǵ� ���� ���ϳ� �¿�� ����Ǿ� ���� �� �̴�. �밢������ ����� ���� ���� ������ ���� �ʴ´�. �׷��� �� �׸��� ��Ȯ�� �� ���̴�. ��� ���� ��� �ϼҴ� ��Ȯ�� �� ���� ������ �ִ�.

���� �� ���� �� ������ ���� �� �ִ��� ���� ��ĥ�ϰ� �ʹ�. ���� ������ �״� 3������ ���ο� ��X���� �߰��ϸ� �ȴ�. (���ο� ��X���� ��*���� ��ü�ؼ� ���� �� �� �ְ� �ߴ�. �Ʒ� �׸� ����)

................
..XXXX....XXX...
...XXXX*...XX...
.XXXX..**..XXX..
........XXXXX...
.........XXX....

����� �� ���� ��� ���� �� ���� ���� �����ؼ� �ϳ��� ū ���� ���� �� �ְ� ���ο� ��X���� �ּ� ���� ���� �� �ְ� �����ִ� ���̴�.
*/

#include <stdio.h>
#include <string.h>

int N, M;
char map[55][55];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int flag;
typedef struct st{
	int r, c;
} P;
P que[2500];
int wp, rp;
int visit[55][55];
int visit2[55][55];
int ans;

void input()
{
	int i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%s", map[i] + 1);
	}
	flag = 0;
	ans = 0x7fffffff;
}

void BFS(int sr, int sc)
{
	int i, nr, nc;
	P out;
	wp = rp = 0;
	que[wp++] = (P){ sr, sc };
	visit[sr][sc] = flag;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i]; nc = out.c + dc[i];
			if (nr<1 || nc < 1 || nr>N || nc>M) continue;
			if (visit[nr][nc]) continue;
			if (map[nr][nc] == 'X') {
				visit[nr][nc] = flag;
				que[wp++] = (P){ nr, nc };
			}
		}
	}
}

int get_ans(int sr, int sc)
{
	int i, nr, nc;
	P out;
	wp = rp = 0;
	memset(visit2, 0, sizeof(visit2));
	que[wp++] = (P){ sr, sc };
	visit2[sr][sc] = 1;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i]; nc = out.c + dc[i];
			if (nr<1 || nc < 1 || nr>N || nc>M) continue;
			if (visit2[nr][nc]) continue;
			visit2[nr][nc] = visit2[out.r][out.c] + 1;
			que[wp++] = (P){ nr, nc };
			if (visit[nr][nc] == 2) return visit2[out.r][out.c] - 1;
		}
	}
}

void FF()
{
	int i, j;
	int min;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (map[i][j] == 'X' && visit[i][j] == 0) {
				flag++;
				BFS(i, j);
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (visit[i][j] == 1) {
				min = get_ans(i, j);
				if (ans > min) ans = min;
			}
		}
	}
}


int main()
{
	input();
	FF();
	printf("%d", ans);
	return 0;
}
