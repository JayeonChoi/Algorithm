/*
��ó : ACM-ICPC > Regionals > Europe > Northwestern European Regional Contest > Benelux Algorithm Programming Contest > BAPC 2013 A��
https://www.acmicpc.net/problem/9367

<����>
������ �ڵ����� ø������ �ʼ�ǰ�̴�. BAPC�� �˷��� �� ��Ʈī ȸ�翡���� ø�������� ��︱ ���� �ڵ������� ����ϰ� 
�����صΰ� ������, ����ó������ ����ϰ� �ִ�. ø�������κ��� �ݳ����� �ڵ����� �����ϴ� ���� �и� ���� ��� ���̴�.
���ָ��� �����ϰų�, (�밳�� ��쿡) �ļյ� ���� �����ϰ� �ȴ�.

�� ������, ȸ�縦 �̿��� ��� ø�������� �̹� �ؿ� �̿��� ���� ���� ����� �����ϰ� �ȴ�. �׷��� �ٷ� �����ֿ� ���� 
�ý��ۿ� ġ������ �ջ��� ���� �� �̻� ����� �� ���� �Ǿ���. �ܿ� ������ �ڷ�� �ڵ����� ������ ���� �ؿ� �Ͼ ��ǵ�
�� ��� �Ϻ� ���̾���. �� �������� �̿��� ȸ�翡���� �� ø�����鿡�� ��Ż�� �ڵ����� ���� ����� �������� û���Ϸ� �Ѵ�.

��� �ڵ����� ������ �Բ� ��ϵǾ� ������, �ű⿡ �ʱ� �뿩 ���� ���� �Ÿ� 1ų�ι��ʹ��� �߰� ����� �Բ� ��ϵǾ� �ִ�. ��
�� ����� �ڵ����� �뿩, �ݳ�, �׸��� �ڵ����� �߻��ߴ� ���, �̷��� �� �� ������ �̷���� �ִ�. ���� ���� �뿩�Ѵٸ�
ø������ �׿� ���� �ʱ� �뿩 ����� �����ؾ� �ϰ�, �ݳ� ���������� ���� �Ÿ��� ����� �߰� ����� �����ؾ� �Ѵ�.
���� �뿩 ���� ���� ���� ���� �ļյǾ��ٸ� �׿� ���� ��� ���� û���ȴ�. ��� ��� ����� �ڵ����� �ļ����� 
��ϵǾ� �ִ�. �ڵ����� ������ ���� ����� �� �ڵ����� ������ �ļ����� ���� ������ û���ȴ�. ���� �Ҽ��� ������ � 
����� �߻��Ѵٸ� �� ����� û������ �ö󰡱� �� �ø��Ͽ� �ջ�ȴ�.

�������� �ڵ����� ����� ������ �����Ǿ���. ������ �ý��� �ջ��� ���ķ� ���� ��� ����� �ջ�Ǿ� �ִ�.
ø�����鿡�� �ϰ��� ���� û������ ������ ���� ȸ���� �ŷڵ��� ũ��ū �ս��� ���� ���̱� ������, ����� �����ϴ� ���
����� �ϰ��� �ִ����� ���θ� ������ ���α׷��� �ۼ��ϰ��� �Ѵ�. �ϰ��� �ִ� ����� ������ ������ ����.

ø������ ���� �ݳ��ϱ� ���� �뿩�� ���� �Ѵ�.
�뿩�� ���� �ݵ�� �ݳ��ȴ�.
�� ���� ø������ �ִ� �ϳ��� ������ ���ÿ� �뿩�� �� �ִ�.
���� ø������ ���� ����ϴ� �Ⱓ���� �߻��Ѵ�.

<�Է�>
�Է��� ù �ٿ� �׽�Ʈ ���̽��� �־�����, �� ���� 100�� ���� �ʴ´�.
������ �׽�Ʈ ���̽��� ������ ���� �����Ǿ� �ִ�.
�������� ���е� �� ���� ���� n, m (0 �� n �� 500 , 0 �� m �� 10000) : �ڵ��� ������ ��, ��� ����� �α� ��
n�ٿ� ���� ���ڿ� N�� �������� ���е� �� ���� ���� p, q, k (1 �� p �� 100 000; 1 �� q �� 1 000; 1 �� k �� 100) : 
�ڵ����� �̸�, ����, �ʱ� �뿩 ���, ���� �Ÿ� 1 ų�ι��ʹ� �߰��Ǵ� ���
m�ٿ� ����, ����� �߻� �ð��� �ǹ��ϴ� ���� t (0 �� t �� 100000), ��ǰ� ������ ø������ �̸��� �ǹ��ϴ� ���ڿ� S, 
����� ������ ��Ÿ���� �� ���� ���ĺ� e,
e='p' (pick-up) �� ���, ���̾� ���ڿ� C : �뿩�� ���� �̸�
e='r' (return) �� ���, ���� d : ���� �Ÿ�(������ ų�ι���)
e='a' (accident) �� ���, ���� s (0 �� s �� 100) : ���� �ļ���
���� �̸��� ø������ �̸��� 1���� �̻� 40���� ������ ���ĺ� �ҹ��ڷθ� �̷���� �ִ�. ������ �׽�Ʈ ���̽��� ���� 
ø������ ���� �ִ� 500���̸�, ����� �߻��� ������� �־�����.

<���>
�׽�Ʈ ���̽��� ������ ����Ѵ�.
�� �ٿ� ø������ �̸�, �� û�� ����� �������� �����Ͽ� ���
���� � ø������ ���� ��� ����� �ϰ����� ���ٸ�, �� ��� ��� ���ڿ� "INCONSISTENT" �� ���.
����� ø������ �̸��� ���������� ������ ���·� �Ѵ�.
*/

#include <stdio.h>
int N, M;
typedef struct cha {
	char name[50];
	int price;
	int rent_fee;
	int dist_fee;
} C;
typedef struct people {
	char name[50];
	char carname[50];
	int time;
	char status;
	int info;
	int price;
} P;
C car[550];
P spy[10010];
P temp[10010];
int spy_info[550];
int car_info[30];
int cnt;

void str_cpy(char *dest, const char *st)
{
	while (*dest++ = *st++);
}

int str_cmp(char *a, char *b)
{
	while ((*a == *b) && *a) {
		a++; b++;
	}
	return *a - *b;
}

int func_cmp2(P comp1, P comp2)
{
	int t = str_cmp(comp1.name, comp2.name);
	if (t > 0) return 1;
	else if (t == 0 && comp1.time > comp2.time) return 1;
	else return 0;
}

void merge_sort_car(int s, int e)
{
	int i, j, k, m;
	C tmp[550];
	if (s >= e) return;
	m = (s + e) / 2; i = k = s; j = m + 1;
	merge_sort_car(s, m);
	merge_sort_car(j, e);
	while (i <= m || j <= e) {
		if (i > m || (j <= e && str_cmp(car[i].name, car[j].name)>0)) tmp[k++] = car[j++];
		else tmp[k++] = car[i++];
	}

	for (i = s; i <= e; i++) car[i] = tmp[i];
}

void merge_sort_spy(int s, int e)
{
	int i, j, k, m;

	if (s >= e) return;
	m = (s + e) / 2; i = k = s; j = m + 1;
	merge_sort_spy(s, m);
	merge_sort_spy(j, e);
	while (i <= m || j <= e) {
		if (i > m || (j <= e && func_cmp2(spy[i], spy[j]))) temp[k++] = spy[j++];
		else temp[k++] = spy[i++];
	}

	for (i = s; i <= e; i++) spy[i] = temp[i];
}

void input()
{
	int i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s %d %d %d", &car[i].name, &car[i].price, &car[i].rent_fee, &car[i].dist_fee);
	for (i = 0; i < M; i++) {
		scanf("%d %s %c", &spy[i].time, &spy[i].name, &spy[i].status);
		if (spy[i].status == 'p') scanf("%s", &spy[i].carname);
		else scanf("%d", &spy[i].info);
		spy[i].price = 0;
	}
	spy[M] = (P) { "", "", 0, 0, 0, 0 };

	//�ڵ��� ���� �� �ε��� �����
	merge_sort_car(1, N);
	for (i = 0; i < 30; i++) car_info[i] = 0;
	for (i = 1; i <= N; i++) {
		int index = car[i].name[0] - 'a';
		if (car_info[index] == 0) car_info[index] = i;
	}

	//��� ����
	merge_sort_spy(0, M - 1);

	cnt = 0;
}

void get_ans()
{
	int i = 0, j, k;

	char cmpname[50];
	char status;
	C tmpcar = { 0 };

	for (; i < M;) {
		str_cpy(cmpname, spy[i].name);
		status = 0;
		for (j = i; j <= M; j++) {
			if (str_cmp(cmpname, spy[j].name)) {
				spy_info[cnt++] = j - 1;
				for (k = i; k < j; k++) {
					if (spy[k].price == 0) {
						spy[j - 1].price = -1;
						break;
					}
				}
				if (spy[j - 1].status != 'r') spy[j - 1].price = -1;
				i = j;
				break;
			}
			//���� �ȵǴ� ���
			if (status == 0 && spy[j].status != 'p') continue;
			if (spy[j].status == 'a' && status == 'r') continue;
			if (spy[j].status == 'p' && status == 'a') continue;
			if (spy[j].status == status && status != 'a') continue;

			//��Ʈ��
			if (spy[j].status == 'p') {
				if (status != 0) spy[j].price = spy[j - 1].price;
				int ind = car_info[spy[j].carname[0] - 'a'];
				for (k = ind;; k++) {
					if (str_cmp(spy[j].carname, car[k].name) == 0) {
						tmpcar = car[k];
						break;
					}
				}
				spy[j].price += tmpcar.rent_fee;
			}
			//����
			else if (spy[j].status == 'a') {
				spy[j].price = spy[j - 1].price;
				spy[j].price += (tmpcar.price * spy[j].info + 99) / 100;
			}
			//���Ͻ�
			else {
				spy[j].price = spy[j - 1].price;
				spy[j].price += tmpcar.dist_fee * spy[j].info;
			}
			status = spy[j].status;
		}
	}
}

int main()
{
	int t, testcase;
	int i;

	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		input();
		get_ans();
		for (i = 0; i < cnt; i++) {
			int ind = spy_info[i];
			printf("%s ", spy[ind].name);
			if (spy[ind].price == -1) printf("%s\n", "INCONSISTENT");
			else printf("%d\n", spy[ind].price);
		}
	}
	return 0;
}