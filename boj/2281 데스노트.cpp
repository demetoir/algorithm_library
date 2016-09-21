
// dp ����� ������
//������ ����� ������ dp ���� ���� ���ҋ� 
//�������� ������ ���� ������ ���� ó���Ѵ�

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sc(a) scanf("%c",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define pii pair<int,int>
#define INF 2e9
#define LLINF ( (((LL)1) <<63)  -1)
#define AND &&
#define OR ||
#define FOR(i,s,e) for (int i = s; i<e; i++)
//////////////////////////////////////////////////////////////////////////////////

//2281 ������Ʈ

#define MAX_N 1001
#define MAX_M 1001

int n, m;
int dp[MAX_N];//n���� ������ �ּ� ��

int name[MAX_N]; // 1���� ����
int main() {
	si(n);
	si(m);
	for (int i = 0; i < n; i++) {
		si(name[i + 1]);
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
		int sum = name[i];
		for (int j = i - 1; j >= 0; j--) {
			if (sum > m)break;
			dp[i] = min(dp[i], (m - sum)*(m - sum) + dp[j]);
			sum += name[j] + 1;
		}
		//printf("##%d %d\n", i, dp[i]);
	}

	int ans = dp[n];
	int sum = name[n];
	for (int i = n - 1; i > 0; i--) {
		if (sum > m) break;
		ans = min(ans, dp[i]);
		sum += name[i] + 1;
	}
	printf("%d\n", ans);
	return 0;
}