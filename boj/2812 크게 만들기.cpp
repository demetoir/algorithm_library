//2812 ũ�� �����

//�Խ��ǿ��� �׽�Ʈ ���̽��� ���� Ǯ����
//�տ������� k�� ����� ������ ���� ���� ���� ���� K+1���� ������
//�տ��� k+1�� �� ���� ũ�� ���� �����°�(val)�� ����� ���� ���� ������
//���� ũ�� ���������°��� ���ڰ� 0~9�̹Ƿ� ���� ���� ���ڸ��� �� �ε����� ������ 
//���� lower bound �� ã�´�
//���� ������ŭ k ���̰�
//���� ���� ��Ÿ���� ������ l�� val +1�� �ű��


#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>
#include <set>
#include <map>

using namespace std;
typedef long long		LL;
typedef pair<int, int>	pii;

#define si(a)			scanf("%d",&(a))
#define ss(a)			scanf("%s",(a))
#define sLL(a)			scanf("%lld",&(a))
#define all(a)			(a).begin(), (a).end()
#define INF				2e9
#define MAXN			500010

int N, K;
char num[MAXN];
int check[MAXN];
vector<int> idx[12];

int main() {
	si(N); si(K);
	ss(num);
	for (int i = 0; i < N; i++) idx [num[i] - '0'].push_back(i);
	
	for (int i = 0; i < 10; i++) sort(all(idx[i]));
	
	int l = 0;
	int k = K;
	
	while (k>0){
		for (int i = 9; i >= 0; i--) {
			if (lower_bound(all(idx[i]), l) == idx[i].end()) continue;
			int val = idx[i][ lower_bound(all(idx[i]), l) - idx[i].begin() ];
			if (val > l + k) continue;

			check[val] = 1;
			k -= val - l ;
			l = val + 1;
			break;
		}
	}
	
	for (int i=0; i < N; i++) {
		if (check[i] || i >=l )printf("%c", num[i]);
	}
	printf("\n");
	return 0;
}
