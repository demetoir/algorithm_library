//1787 ���ڿ� �ֱ� ����

//kmp 
//kmp ���� �Լ� ����� �� ���������� ���� ���� ���� �� ����κ��� �������
//���� �� ����κ��� ���� �� ��Ī�� �����̴�
//�̰� ������ ��� ������ ���鼭 ���� ª�� ����κ��� ���̸� ���ϸ� �ȴ�
//�շ� ������ Ʋ�ȴ�....


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>

typedef long long ll;
#define pii pair<int, int>
#define si(a) scanf("%d", &(a))
#define sc(a) scanf("%c", &(a))
#define ss(a) scanf("%s",a)
#define sll(a) scanf("%lld", &(a))
#define pi(a) printf("%d\n", (a))
#define pc(a) printf("%c",a);
#define ENDL printf("\n");
#define pll(a) printf("%lld\n", (a))

#define INF 2e9
#define all(a) (a).begin(),(a).end()
#define MAX_N 1000001

using namespace std;

vector < ll > make_pie(string &str) {
	ll n = str.size();
	vector <ll> pie(n);

	ll start = 1;
	ll match = 0;
	while (start + match < n) {
		if (str[start + match] == str[match]) {
			match++;
			pie[start + match - 1] = match;
		}
		else {
			if (match == 0) start++;
			else {
				start += match - pie[match - 1];
				match = pie[match - 1];
			}
		}
	}
	return pie;
}

char buff[MAX_N];
ll n;
int main() {
	si(n);
	ss(buff);

	string str(buff);
	vector<ll>pie;
	pie = make_pie(str);
	ll ans = 0;

	for (ll i = 0; i < n; i++) {
		if (pie[i] == 0) continue;

		while (1) {
			if (pie[pie[i] - 1] == 0)break;
			pie[i] = pie[pie[i] - 1];
		}
		if(i + 1 - pie[i] >= pie[i])
			ans += i + 1 - pie[i];
	}
	printf("%lld\n",ans);
	return 0;
}
