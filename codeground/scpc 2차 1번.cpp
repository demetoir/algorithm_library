#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <string.h>
using namespace std;

#define MAX(a,b) (((a)>(b))? (a):(b))
#define MIN(a,b) (((a)<(b))? (a):(b))
#define ABS(a) (((a)<(0))? (-(a)):(a))
#define ll long long
#define si(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)

using namespace std;
int n, m,k;
struct rect {
	ll a, b, x, y;
	rect(ll a1,ll b1, ll a2,ll b2){
		a = a1;
		b = b1;
		x = a2;
		y = b2;
	}
};
#define MAX_N 5001
#define MULVAL 10000000
struct mp {
	ll a,b;
	int index;
	mp(ll x,ll y,int i){
		a = x;
		b = y;
		index = i;
	}

};
bool operator< (const mp A, const mp B) {
	if (A.a == B.a) {
		return A.b < B.b;
	}
	return !(A.a < B.a);
}

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);


	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		si(n); si(m); si(k);
		//vector<rect> v;
		vector<mp> v;
		for (int i = 0; i < k; i++) {
			int a, b, c, d;
			sll(a); sll(b); sll(c); sll(d);
			v.push_back(mp(a*MULVAL + b , c*MULVAL +d,i+1));
			
		}
		sort(v.begin(), v.end());


		vector <ll> lis;
		lis.push_back(v[0].b);

		for (int i = 1; i < k; i++) {
			int val = v[i].b;
			if (lis.back() <= val ) {
				lis.push_back(val);
			}
			else {
				vector<ll>::iterator it = lower_bound(lis.begin(), lis.end(), val);
				*it = val;
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.

		printf("Case #%d\n", test_case);
		printf("%d\n", lis.size());
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}