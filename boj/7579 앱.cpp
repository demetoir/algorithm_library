// 7579 ��

//dp ���� ���� + ���̵��
//�ٽ� ������
//ó������ �׸���� �ߴٰ� Ʋ��
//�׷��� dp ���� ���� Ǭ��
//�޸𸮸� ���ڷ� ������ �ʹ� Ŀ�� �ȵǹǷ�
//����� ���ڷ� ��´�
//�ܼ��� �ֳ� �ȳֳķ� �����ϴ°� ���� ���÷��߰ٴ�
//�̰Ÿ� ��ͷ� ¥�°Ÿ� dp�� �ű��ȴ�
//������ �����̵� ����� ���� ���� i������ �ϴµ� �������� ������ �ʴ� �뷮�� 
//�Ѿ�� �Ÿ� ����ؾ��Ѵ�
//i��°�� �������� ó���϶��� ���� ó���Ѵ�

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>
#include <limits.h>

typedef long long LL;
using namespace std;

#define pii pair<int, int>
#define PLL pair<LL,LL>
#define si(a) scanf("%d", &(a))
#define sc(a) scanf("%c", &(a))
#define ss(a) scanf("%s",a)
#define sll(a) scanf("%lld", &(a))
#define pi(a) printf("%d\n", (a))
#define pc(a) printf("%c",a);
#define ENDL printf("\n");
#define pll(a) printf("%lld\n", (a))
#define INF 2e9
#define LLINF 1e17 
#define all(a) (a).begin(),(a).end()

#define MAX_N 101l

LL memory[MAX_N];
LL cost[MAX_N];
LL n, m;
LL ans;

int main() {
	sll(n);
	sll(m);

	for (LL i = 0, val; i < n; i++) sll(memory[i]);
	for (LL i = 0, val; i < n; i++) sll(cost[i]);

	vector<LL> dp1(10001,0);
	for (int i = 0; i < n; i++) {
		vector<LL> dp2 = dp1;

		dp2[cost[i]] = max(dp2[cost[i]], memory[i]);
		for (int j = 0; j < 10001; j++) {
			if (dp1[j] == 0) continue;
			if (j + cost[i] > 10000) break;
			dp2[j + cost[i]] = max(dp2[j +cost[i]] , dp1[j] + memory[i]);
		}
		dp1 = dp2;
	}

	for (int i = 0; i < 10001; i++) {
		if (dp1[i] >= m) {
			ans = i;
			break;
		}
	}

	pll(ans);
	return 0;
}
