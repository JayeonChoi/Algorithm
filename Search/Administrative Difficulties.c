/*
출처 : ACM-ICPC > Regionals > Europe > Northwestern European Regional Contest > Benelux Algorithm Programming Contest > BAPC 2013 A번
https://www.acmicpc.net/problem/9367

<문제>
적절한 자동차는 첩보원의 필수품이다. BAPC로 알려진 한 렌트카 회사에서는 첩보원에게 어울릴 만한 자동차들을 방대하게 
구비해두고 있으며, 사후처리까지 담당하고 있다. 첩보원으로부터 반납받은 자동차를 관리하는 것은 분명 돈이 드는 일이다.
가솔린을 보충하거나, (대개의 경우에) 파손된 차를 수리하게 된다.

매 연말에, 회사를 이용한 모든 첩보원들은 이번 해에 이용한 차에 대해 비용을 지불하게 된다. 그러나 바로 지난주에 관리 
시스템에 치명적인 손상이 생겨 더 이상 사용할 수 없게 되었다. 겨우 복구된 자료는 자동차의 정보와 지난 해에 일어난 사건들
의 기록 일부 뿐이었다. 이 정보들을 이용해 회사에서는 각 첩보원들에게 렌탈한 자동차에 대한 비용을 수동으로 청구하려 한다.

모든 자동차는 원가와 함께 등록되어 있으며, 거기에 초기 대여 비용과 운행 거리 1킬로미터당의 추가 요금이 함께 등록되어 있다. 사
건 기록은 자동차의 대여, 반납, 그리고 자동차에 발생했던 사고, 이렇게 총 세 가지로 이루어져 있다. 만약 차를 대여한다면
첩보원은 그에 대한 초기 대여 비용을 지불해야 하고, 반납 시점까지의 주행 거리에 비례한 추가 요금을 지불해야 한다.
만일 대여 도중 사고로 인해 차가 파손되었다면 그에 대한 비용 또한 청구된다. 모든 사고 기록은 자동차의 파손율로 
기록되어 있다. 자동차의 수리에 대한 비용은 그 자동차의 원가에 파손율을 곱한 값으로 청구된다. 만일 소수점 이하의 어떤 
비용이 발생한다면 그 비용은 청구서에 올라가기 전 올림하여 합산된다.

다행히도 자동차의 목록은 완전히 복구되었다. 하지만 시스템 손상의 여파로 인해 사건 기록은 손상되어 있다.
첩보원들에게 일관성 없는 청구서를 보내는 것은 회사의 신뢰도에 크나큰 손실을 입힐 것이기 때문에, 당신은 존재하는 사건
기록이 일관성 있는지의 여부를 판정할 프로그램을 작성하고자 한다. 일관성 있는 기록의 조건은 다음과 같다.

첩보원은 차를 반납하기 전에 대여를 먼저 한다.
대여된 차는 반드시 반납된다.
한 명의 첩보원은 최대 하나의 차만을 동시에 대여할 수 있다.
사고는 첩보원이 차를 사용하던 기간에만 발생한다.

<입력>
입력의 첫 줄엔 테스트 케이스가 주어지며, 이 값은 100을 넘지 않는다.
각각의 테스트 케이스는 다음과 같이 구성되어 있다.
공백으로 구분된 두 개의 정수 n, m (0 ≤ n ≤ 500 , 0 ≤ m ≤ 10000) : 자동차 종류의 수, 사건 기록의 로그 수
n줄에 걸쳐 문자열 N과 공백으로 구분된 세 개의 정수 p, q, k (1 ≤ p ≤ 100 000; 1 ≤ q ≤ 1 000; 1 ≤ k ≤ 100) : 
자동차의 이름, 원가, 초기 대여 비용, 주행 거리 1 킬로미터당 추가되는 비용
m줄에 걸쳐, 사건의 발생 시각을 의미하는 정수 t (0 ≤ t ≤ 100000), 사건과 연관된 첩보원의 이름을 의미하는 문자열 S, 
사건의 종류를 나타내는 한 개의 알파벳 e,
e='p' (pick-up) 일 경우, 뒤이어 문자열 C : 대여된 차의 이름
e='r' (return) 일 경우, 정수 d : 주행 거리(단위는 킬로미터)
e='a' (accident) 일 경우, 정수 s (0 ≤ s ≤ 100) : 차의 파손율
차의 이름과 첩보원의 이름은 1글자 이상 40글자 이하인 알파벳 소문자로만 이루어져 있다. 각각의 테스트 케이스에 대해 
첩보원의 수는 최대 500명이며, 사건은 발생한 순서대로 주어진다.

<출력>
테스트 케이스당 다음을 출력한다.
각 줄에 첩보원의 이름, 총 청구 비용을 공백으로 구분하여 출력
만약 어떤 첩보원에 대한 사건 기록이 일관성이 없다면, 총 비용 대신 문자열 "INCONSISTENT" 를 출력.
출력은 첩보원의 이름을 사전순으로 정렬한 형태로 한다.
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

	//자동차 정렬 후 인덱스 만들기
	merge_sort_car(1, N);
	for (i = 0; i < 30; i++) car_info[i] = 0;
	for (i = 1; i <= N; i++) {
		int index = car[i].name[0] - 'a';
		if (car_info[index] == 0) car_info[index] = i;
	}

	//요원 정렬
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
			//말이 안되는 경우
			if (status == 0 && spy[j].status != 'p') continue;
			if (spy[j].status == 'a' && status == 'r') continue;
			if (spy[j].status == 'p' && status == 'a') continue;
			if (spy[j].status == status && status != 'a') continue;

			//렌트시
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
			//사고시
			else if (spy[j].status == 'a') {
				spy[j].price = spy[j - 1].price;
				spy[j].price += (tmpcar.price * spy[j].info + 99) / 100;
			}
			//리턴시
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