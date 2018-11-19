/*
<source>
USACO 2012 January Contest, Bronze
Problem 3. Grazing Patterns
http://www.usaco.org/index.php?page=viewproblem2&cpid=105
*/


#include <stdio.h>
int N;
int hr, hc;
int yr, yc;
int depth;
char map[6][6];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int sol;


void input()
{
	int tr, tc;
	int i;
	hr = 1; hc = 1;
	yr = 5; yc = 5;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &tr, &tc);
		map[tr][tc] = 'x';
	}
	map[1][1] = 'x';
}

void DFS(int L, int hr, int hc)
{
	int i;
	int nhr, nhc;

	if (L >= depth) {
		if (hr == yr && hc == yc) sol++;
		return;
	}
	//-------------------------------
	for (i = 0; i < 4; i++) {
		nhr = hr + dr[i];
		nhc = hc + dc[i];

		if (nhr < 1 || nhc < 1 || nhr > 5 || nhc > 5) continue;

		if (map[nhr][nhc] != 'x') {
			if (nhr == 5 && nhc == 5 && L< depth - 1) continue;
			map[nhr][nhc] = 'x';
			DFS(L + 1, nhr, nhc);
			map[nhr][nhc] = 0;
		}

	}

}

int main(void)
{
	input();
	sol = 0;
	depth = (25 - N);
	DFS(1, hr, hc);
	printf("%d\n", sol);
	return 0;

}
