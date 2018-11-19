/*
출처 : 정올 알고리즘(그리디) 2461 : 공주님의 정원
http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1721&sca=50&sfl=wr_subject&stx=%EC%A0%95%EC%9B%90&sop=and
<문제>
오늘은 공주님이 태어난 경사스러운 날이다. 왕은 이 날을 기념하기 위해 늘 꽃이 피어있는 작은 정원을 만들기로 결정했다.
총 N개의 꽃이 있는데, 꽃은 모두 같은 해에 피어서 같은 해에 진다. 하나의 꽃은 피는 날과 지는 날이 정해져 있다. 예를 들어, 5월 8일 피어서 6월 13일 지는 꽃은 5월 8일부터 6월 12일까지는 꽃이 피어 있고, 6월 13일을 포함하여 이후로는 꽃을 볼 수 없다는 의미이다. (올해는 4, 6, 9, 11월은 30일까지 있고, 1, 3, 5, 7, 8, 10, 12월은 31일까지 있으며, 2월은 28일까지만 있음)
이러한 N개의 꽃들 중에서 다음의 두 조건을 만족하는 꽃들을 선택하고 싶다.
1. 공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 한다.
2. 정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다.
N개의 꽃들 중에서 위의 두 조건을 만족하는, 즉 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 꽃들을 선택할 때, 선택한 꽃들의 최소 개수를 출력하는 프로그램을 작성하시오.

<제약조건>
전체 테스트 데이터의 20%는 N≤30
전체 테스트 데이터의 50%는 N≤10,000

<입력>
첫째 줄에는 꽃들의 총 개수 N(1≤N≤100,000)이 주어진다.
다음 개의 줄에는 각 꽃이 피는 날짜와 지는 날짜가 주어진다.
하나의 날짜는 월과 일을 나타내는 두 숫자로 표현된다. 예를 들어서, 3 8 7 31은 꽃이 3월 8일에 피어서 7월 31일에 진다는 것을 나타낸다.
<출력>
첫째 줄에 선택한 꽃들의 최소 개수를 출력한다.
만약 두 조건을 만족하는 꽃들을 선택할 수 없다면 0을 출력한다.
*/

#include <stdio.h>
int N;
int visit[100010];
int sdate[100010];
int edate[100010];
int sol;
int max = 0;
int maxi;

void input()
{
	int sm, sd, em, ed;
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &sm, &sd);
		scanf("%d %d", &em, &ed);

		sdate[i] = sm * 100 + sd;
		edate[i] = em * 100 + ed;
	}

	for (i = 0; i < N; i++) {
		if (sdate[i] <= 301) {
			if (edate[i] > max) {
				max = edate[i];
				maxi = i;
			}
		}
	}
	max--;
}

int greedy(int maxi)
{
	int start;
	int i;
	int tmpmax;
	int tmpstart;

	start = maxi;
	tmpstart = start;

	while (edate[start] <= 1130) {
		sol++;
		visit[start] = 1;
		tmpmax = max;
		start = tmpstart;
		for (i = 0; i < N; i++) {
			if (visit[i]) continue;
			if (sdate[i] > edate[start]) continue;

			if (edate[i] > max) {
				max = edate[i];
				tmpstart = i;
				max--;
			}
		}

		if (tmpmax == max && tmpmax<1130) {
			return 0;
		}

	}
	return sol;
}

int main(void)
{
	int ans;

	input();
	ans = greedy(maxi);
	printf("%d", ans);

	return 0;
}
