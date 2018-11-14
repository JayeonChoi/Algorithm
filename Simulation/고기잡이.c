/*
출처 : 윌텍(codexpert.ort/willtek)

<문제>
한국인의 식단에서 생선은 매우 중요한 단백질 공급원이다. 반면, 지구 온난화로 인한 바닷물의 온도 상승, 
그리고 지금까지 마구잡이로 물고기를 잡은 결과로 점점 우리나라의 바다에서 물고기의 수가 줄어들고 있다.
정부에서는 이 문제를 심각하게 생각하여, 물고기를 잡을 수 있는 곳과 여기서 고기잡이 배가 사용할 수 있는 
그물의 폭에 제한을 두었다. 물고기는 바다 표면 근처에 살기 때문에, 그물의 높이는 중요하지 않다. 따라서 
그물은 길이가 ℓ인 직선으로 생각할 수 있고, 물고기를 잡을 때, 그물은 한 변의 길이가 1 이상 정수인 직사각형 모양으로
치게 된다. 예를 들어, ℓ=10 이라면, 칠 수 있는 그물의 모양은 1×4, 2×3, 3×2, 4×1 과 같이 4가지 형태의 직사각형이 된다.

고기를 잡을 수 있는 곳은 N×N 크기의 모눈종이 모양으로 되어 있다. 각 모눈에는 좌표가 주어지며, 
가장 왼쪽 위 모눈이 (1,1)이고, 가장 오른쪽 아래 모눈이 (N,N)이다. 총 M마리의 물고기가 서로 다른 모눈 위에 한 마리씩
살고 있으며, 물고기는 움직이지 않는다. 고기잡이 배는 한 모눈 위에 위치를 잡고 자신의 오른쪽과 아래쪽으로 그물을 친다.
일단 그물을 치면, 그물 안, 그리고 그물에 걸친 물고기들을 잡을 수 있다. 
고기를 잡을 수 있는 영역 밖으로 그물을 치는 경우는 없다.

고기를 잡을 수 있는 영역, 물고기의 위치, 그물의 폭이 주어졌을 때 한 번의 그물치기로 잡을 수 있는 가장 많은
물고기의 마리 수를 구하는 프로그램을 작성하시오.

<입력>
첫 번째 줄에는 모눈종이의 크기, 그물의 길이, 물고기의 수를 나타내는 세 개의 정수 N, ℓ, M 이 하나의 공백을 두고 
주어진다. 단, 2≤N≤10,000, 4≤ ℓ≤100, 1≤M≤100 이다. ℓ은 ℓ≤4N 을 만족하는 짝수이다. 두 번째 줄부터 이후 M 개의
줄에는 각 물고기의 좌표가 하나의 공백을 두고 주어진다. 물고기의 좌표 순서는 무작위로 주어진다.
<출력>
출력 파일의 첫 줄에 주어진 입력에서 잡을 수 있는 가장 많은 물고기의 마리 수를 하나의 정수로 출력한다. .
*/

#include <stdio.h>
#define MAX 10010

int l;
char sea[MAX][MAX];
int M;
int N;
typedef struct xy {
	int r, c;
} P;
P fish[101];
int dr[] = { 0, 0, 1, 1, 1 };
int dc[] = { 0, -1, -1, 0, 1 };
int sol;

void input(void) {
	int i;
	int r, c;

	scanf("%d %d %d", &N, &l, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &r, &c);
		sea[r][c] = '1';
		fish[i] = (P){ r, c };
	}
}

int fishing(int g)
{
	int nr, nc;
	P out;
	int f;
	int max = 0;

	register int i, j;
	for (i = 0; i < M; i++) {
		out = fish[i];
		for (j = 0; j < 5; j++) {
			nr = out.r + dr[j];
			nc = out.c + dc[j];
			if (nr<1 || nc<1 || nr>N || nc>N) continue;
			f = get_fish(nr, nc, g);
			if (f>max) max = f;
		}
	}

	return max;
}

int get_fish(int sr, int sc, int g)
{
	register int i, j;
	int gy = l / 2 - g;
	int f[4] = { 0 };
	int max = 0;

	for (i = sr; i <= sr + g; i++) {
		for (j = sc; j <= sc + gy; j++) {
			if (i<1 || j<1 || i>N || j>N) continue;
			if (sea[i][j] == '1') f[0]++;
		}
	}

	for (i = sr; i <= sr + g; i++) {
		for (j = sc; j >= sc - gy; j--) {
			if (i<1 || j<1 || i>N || j>N) continue;
			if (sea[i][j] == '1') f[1]++;
		}
	}
	for (i = sr; i >= sr - g; i--) {
		for (j = sc; j <= sc + gy; j++) {
			if (i<1 || j<1 || i>N || j>N) continue;
			if (sea[i][j] == '1') f[2]++;
		}
	}
	for (i = sr; i >= sr + g; i--) {
		for (j = sc; j >= sc - gy; j--) {
			if (i<1 || j<1 || i>N || j>N) continue;
			if (sea[i][j] == '1') f[3]++;
		}
	}

	for (i = 0; i < 4; i++) {
		if (f[i]>max) max = f[i];
	}

	return max;
}
int main()
{
	int i;
	int g;
	int tmp;
	input();
	g = l / 2;
	for (i = 1; i<g; i++) {
		tmp = fishing(i);
		if (tmp>sol) sol = tmp;
	}

	printf("%d", sol);
	return 0;
}
