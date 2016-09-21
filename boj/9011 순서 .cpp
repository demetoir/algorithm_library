//9011 ���� 
//�����ϴ� ����
//ũ�Ⱑ �����Ƿ� �׳� �������� Ǯ���ִ�
//ũ�Ⱑ ũ�� �ε���Ʈ���� ���׸�ƮƮ���� Ǯ��Ѵ�
//���� ������ ���� �����ϸ� ���� ã�����ְ�
//�Ź� �տ� �����ִ� ������� ����� ������Ʈ �ؾ��Ѵ�

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

#define MAX_N 1000
int n;
int num[MAX_N];
int ans[MAX_N];
int check[MAX_N];
int main() {
	int test = 0;
	si(test);
	for (; test > 0; test--) {
		si(n);

		for (int i = 0; i < n; i++) si(num[i]);

		int flag = false;
		memset(check, 0, sizeof(check));
		memset(ans, 0, sizeof(ans));
		for (int i = n - 1; i >= 0; i--) {
			int count = 0;
			for (int j = 1; j <= n; j++) {
				if (check[j] == 1) continue;
				count += 1;
				if (count == num[i] + 1) {
					ans[i] = j;
					check[j] = 1;
					break;
				}
			}
			if (ans[i] == 0) {
				flag = true;
				break;
			}
		}
		if (flag)
			printf("IMPOSSIBLE\n");
		else {
			for (int i = 0; i<n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
	}
	return 0;
}