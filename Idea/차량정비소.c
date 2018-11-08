/*
출처 : 삼성 SW Expert Academy 모의 SW 역량테스트#2477
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV6c6bgaIuoDFAXy&categoryId=AV6c6bgaIuoDFAXy&categoryType=CODE&solveclubId=&probBoxId=AV6c6bgaIuoDFAXy&problemBoxTitle=
*/

#include <stdio.h>
#include <string.h>

int N, M, K, A, B;
int a[25];
int b[25];
int tk[1000 + 10];
typedef struct customer {
	int rec_num;
	int rep_num;
	int arr_time;
	int num;
} S;
S info[1000 + 10];
int rec_stat[10];
int rep_stat[10];
int time;

void input()
{
	register int i;
	scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
	for (i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (i = 1; i <= M; i++) scanf("%d", &b[i]);
	for (i = 1; i <= K; i++) {
		scanf("%d", &tk[i]);
		info[i].num = i;
	}
}

void reception()
{
	register int j;
	register int fin = 1;

	for (time = tk[1]; info[K].rec_num == 0;)
	{
		if (tk[fin] > time) {
			time = tk[fin];
		}
		for (j = 1; j <= N; j++) {
			if (rec_stat[j] != 0 && time >= rec_stat[j]) rec_stat[j] = 0;

			if (rec_stat[j] == 0 && info[fin].rec_num == 0) {
				rec_stat[j] = time + a[j];
				info[fin].rec_num = j;
				info[fin].arr_time = a[j] + time;
				fin++;
				break;
			}
		}
		if (j == N + 1) time++;
	}
}

void repair()
{
	register int i, j;
	register int fin = 1;
	S tmp;

	//먼저 온 손님 순서로 정렬
	for (i = 1; i < K; i++) {
		for (j = i + 1; j <= K; j++) {
			if (info[i].arr_time > info[j].arr_time) {
				tmp = info[i];
				info[i] = info[j];
				info[j] = tmp;
			}
			else if (info[i].arr_time == info[j].arr_time && info[i].rec_num > info[j].rec_num) {
				tmp = info[i];
				info[i] = info[j];
				info[j] = tmp;
			}
		}
	}

	//정비 순서대로 받기
	for (time = info[1].arr_time; info[K].rep_num == 0;)
	{
		if (info[fin].arr_time > time) {
			time = info[fin].arr_time;
		}

		for (j = 1; j <= M; j++) {
			if (rep_stat[j] != 0 && time >= rep_stat[j]) rep_stat[j] = 0;

			if (rep_stat[j] == 0 && info[fin].rep_num == 0) {
				rep_stat[j] = time + b[j];
				info[fin].rep_num = j;
				fin++;
				break;
			}
		}
		if (j == M + 1) time++;
	}
}

int get_ans()
{
	int ans = 0;
	register int i;

	for (i = 1; i <= K; i++) {
		if (info[i].rec_num == A && info[i].rep_num == B) {
			ans += info[i].num;
		}
	}
	if (ans == 0) return -1;
	else return ans;
}

int main()
{
	int t, testcase;
	int sol;
	int i;
	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		input();
		reception();
		repair();
		sol = get_ans();
		printf("#%d %d\n", t, sol);
		memset(info, 0, sizeof(info));
		for (i = 1; i <= N; i++) rec_stat[i] = 0;
		for (i = 1; i <= M; i++) rep_stat[i] = 0;
	}
	return 0;
}