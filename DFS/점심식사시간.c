/*
출처 : 삼성 SW Expert Academy 모의 SW 역량테스트#2383
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5-BEE6AK0DFAVl
*/

int N;
int map[15][15];
typedef struct info {
	int r, c;
	int time;
	int d[3];
	int snum;
} P;
typedef struct info2{
	int r, c;
	int K;
	int wait[5];
} S;

int p;
P people[15];
S stair[3];
int min;
int list1[15], list2[15];
int tmparr[15];

void input()
{
	int i, j;
	scanf("%d", &N);
	p = 1;
	stair[1] = stair[2] = (S){ 0 };

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) people[p++] = (P) { i, j };
			if (map[i][j] >= 2) {
				if (stair[1].K == 0) stair[1] = (S) { i, j, map[i][j], { 0 } };
				else stair[2] = (S) { i, j, map[i][j], { 0 } };
			}
		}
	}

}

int abs(int a)
{
	return a >= 0 ? a : -a;
}

void get_dis(void)
{
	int i, j;
	P tmp;

	//사람마다 1번 계단, 2번 계단과의 거리 구하기
	for (i = 1; i < p; i++) {
		people[i].d[1] = abs(stair[1].r - people[i].r) + abs(stair[1].c - people[i].c);
		people[i].d[2] = abs(stair[2].r - people[i].r) + abs(stair[2].c - people[i].c);
	}

	//1번 계단 기준 정렬
	for (i = 1; i < p - 1; i++) {
		for (j = i + 1; j < p; j++) {
			if (people[i].d[1] > people[j].d[1]) {
				tmp = people[i];
				people[i] = people[j];
				people[j] = tmp;
			}
		}
	}
}

int get_max()
{
	int i;
	int max = 0;

	for (i = 1; i < p; i++) {
		if (people[i].time > max) max = people[i].time;
	}
	return max;
}

int get_time(int ingan, int num)
{
	int time, mintmp, mini;
	int i;

	mintmp = 0x7fffffff;
	time = people[ingan].d[num] + stair[num].K + 1;

	for (i = 1; i <= 3; i++) {
		if (stair[num].wait[i] == 0) {
			stair[num].wait[i] = time;
			people[ingan].time = time;
			people[ingan].snum = i;
			break;
		}
		if (mintmp > stair[num].wait[i]) {
			mintmp = stair[num].wait[i];
			mini = i;
		}
	}
	if (i == 4) {
		int val;
		val = mintmp > people[ingan].d[num] ? mintmp + stair[num].K : people[ingan].d[num] + stair[num].K + 1;
		people[ingan].time = val;
		stair[num].wait[mini] = val;
		people[ingan].snum = mini;
	}

	if (i == 4) return mintmp;
	else return 0;
}

void DFS(int L)
{
	int past;
	if (L >= p) {
		int max;
		int j, k, tmp;
		int t1, t2;

		//list 2 sorting
		for (j = 1; j < p; j++) tmparr[j] = list2[j];
		for (k = 1; k < p - 1; k++) {
			if (!tmparr[k]) continue;
			for (j = k + 1; j < p; j++) {
				if (!tmparr[j]) continue;
				t1 = tmparr[k]; t2 = tmparr[j];
				if (people[t1].d[2] > people[t2].d[2]) {
					tmp = tmparr[k]; tmparr[k] = tmparr[j]; tmparr[j] = tmp;
				}
			}
		}
		//0이 아닌것들만 time 넣어주기
		for (j = 1; j < p; j++) {
			int n;
			if (tmparr[j]) {
				n = get_time(tmparr[j], 2);
			}
		}
		stair[2].wait[1] = stair[2].wait[2] = stair[2].wait[3] = 0;
		//max비교
		max = get_max();
		if (min > max) min = max;
		return;
	}
	//-------------------------------------------
	//1번 계단 이용하는 경우
	list1[L] = L;
	past = get_time(L, 1);
	DFS(L + 1);
	list1[L] = 0;
	stair[1].wait[people[L].snum] = past;
	people[L].time = 0;

	//2번 계단 이용하는 경우
	list2[L] = L;
	DFS(L + 1);
	list2[L] = 0;
	people[L].time = 0;
}

int main()
{
	int t, testcase;
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		min = 0x7fffffff;
		get_dis();
		DFS(1);
		printf("#%d %d\n", t, min);
	}
	return 0;
}