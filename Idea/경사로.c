﻿
/*
출처: 백준 알고리즘(삼성 알고리즘 테스트 기출-경사로) 

https ://www.acmicpc.net/problem/14890 
	
문제


크기가 N×N인 지도가 있다.지도의 각 칸에는 그 곳의 높이가 적혀져 있다.

오늘은 이 지도에서 지나갈 수 있는 길이 몇 개 있는지 알아보려고 한다.길이란 한 행 또는 한 열 전부를 나타내며, 한쪽 끝에서 다른쪽 끝까지 지나가는 것이다.

이때, 길은 총 2N개가 있으며, 아래와 같다.



길을 지나갈 수 있으려면 길에 속한 모든 칸의 높이가 모두 같아야 한다.또는, 경사로를 놓아서 지나갈 수 있는 길을 만들 수 있다.경사로는 높이가 항상 1이며, 길이는 L이다.또, 개수는 매우 많아 부족할 일이 없다.경사로는 낮은 칸과 높은 칸을 연결하며, 아래와 같은 조건을 만족해야한다.
•경사로는 낮은 칸에 놓으며, L개의 연속된 칸에 경사로의 바닥이 모두 접해야 한다.
•낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
•경사로를 놓을 낮은 칸의 높이는 모두 같아야 하고, L개의 칸이 연속되어 있어야 한다.

아래와 같은 경우에는 경사로를 놓을 수 없다.
•경사로를 놓은 곳에 또 경사로를 놓는 경우
•낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
•낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
•경사로를 놓다가 범위를 벗어나는 경우

L = 2인 경우에 경사로를 놓을 수 있는 경우를 그림으로 나타내면 아래와 같다.



경사로를 놓을 수 없는 경우는 아래와 같다.



위의 그림의 가장 왼쪽부터 1번, 2번, 3번, 4번 예제라고 했을 때, 1번은 높이 차이가 1이 아니라서, 2번은 경사로를 바닥과 접하게 놓지 않아서, 3번은 겹쳐서 놓아서, 4번은 기울이게 놓아서 불가능한 경우이다.

가장 위에 주어진 그림 예의 경우에 지나갈 수 있는 길은 초록색으로, 지나갈 수 없는 길은 빨간색으로 표시되어 있으며, 아래와 같다.경사로의 길이 L = 2이다.



지도가 주어졌을 때, 지나갈 수 있는 길의 개수를 구하는 프로그램을 작성하시오.




입력


첫째 줄에 N(2 ≤ N ≤ 100)과 L(1 ≤ L ≤ N)이 주어진다.둘째 줄부터 N개의 줄에 지도가 주어진다.각 칸의 높이는 10보다 작거나 같은 자연수이다.




출력


첫째 줄에 지나갈 수 있는 길의 개수를 출력한다.
*/

#include <stdio.h>
#define MAX 105

int N;
int X;
int map[MAX][MAX];
int visit[MAX][MAX];

void input()
{
	int i, j;
	scanf("%d %d", &N, &X);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

int abs(int a)
{
	return a >= 0 ? a : -a;
}

int is_possible(int num)
{
	int i, j;
	int tmp;
	int cha;

	//가로
	if (num <= N) {
		tmp = map[num][1];
		for (i = 2; i <= N; i++) {
			if (map[num][i] == tmp) continue;
			cha = tmp - map[num][i];
			if (abs(cha) > 1) return 0;
			else if (cha == 1) {
				for (j = i; j < i + X; j++) {
					if (j>N || tmp - map[num][j] != 1) return 0;
					visit[num][j] = 1;
				}
				tmp = map[num][i];
			}
			else {
				for (j = i - 1; j >= i - X; j--) {
					if (j < 1 || map[num][j] - map[num][i] != -1 || visit[num][j]) return 0;
				}
				tmp = map[num][i];
			}
		}
	}
	//세로
	else {
		num -= N;
		tmp = map[1][num];
		for (i = 2; i <= N; i++) {
			if (map[i][num] == tmp) continue;
			cha = tmp - map[i][num];
			if (abs(cha) > 1) return 0;
			else if (cha == 1) {
				for (j = i; j < i + X; j++) {
					if (j>N || tmp - map[j][num] != 1) return 0;
					visit[j][num] = 1;
				}
				tmp = map[i][num];
			}
			else {
				for (j = i - 1; j >= i - X; j--) {
					if (j < 1 || map[j][num] - map[i][num] != -1 || visit[j][num]) return 0;
				}
				tmp = map[i][num];
			}
		}
	}
	return 1;
}

void init_visit(int num)
{
	int i;
	if (num <= N) {
		for (i = 1; i <= N; i++) {
			visit[num][i] = 0;
		}
	}
	else {
		num -= N;
		for (i = 1; i <= N; i++) {
			visit[i][num] = 0;
		}
	}
}

int get_ans()
{
	int ans = 0;
	int i;
	int k;
	k = 2 * N;

	for (i = 1; i <= k; i++) {
		//i번째 줄이 가능한지 체크
		if (is_possible(i)) {
			ans++;
		}
		init_visit(i);
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
