/*
USACO 2013 December Contest, Bronze
Problem 2. Cow Baseball
http://www.usaco.org/index.php?page=viewproblem2&cpid=359
*/

#include <stdio.h>
#define MAX 110
int N;
int field[MAX][MAX];
int visit[MAX][MAX];

typedef struct xy {
	int r, c;
} P;
P que[MAX*MAX];
P hque[MAX*MAX*MAX];
int wp, rp;
int hwp, hrp;
int minr = 101, maxr = 0;
int minc = 101, maxc = 0;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int sr, sc;

void init_visit()
{
	int i, j;
	for (i = minr; i <= maxr; i++) {
		for (j = minc; j <= maxc; j++) {
			visit[i][j] = 0;
		}
	}
}

int find_hole(int r, int c)
{
	int i;
	int nr, nc;
	P out;
	init_visit();
	hwp = hrp = 0;
	hque[hwp++] = (P){ r, c };
	visit[r][c] = 1;

	while (hwp > hrp) {
		out = hque[hrp++];

		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i];
			nc = out.c + dc[i];
			if (nr <minr || nr > maxr || nc <minc || nc >maxc) return 0;
			if (field[nr][nc] == 0 && visit[nr][nc] == 0) {
				visit[nr][nc] = 1;
				hque[hwp++] = (P) { nr, nc };

			}
		}
	}
	return 1;
}

void input()
{
	int i, j;
	int r, c;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d %d", &c, &r);
		field[r][c] = 1;
		que[wp++] = (P) { r, c };
		if (r > maxr) maxr = r;
		if (r < minr) minr = r;
		if (c > maxc) maxc = c;
		if (c < minc) minc = c;
	}

	for (i = minr; i <= maxr; i++) {
		for (j = minc; j <= maxc; j++) {
			if (field[i][j]) continue;
			if (find_hole(i, j)) {
				field[i][j] = 1;
			}
		}
	}
}


int get_len()
{
	int nr, nc, i;
	int len = 0;
	P out;

	while (wp > rp) {
		out = que[rp++];
		for (i = 0; i < 4; i++) {
			nr = out.r + dr[i];
			nc = out.c + dc[i];
			if (nr < 0 || nc < 0 || nr>101 || nc>101) continue;
			if (!field[nr][nc]) {
				len++;
			}
		}
	}
	return len;
}

int main(void)
{
	int len;

	input();
	len = get_len();

	printf("%d", len);
	return 0;
}