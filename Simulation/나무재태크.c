/*
출처 : 백준-삼성 SW 역량 테스트 기출 문제:나무재태크
https://www.acmicpc.net/problem/16235
*/

#include <stdio.h>
int N, M, K;
int map[15][15];
int nutri[15][15];
typedef struct _tree
{
	int r, c;
	int age;
	int death;
} T;
T tree[100000];
int alivetree;
int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int death[50000], alive[100000];

void input()
{
	int i, j;

	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &nutri[i][j]);
		}
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &tree[i].r, &tree[i].c, &tree[i].age);
		tree[i].death = 0;
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			map[i][j] = 5;
		}
	}

	for (i = 0; i <= N + 1; i++) {
		map[i][0] = -1; map[i][N + 1] = -1;
		map[0][i] = -1; map[N + 1][i] = -1;
	}
	alivetree = M;
}

void one_year_after()
{
	register int i, j;
	int nr, nc;
	int l = 0;
	int d = 0;
	int tmp;
	int uppera = 50000, lowera = 50000;

	//봄
	for (i = alivetree - 1; i >= 0; i--) {
		if (map[tree[i].r][tree[i].c] >= tree[i].age) {
			map[tree[i].r][tree[i].c] -= tree[i].age;
			tree[i].age++;
			alive[uppera++] = i;
			//가을
			if (tree[i].age % 5 == 0) {
				for (j = 0; j < 8; j++) {
					nr = tree[i].r + dr[j]; nc = tree[i].c + dc[j];
					if (map[nr][nc] == -1) continue;
					tree[alivetree + l] = (T){ nr, nc, 1, 0 };
					alive[--lowera] = alivetree + l;
					l++;
				}
			}
		}
		else {
			tree[i].death = 1;
			death[d++] = i;
		}
	}

	//여름
	for (i = 0; i <d; i++) {
		int ind = death[i];
		map[tree[ind].r][tree[ind].c] += tree[ind].age / 2;
	}


	//겨울
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			map[i][j] += nutri[i][j];
		}
	}

	//정리
	tmp = 0;
	if (d > 0) {
		for (i = uppera - 1; i >= lowera; i--) {
			tree[tmp++] = tree[alive[i]];
		}
	}

	alivetree = uppera - lowera;
}

int main()
{
	int i;
	input();
	for (i = 0; i < K; i++) {
		one_year_after();
	}
	printf("%d", alivetree);
	return 0;
}