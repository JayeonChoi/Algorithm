//��ŸƮ��ũ���� �Ǹ��ϴ� ��̿� �峲�� �߿��� ���� �αⰡ ���� ��ǰ�� ���� Ż���̴�.���� Ż���� ���簢�� ���忡 ���� ������ �Ķ� ������ �ϳ��� ���� ����, ���� ������ ������ ���� ������ �����̴�.
//
//������ ���� ũ��� N, ���� ũ��� M�̰�, ���ǻ� 1��1ũ���� ĭ���� �������� �ִ�.���� �ٱ� ��� ���� ��� ������ �ְ�, ���忡�� ������ �ϳ� �ִ�.���� ������ �Ķ� ������ ũ��� ���忡�� 1��1ũ���� ĭ�� ���� ä��� �������̰�, ���� �ϳ��� �� �ִ�.������ ��ǥ�� ���� ������ ������ ���ؼ� ������ ���̴�.�̶�, �Ķ� ������ ���ۿ� ���� �ȵȴ�.
//
//�̶�, ������ ������ �ǵ帱 ���� ����, �߷��� �̿��ؼ� �̸� ���� ������ �Ѵ�.�������� ����̱�, ���������� ����̱�, �������� ����̱�, �Ʒ������� ����̱�� ���� �� ���� ������ �����ϴ�.
//
//������ ���ۿ��� ���� ���ÿ� �����δ�.���� ������ ���ۿ� ������ ����������, �Ķ� ������ ���ۿ� ������ �����̴�.���� ������ �Ķ� ������ ���ÿ� ���ۿ� ������ �����̴�.���� ������ �Ķ� ������ ���ÿ� ���� ĭ�� ���� �� ����.��, ���� ������ �Ķ� ������ ũ��� �� ĭ�� ��� �����Ѵ�.����̴� ������ �׸��ϴ� ���� �� �̻� ������ �������� ���� �� �����̴�.
//
//������ ���°� �־����� ��, �ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù ��° �ٿ��� ������ ����, ���� ũ�⸦ �ǹ��ϴ� �� ���� N, M(3 �� N, M �� 10)�� �־�����.���� N���� �ٿ� ������ ����� ��Ÿ���� ���� M�� ���ڿ��� �־�����.�� ���ڿ��� '.', '#', 'O', 'R', 'B' �� �̷���� �ִ�. '.'�� �� ĭ�� �ǹ��ϰ�, '#'�� ���� �̵��� �� ���� ��ֹ� �Ǵ� ���� �ǹ��ϸ�, 'O'�� ������ ��ġ�� �ǹ��Ѵ�. 'R'�� ���� ������ ��ġ, 'B'�� �Ķ� ������ ��ġ�̴�.
//
//�ԷµǴ� ��� ������ �����ڸ����� ��� '#'�� �ִ�.������ ������ �� �� �̸�, ���� ������ �Ķ� ������ �׻� 1���� �־�����.
//
//���
//�ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ����Ѵ�.����, 10�� ���Ϸ� �������� ���� ������ ������ ���� ���� �� ������ - 1�� ����Ѵ�.

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