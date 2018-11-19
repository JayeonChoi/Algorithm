/*
USACO 2013 December Contest, Bronze
Problem 2. Cow Baseball
http://www.usaco.org/index.php?page=viewproblem2&cpid=359
*/

#include <stdio.h>
#define MAX 1010

int N;
int leaf[MAX];
int sol;
int tmp[MAX];

void merge_sort(int s, int e)
{
	int i, j, k, m;
	if (s >= e) return;
	m = (s + e) / 2; i = k = s; j = m + 1;
	merge_sort(s, m);
	merge_sort(j, e);

	while ((i <= m) || (j <= e))
	{
		if ((i > m) || ((j <= e) && (leaf[i] > leaf[j]))) tmp[k++] = leaf[j++]; //오름차순 정렬
		else tmp[k++] = leaf[i++];
	}
	for (i = s; i <= e; i++) leaf[i] = tmp[i];
}

void input()
{
	register int i, j;
	int tmp;

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &leaf[i]);
	merge_sort(0, N - 1);
	//for (i = 0; i < N; i++) printf("%d ", leaf[i]);
}

int binary_right(int s, int e, int d) //작은 수 중에 큰수
{
	int sol = -1;

	while (s <= e) {
		int m = (s + e) / 2;
		if (leaf[m] == d) return m;
		else if (leaf[m] < d) {
			s = m + 1;
			sol = m;
		}
		else e = m - 1;
	}
	return sol;
}

int binary_left(int s, int e, int d) //큰 수 중에 작은수
{
	int sol = -1;

	while (s <= e) {
		int m = (s + e) / 2;
		if (leaf[m] == d) return m;
		else if (leaf[m] > d) {
			e = m - 1;
			sol = m;
		}
		else s = m + 1;
	}
	return sol;
}

int main()
{
	int i, j, k;
	int d;
	int m1, m2;

	sol = 0;
	input();
	for (i = 0; i < N - 2; i++) {
		for (j = i + 1; j < N - 1; j++) {
			d = leaf[j] - leaf[i];

			m1 = binary_left(j, N - 1, leaf[j] + d);
			m2 = binary_right(j, N - 1, leaf[j] + 2 * d);

			if (m1 != -1 && m2 != -1 && m2 >= m1) {
				sol += (m2 - m1 + 1);
			}
		}
	}
	printf("%d", sol);
	return 0;
}