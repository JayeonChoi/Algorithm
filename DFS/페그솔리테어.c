/*
��ó : ACM-ICPC > Regionals > Europe > Northwestern European Regional Contest > German Collegiate Programming Contest > GCPC 2013 F��
��� �ָ��׾�

<����>
��� �ָ��׾�� ������ �Է��ִ� ������ �����ǿ��� �ϴ� �����̴�. �� ���ۿ��� ���� �ϳ� ���� �� �ִ�.
���� ����, ���� �������� ������ ���� �پ�Ѿ �� ���� ���� ĭ���� �̵��ϴ� �͸� ���ȴ�.
������ ���� ���� ĭ�� ����־�� �ϰ� �� ������ ���� ���ŵȴ�.
���� �����ǿ� �����ִ� ���� ���°� �־�����. �̶�, ���� ������ �������� �����ǿ� �����ִ� ���� ������ �ּҷ� 
�Ϸ��� �Ѵ�. ��, �׷��� ����� ���� �ʿ��� �ּ� �̵�Ƚ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

<�Է�>
ù° �ٿ� �׽�Ʈ ���̽��� ���� 1 �� N �� 100�� �־�����. �� �׽�Ʈ ���̽��� �������� �ʱ� �����̴�.
�������� ��� ���� ����� ������. (���� ����) '.'�� �� ĭ, 'o'�� ���� �����ִ� ĭ, '#'�� ������ ���� ĭ�̴�. 
���� ������ �ִ� 8�̸�, �� �׽�Ʈ ���̽��� �� �ٷ� ���еǾ��� �ִ�.

<���>
�� �׽�Ʈ ���̽��� ���ؼ�, ���� �������� ���� �� �ִ� ���� �ּ� ������ �� ������ ����� ���� �ʿ��� �ּ� �̵� Ƚ����
����Ѵ�.
*/

#include <stdio.h>
char map[6][10];
int pin;
int min;
int minmove;
int or, oc;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void input()
{
	int i, j;
	for (i = 1; i <= 5; i++) {
		scanf("%s", map[i] + 1);
		for (j = 1; j <= 9; j++) {
			if (map[i][j] == 'o') {
				pin++;
			}
		}
	}
}

int check(int r, int c)
{
	int i, nr, nc;
	for (i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if (nr + dr[i] < 1 || nc + dc[i] < 1 || nr + dr[i]>5 || nc + dc[i]>9) continue;
		if (map[nr][nc] == 'o' && map[nr + dr[i]][nc + dc[i]] == '.') {
			return 1;
		}
	}
	return 0;
}
void DFS(int pin, int move)
{
	int i, j, k;
	int tr, tc;

	if (min > pin) {
		min = pin;
		minmove = move;
	}

	if (min == pin) {
		if (minmove > move) minmove = move;
	}

	//---------------------------------------
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 9; j++) {
			if (map[i][j] == 'o') {
				if (check(i, j)) {
					int nr, nc;
					for (k = 0; k < 4; k++) {
						nr = i + dr[k];
						nc = j + dc[k];
						if (nr + dr[k] < 1 || nc + dc[k] < 1 || nr + dr[k]>5 || nc + dc[k]>9) continue;
						if (map[nr][nc] == 'o' && map[nr + dr[k]][nc + dc[k]] == '.') {
							tr = dr[k]; tc = dc[k];
							map[i][j] = map[i + tr][j + tc] = '.';
							map[i + 2 * tr][j + 2 * tc] = 'o';
							DFS(pin - 1, move + 1);
							map[i][j] = map[i + tr][j + tc] = 'o';
							map[i + 2 * tr][j + 2 * tc] = '.';
						}
					}

				}
			}
		}
	}

}

int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--) {
		pin = 0;
		min = minmove = 0x7fffffff;
		input();
		DFS(pin, 0);
		printf("%d %d\n", min, minmove);
	}

	return 0;
}

