//2212 ����

//���̵��
//dp�� �ƴϴ� ���̵���
//���� �������� ���δٸ� ������ ������ ���� �� ���� ������ �Ÿ����� �����ϴ°� �߿�
//�� �Ÿ����߿��� ���� ū ������ �ȴ�
//
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <functional>
#include <stdio.h>
#include <deque>
using namespace std;

#define LL				long long 
#define pii				pair<int, int>
#define si(a)           scanf("%d", &(a))
#define sc(a)           scanf("%c", &(a))
#define ss(a)           scanf("%s", (a))
#define all(a)			(a).begin() , (a).end()
#define INF             2e9
#define LLINF			1e17
#define MAX_N			10001


int n, m, k;
vector<int> A,v;
int main() {
	si(n);si(k);
	for (int i = 0,val; i < n; i++) {
		si(val);
		A.push_back(val);
	}

	sort(all(A));
	LL res = A[n - 1] - A[0];
	for (int i = 1; i < n; i++) 
		v.push_back(A[i] - A[i - 1]);

	sort(all(v));
	for (int i = 0; i < k - 1 &&  i<n-1; i++) {
		res -= v[ n -i -2];
	}
	printf("%lld\n",res);
	
	return 0;
}
