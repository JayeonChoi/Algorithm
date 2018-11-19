/*
출처 : ACM-ICPC > Regionals > Europe > Northwestern European Regional Contest > German Collegiate Programming Contest > GCPC 2013 F번
페그 솔리테어

<문제>
페그 솔리테어는 구멍이 뚤려있는 이차원 게임판에서 하는 게임이다. 각 구멍에는 핀을 하나 꽂을 수 있다.
핀은 수평, 수직 방향으로 인접한 핀을 뛰어넘어서 그 핀의 다음 칸으로 이동하는 것만 허용된다.
인접한 핀의 다음 칸은 비어있어야 하고 그 인접한 핀은 제거된다.
현재 게임판에 꽂혀있는 핀의 상태가 주어진다. 이때, 핀을 적절히 움직여서 게임판에 남아있는 핀의 개수를 최소로 
하려고 한다. 또, 그렇게 남기기 위해 필요한 최소 이동횟수를 구하는 프로그램을 작성하시오.

<입력>
첫째 줄에 테스트 케이스의 개수 1 ≤ N ≤ 100이 주어진다. 각 테스트 케이스는 게임판의 초기 상태이다.
게임판은 모두 같은 모양을 가진다. (예제 참고) '.'는 빈 칸, 'o'는 핀이 꽂혀있는 칸, '#'는 구멍이 없는 칸이다. 
핀의 개수는 최대 8이며, 각 테스트 케이스는 빈 줄로 구분되어져 있다.

<출력>
각 테스트 케이스에 대해서, 핀을 움직여서 남길 수 있는 핀의 최소 개수와 그 개수를 만들기 위해 필요한 최소 이동 횟수를
출력한다.
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

