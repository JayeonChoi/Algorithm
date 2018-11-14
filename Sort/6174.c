/*
출처 : Jungol1621 (http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=894&sca=50&sfl=wr_subject&stx=6174&sop=and)
문제:
1949년 인도 수학자 Kaprekar는 Kaprekar 연산을 고안해냈다. Kaprekar 연산은 네 자리 수 중 모든 자리수가 같지 않은 수(1111, 2222 등을 제외한)의 각 자리의 숫자를 재배열해서 만들 수 있는 가장 큰 수와 가장 작은 수를 만들어서 그 차이를 계산하는데, 그 결과로 나온 새로운 숫자를 갖고 같은 과정을 반복하는 것이다.

간단한 연산이지만 Kaprekar는 이 연산이 놀라운 결과를 보여준다는 것을 발견했다. 올해 연도인 2008로 그 결과를 알아보자. 2008로 만들 수 있는 가장 큰 수는 8200이고 가장 작은 수는 0028이다.

8200 – 0028 = 8172
8721 – 1278 = 7443
7443 – 3447 = 3996
9963 – 3699 = 6264
6642 – 2466 = 4176
7641 – 1467 = 6174
7641 – 1467 = 6174

6174에 도달한 다음에는 매번 6174를 만들어 낸다. 2008만이 유독 6174에 도달하는 것이 아니라 한 숫자로 이루어지지 않은 모든 네 자리 수는 Kaprekar 연산을 통해 6174로 가게 된다. 2008의 경우 6 단계를 거쳐 6174로 가게 되었는데, 다른 숫자가 입력으로 주어졌을 때 몇 단계 만에 6174로 가는지 알아내는 프로그램을 작성하시오.
*/

#include <stdio.h>
#include <string.h>

void main()
{
	int ans = 0;
	int i, j;
	int big = 0, small = 0, cha = 0;

	char bigger[5] = { 0 };
	char smaller[5] = { 0 };
	char instr[5] = { 0 };
	char tmp;

	scanf("%s", instr);

	for (;;) {
		strcpy(bigger, instr);
		strcpy(smaller, instr);
		//오름차순
		for (i = 0; i < 3; i++) {
			for (j = i + 1; j < 4; j++) {
				if (bigger[i]<bigger[j]) {
					tmp = bigger[i];
					bigger[i] = bigger[j];
					bigger[j] = tmp;
				}
			}
		}

		//내림차순
		for (i = 0; i < 3; i++) {
			for (j = i + 1; j < 4; j++) {
				if (smaller[i] > smaller[j]) {
					tmp = smaller[i];
					smaller[i] = smaller[j];
					smaller[j] = tmp;
				}
			}
		}

		//빼기
		big = 0;
		small = 0;
		for (i = 0; i < 4; i++) {
			big *= 10;
			small *= 10;

			big += bigger[i] - '0';
			small += smaller[i] - '0';
		}

		cha = big - small;
		ans++;
		if (cha == 6174) break;

		instr[3] = cha % 10 + '0';
		instr[2] = (cha / 10) % 10 + '0';
		instr[1] = (cha / 100) % 10 + '0';
		instr[0] = (cha / 1000) + '0';
	}

	printf("%d", ans);

}
