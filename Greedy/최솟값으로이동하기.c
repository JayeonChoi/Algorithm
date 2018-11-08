/*
출처 : 삼성 SW Expert Academy 난이도 D4 #3349
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWDTN0cKr1oDFAWD
*/

#include <stdio.h>
int W, H, N;
int cost;
int tr[1010];
int tc[1010];

void input()
{
	int i;

	scanf("%d %d %d", &W, &H, &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &tr[i], &tc[i]);
	}
}

int abs(int a) {
	return a >= 0 ? a : -a;
}
int get_cost(int n)
{
	int sr, sc;
	int er, ec;
	int dr, dc;
	int cost = 0;

	sr = tr[n];
	sc = tc[n];
	er = tr[n + 1];
	ec = tc[n + 1];
	dr = er - sr;
	dc = ec - sc;

	while (dr != 0 || dc != 0) {
		if (dr >= 1 && dc >= 1) {
			dr--;
			dc--;
		}
		else if (dr <= -1 && dc <= -1) {
			dr++;
			dc++;
		}
		else if (dr >= 1) {
			dr--;
		}
		else if (dr <= -1) {
			dr++;
		}
		else if (dc >= 1) {
			dc--;
		}
		else if (dc <= -1) {
			dc++;
		}
		cost++;
	}
	return cost;
}

int main()
{
	int i;
	int t, testcase;

	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		cost = 0;
		for (i = 0; i < N - 1; i++) {
			cost += get_cost(i);
		}
		printf("#%d %d\n", t, cost);
	}

	return 0;
}