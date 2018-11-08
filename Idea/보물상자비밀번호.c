/*
출처 : 삼성 SW Expert Academy 모의 SW 역량테스트#5658
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
*/

#include <stdio.h>

int N, K;
int arr[30][10];
int indata[30];
int h;

void input()
{
	int i;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%1x", &indata[i]);
}

void get_arr()
{
	int a;
	int i, j;

	h = N / 4;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= h; j++) {
			if (i + j - 1 > N) a = i + j - 1 - N;
			else a = i + j - 1;
			arr[i][j] = indata[a];
		}
	}
}

int compare(int *char1, int *char2, int n)
{
	if (n > h) return 0;

	if (char1[n] < char2[n]) return 1;
	else if (char1[n] > char2[n]) return 0;
	else compare(char1, char2, n + 1);
}

unsigned int i16to10(int K)
{
	unsigned int ans = 0;
	int i;

	for (i = 1; i <= h; i++) {
		ans *= 16;
		ans += arr[K][i];
	}
	return ans;
}

void copy(int *arr1, int *arr2)
{
	int i;
	for (i = 1; i <= h; i++) arr1[i] = arr2[i];
}

int cmp(int *arr1, int *arr2)
{
	int i;
	for (i = 1; i <= h; i++) {
		if (arr1[i] != arr2[i]) return 0;
	}
	return 1;
}

unsigned int get_ans()
{
	int i, j;
	int cnt = 0;
	int tmp[10];
	unsigned int sol;

	//정렬
	for (i = 1; i < N; i++) {
		for (j = i + 1; j <= N; j++) {
			if (compare(arr[i], arr[j], 1)) {
				copy(tmp, arr[i]);
				copy(arr[i], arr[j]);
				copy(arr[j], tmp);
			}
		}
	}

	//중복 제거
	for (i = 2; i <= K; i++) {
		if (cmp(arr[i - 1], arr[i])) {
			cnt++;
		}
	}

	//K번째 값 진수 변환
	sol = i16to10(K + cnt);
	return sol;
}


int main()
{
	int t, testcase;
	unsigned int sol;

	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		input();
		get_arr();
		sol = get_ans();
		printf("#%d %u\n", t, sol);
	}
	return 0;
}