//����
//�� ���ӿ��� �� ���� �̵��� ���� ���� �ִ� ��ü ����� �����¿� �� ���� �� �ϳ��� �̵���Ű�� ���̴�.�̶�, ���� ���� ���� �� ����� �浹�ϸ� �� ����� �ϳ��� �������� �ȴ�.�� ���� �̵����� �̹� ������ ����� �� �ٸ� ��ϰ� �ٽ� ������ �� ����. (���� ���ӿ����� �̵��� �� �� �� ������ ����� �߰�������, �� �������� ����� �߰��Ǵ� ���� ����)
//����������, �Ȱ��� ���� �� ���� �ִ� ��쿡�� �̵��Ϸ��� �ϴ� ���� ĭ�� ���� ��������.���� ���, ���� �̵���Ű�� ��쿡�� ���ʿ� �ִ� ����� ���� �������� �ȴ�. <�׸� 14>�� ��쿡 ���� �̵��ϸ� <�׸� 15>�� �����.
//
//�� �������� �ٷ�� 2048 ������ ������ ũ�Ⱑ N��N �̴�.������ ũ��� �������� ��� ���°� �־����� ��, �ִ� 5�� �̵��ؼ� ���� �� �ִ� ���� ū ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� ������ ũ�� N(1 �� N �� 20)�� �־�����.��° �ٺ��� N���� �ٿ��� �������� �ʱ� ���°� �־�����. 0�� �� ĭ�� ��Ÿ����, �̿��� ���� ��� ����� ��Ÿ����.��Ͽ� ���� �ִ� ���� 2���� ũ�ų� ����, 1024���� �۰ų� ���� 2�� �������̴�.����� ��� �ϳ� �־�����.
//
//���
//�ִ� 5�� �̵����Ѽ� ���� �� �ִ� ���� ū ����� ����Ѵ�.

#include <stdio.h>
#include <string.h>

int N;
int map[25][25];
int ans;
int list[5];

void input()
{
	int i, j;
	scanf("%d", &N);
	ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void move(i)
{
	int max = 0;
	int r, c;
	int tmpr, tmpc;
	int visit[25][25] = { 0 };

	if (i == 0) {
		for (c = 1; c <= N; c++) {
			for (r = 2; r <= N; r++) {
				if (map[r][c] == 0) continue;
				tmpr = r - 1;
				while (tmpr != 1 && map[tmpr][c] == 0) {
					tmpr--;
				}
				if (map[r][c] == map[tmpr][c] && visit[tmpr][c] == 0) {
					map[tmpr][c] *= 2;
					map[r][c] = 0;
					visit[tmpr][c] = 1;
				}
				else {
					if (map[tmpr][c] == 0) {
						map[tmpr][c] = map[r][c]; map[r][c] = 0;
					}
					else if (tmpr + 1 != r) {
						map[tmpr + 1][c] = map[r][c]; map[r][c] = 0;
					}
				}
			}
		}
	}

	else if (i == 1) {
		for (c = 1; c <= N; c++) {
			for (r = N - 1; r >= 1; r--) {
				if (map[r][c] == 0) continue;
				tmpr = r + 1;
				while (tmpr != N && map[tmpr][c] == 0) {
					tmpr++;
				}
				if (map[r][c] == map[tmpr][c] && visit[tmpr][c] == 0) {
					map[tmpr][c] *= 2;
					map[r][c] = 0;
					visit[tmpr][c] = 1;
				}
				else {
					if (map[tmpr][c] == 0) {
						map[tmpr][c] = map[r][c]; map[r][c] = 0;
					}
					else if (tmpr - 1 != r) {
						map[tmpr - 1][c] = map[r][c]; map[r][c] = 0;
					}
				}
			}
		}
	}

	else if (i == 2) {
		for (r = 1; r <= N; r++) {
			for (c = 2; c <= N; c++) {
				if (map[r][c] == 0) continue;
				tmpc = c - 1;
				while (tmpc != 1 && map[r][tmpc] == 0) {
					tmpc--;
				}
				if (map[r][c] == map[r][tmpc] && visit[r][tmpc] == 0) {
					map[r][tmpc] *= 2;
					map[r][c] = 0;
					visit[r][tmpc] = 1;
				}
				else {
					if (map[r][tmpc] == 0) {
						map[r][tmpc] = map[r][c]; map[r][c] = 0;
					}
					else if (tmpc + 1 != c) {
						map[r][tmpc + 1] = map[r][c]; map[r][c] = 0;
					}
				}
			}
		}
	}

	else {
		for (r = 1; r <= N; r++) {
			for (c = N - 1; c >= 1; c--) {
				if (map[r][c] == 0) continue;
				tmpc = c + 1;
				while (tmpc != N && map[r][tmpc] == 0) {
					tmpc++;
				}
				if (map[r][c] == map[r][tmpc] && visit[r][tmpc] == 0) {
					map[r][tmpc] *= 2;
					map[r][c] = 0;
					visit[r][tmpc] = 1;
				}
				else {
					if (map[r][tmpc] == 0) {
						map[r][tmpc] = map[r][c];
						map[r][c] = 0;
					}
					else if (tmpc - 1 != c) {
						map[r][tmpc - 1] = map[r][c];
						map[r][c] = 0;
					}
				}
			}
		}
	}
}

int get_max()
{
	int max = 0;
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (map[i][j] > max) max = map[i][j];
		}
	}

	return max;
}

void printmap()
{
	int j, k;
	for (j = 1; j <= N; j++) {
		for (k = 1; k <= N; k++) {
			printf("%d ", map[j][k]);
		}
		printf("\n");
	}
}

void DFS(int L)
{
	int i;
	int tmpmap[25][25];
	int max;

	if (L >= 5) {
		max = get_max();
		if (max > ans) {
			ans = max;
		}
		return;
	}
	//----------------------------------------------

	for (i = 0; i < 4; i++) {
		memcpy(tmpmap, map, sizeof(map));
		list[L] = i;
		move(i);
		DFS(L + 1);
		list[L] = 0;
		memcpy(map, tmpmap, sizeof(map));
	}
}

int main()
{
	input();
	DFS(0);
	printf("%d", ans);
	return 0;
}