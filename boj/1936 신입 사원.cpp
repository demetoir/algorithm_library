//1936 ���� ���

//ó������ lis�� �����Ѵ�
//�׸��� Ʋ����
//����޴´�
//�׸��� �˰� �ȴ� ������ �߸����� �ѰŸ�
//�׸���� Ǫ�µ� �ϴ� �������� �����Ѵ�
//�׸��� �ٸ�������...
//���� �ù�..

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>

typedef long long LL;
#define pii pair<int, int>
#define si(a) scanf("%d", &(a))
#define sc(a) scanf("%c", &(a))
#define ss(a) scanf("%s",a)
#define sLL(a) scanf("%lld", &(a))
#define pi(a) printf("%d\n", (a))
#define pc(a) printf("%c",a);
#define ENDL printf("\n");
#define pll(a) printf("%lld\n", (a))

#define INF 2e9
#define LLINF 1e17
#define all(a) (a).begin(), (a).end()
#define MAX_N 100001

using namespace std;

#define MOD 360000

LL n;
pii A[MAX_N];
bool cmp(pii a, pii b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}
int main() {	
	int test = 0; si(test);
	for (; test > 0; test--) {
		int ans = 0;
		sLL(n);
		for (int i = 0,a,b; i < n; i++) {
			si(a); si(b);
			A[i] = pii(a, b);
		}
			
		sort(A ,A+n, cmp);

		ans = 1;
		int val = A[0].second;
		for (int i = 1; i < n; i++) {
			if (val > A[i].second) {
				ans++;
				val = A[i].second;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
