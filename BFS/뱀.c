
/*출처 : 백준 알고리즘
문제


'Dummy' 라는 도스게임이 있다.이 게임에는 뱀이 나와서 기어다니는데, 사과를 먹으면 뱀 길이가 늘어난다.뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.

게임은 NxN 정사각 보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다.보드의 상하좌우 끝에 벽이 있다.게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다.뱀은 처음에 오른쪽을 향한다.

뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.
•먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
•만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
•만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.즉, 몸길이는 변하지 않는다.

사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.




입력


첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)

다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다.사과의 위치는 모두 다르며, 맨 위 맨 좌측(1행 1열) 에는 사과가 없다.

다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)

다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데, 정수 X와 문자 C로 이루어져 있으며.X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다.X는 10, 000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.




출력


첫째 줄에 게임이 몇 초에 끝나는지 출력한다.*/

#include <stdio.h>
int N, K, L;
int map[110][110];
int dir;
int sr, sc;
int Ldir[] = { 2, 3, 1, 0 };
int Ddir[] = { 3, 2, 0, 1 };
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int lookup[10010];
char lr[10010];
typedef struct st {
	int r, c;
} P;
P que[101000];
int wp, rp;

void input()
{
	int r, c;
	int i, j;
	char d;


	sr = 1; sc = 1;
	dir = 3;
	map[sr][sc] = 1;
	que[wp++] = (P) { 1, 1 };

	scanf("%d %d", &N, &K);
	for (i = 1; i <= K; i++) {
		scanf("%d %d", &r, &c);
		map[r][c] = 2;
	}

	scanf("%d", &L);
	for (i = 1; i <= L; i++) {
		scanf("%d %c", &r, &d);
		lookup[r] = 1;
		lr[r] = d;
	}

	//맵 테두리에 벽 그리기
	for (i = 0; i <= N + 1; i++) {
		for (j = 0; j <= N + 1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) {
				map[i][j] = -1;
			}
		}
	}
}

int get_ans()
{
	int time;
	P tail;

	for (time = 1;; time++) {
		sr += dr[dir]; sc += dc[dir];
		if (map[sr][sc] == 1 || map[sr][sc] == -1) break;
		if (map[sr][sc] == 2) {
			que[wp++] = (P) { sr, sc };
			map[sr][sc] = 1;
		}
		else if (map[sr][sc] == 0) {
			map[sr][sc] = 1;
			tail = que[rp++];
			map[tail.r][tail.c] = 0;
			que[wp++] = (P){ sr, sc };
		}

		if (time > 10000) continue;
		if (lookup[time]) {
			if (lr[time] == 'D') dir = Ddir[dir];
			else dir = Ldir[dir];
		}
	}

	return time;
}

int main()
{
	int sol;
	input();
	sol = get_ans();
	printf("%d", sol);
	return 0;
}
