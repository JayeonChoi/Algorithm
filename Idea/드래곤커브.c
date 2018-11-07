/*
출처: 백준 알고리즘(삼성 알고리즘 테스트 기출)
https://www.acmicpc.net/problem/15685
*/

#include <stdio.h>
int map[110][110];
int N;
int x, y, d, g;
typedef struct st {
	int r, c;
	int dir;
} I;
I curve[1050];
int dr[] = { 0, -1, 0, 1 };
int dc[] = { 1, 0, -1, 0 };
int cdir[] = { 1, 2, 3, 0 };
void draw_curve(int, int, int, int);

void input()
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);
		draw_curve(x, y, d, g);
	}
}

void draw_curve(int x, int y, int d, int g)
{
	int wp, rp;
	int gr, gc;
	int i, dir;

	wp = 0;
	//0세대
	curve[wp++] = (I){ y + dr[d], x + dc[d], d };
	map[y][x] = map[y + dr[d]][x + dc[d]] = 1;

	//1세대부터
	for (i = 1; i <= g; i++) {
		gr = curve[wp - 1].r; gc = curve[wp - 1].c;
		for (rp = wp - 1; rp >= 0; rp--) {
			dir = cdir[curve[rp].dir];
			gr = gr + dr[dir]; gc = gc + dc[dir];
			curve[wp++] = (I){ gr, gc, dir };
			map[gr][gc] = 1;
		}
	}
}

int get_ans()
{
	int i, j;
	int ans = 0;

	for (i = 0; i <= 99; i++) {
		for (j = 0; j <= 99; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
				ans++;
			}
		}
	}

	return ans;
}

int main()
{
	int sol;
	input();
	sol = get_ans();
	printf("%d", sol);
	return 0;
}