//스타트링크에서 판매하는 어린이용 장남감 중에서 가장 인기가 많은 제품은 구슬 탈출이다.구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.
//
//보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다.가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다.빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다.게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다.이때, 파란 구슬이 구멍에 들어가면 안된다.
//
//이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다.왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.
//
//각각의 동작에서 공은 동시에 움직인다.빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다.빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다.빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다.또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다.기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
//
//보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.
//
//입력
//첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M(3 ≤ N, M ≤ 10)이 주어진다.다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다.이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. '.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.
//
//입력되는 모든 보드의 가장자리에는 모두 '#'이 있다.구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.
//
//출력
//최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다.만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 - 1을 출력한다.

#include <stdio.h>

int N, M;
char map[15][15];
int visitA[15][15];
int visitB[15][15];
int rr, rc, br, bc, or, oc;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int min;
int flag;

void input()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%s", map[i] + 1);
		for (j = 1; j <= M; j++) {
			if (map[i][j] == 'R') {
				rr = i; rc = j;
			}
			else if (map[i][j] == 'B') {
				br = i; bc = j;
			}
			else if (map[i][j] == 'O') {
				or = i; oc = j;
			}
		}
	}
}

int who_first_move(int dir, int rr, int rc, int br, int bc)
{
	switch (dir)
	{
	case 0: {
		if (rr < br) return 1;
		else return 0;
	}
	case 1: {
		if (rr > br) return 1;
		else return 0;
	}
	case 2: {
		if (rc < bc) return 1;
		else return 0;
	}
	case 3: {
		if (rc > bc) return 1;
		else return 0;
	}
	}
}

void DFS(int cnt, int rr, int rc, int br, int bc)
{
	int R_nr, R_nc, r_orir, r_oric;
	int B_nr, B_nc, b_orir, b_oric;
	int i;

	if (br == or && bc == oc) {
		return;
	}

	if (rr == or && rc == oc) {
		if (cnt < min) min = cnt;
		return;
	}

	if (cnt >= min || cnt >= 10) return;
	//--------------------------------------------
	for (i = 0; i < 4; i++) {
		R_nr = rr + dr[i]; R_nc = rc + dc[i];
		B_nr = br + dr[i]; B_nc = bc + dc[i];

		if (map[R_nr][R_nc] == '#' || (R_nr == br && R_nc == bc)) {
			if (map[B_nr][B_nc] == '#' || (rr == B_nr && rc == B_nc)) {
				continue;
			}
		}
		r_orir = rr; r_oric = rc; b_orir = br; b_oric = bc;

		flag = 0;
		if (who_first_move(i, rr, rc, br, bc)) {
			while (map[R_nr][R_nc] != '#' && (R_nr != b_orir || R_nc != b_oric || flag)) {
				r_orir = R_nr; r_oric = R_nc;
				if (r_orir == or && r_oric == oc) {
					flag = 1;
					break;
				}
				R_nr += dr[i]; R_nc += dc[i];
			}

			while (map[B_nr][B_nc] != '#' && (r_orir != B_nr || r_oric != B_nc || flag)) {
				b_orir = B_nr; b_oric = B_nc;
				if (b_orir == or && b_oric == oc) {
					flag = 1;
					break;
				}
				B_nr += dr[i]; B_nc += dc[i];
			}

			DFS(cnt + 1, r_orir, r_oric, b_orir, b_oric);

		}

		else {
			while (map[B_nr][B_nc] != '#' && (r_orir != B_nr || r_oric != B_nc || flag)) {
				b_orir = B_nr; b_oric = B_nc;
				if (b_orir == or && b_oric == oc) {
					flag = 1;
					break;
				}
				B_nr += dr[i]; B_nc += dc[i];
			}

			while (map[R_nr][R_nc] != '#' && (R_nr != b_orir || R_nc != b_oric || flag)) {
				r_orir = R_nr; r_oric = R_nc;
				if (r_orir == or && r_oric == oc) {
					flag = 1;
					break;
				}
				R_nr += dr[i]; R_nc += dc[i];
			}
			DFS(cnt + 1, r_orir, r_oric, b_orir, b_oric);
		}
	}
}

int main()
{
	input();
	min = 11;
	flag = 0;
	DFS(0, rr, rc, br, bc);
	if (min == 11) printf("%d", -1);
	else printf("%d", min);
	return 0;
}