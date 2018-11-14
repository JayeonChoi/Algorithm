/*
��ó : ����(codexpert.ort/willtek)

<����>
N���� ���� ������ �׷����� ������ �־�����, ���� M�� �־�����. �� ��, ���� ������ ���� ������ ���� ���� ĥ���� �����鼭 M���� ������ N���� ��带 ���� ĥ�� �� �ִ��� �Ǵ��϶�. ������ ��쿡�� ù ��° ������ ���� ��ȣ(1 ~ M���� ����)�� ����ϰ�, �Ұ����� ��� -1�� ����Ѵ�.

���1���� ������� ���� ĥ�ؾ� �ϸ� ���� ��ȣ�� ���� ��ȣ���� �ٿ� ������ �Ѵ�.  �־��� ������ ��� ����� �ʿ�� ������ �����ϸ� ���� ���� ��ȣ�� ����Ͽ� �ϼ��϶�. ��, 6���� ���� �־���� 5���� ������ ��� ĥ�� �� ������ 5������ ����Ͽ��� �Ѵ�.

�׷��� ������ triangular matrix�� �־�����, ����Ǿ� �ִ� ��� 1, ����Ǿ� ���� ���� ��� 0���� �־�����.

<�Է�>
ù �ٿ� ��� �� N(1��N��12)�� ���� ��ȣ M(1��M��12)�� �־�����.
<���>
���1������ ĥ���� ���� ��ȣ ����Ʈ�� ����Ѵ�.
�Ұ����� ��� -1�� ����Ѵ�.
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