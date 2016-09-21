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
int n, m, k;
struct mp {
	mp(int x, int y) {
		a = x;
		b = y;
	}
	int a, b;
};
vector<mp> red, blue;

int main(int argc, char** argv) {

	setbuf(stdout, NULL);


	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		si(n); 
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		int a, b,c;
		red.clear();
		blue.clear();
		for (int i = 0; i < n; i++) {
			si(a); si(b); si(c);
			
			if (c == 0) {
				red.push_back(mp(a, b));
			}
			else {
				blue.push_back(mp(a, b));
			}			
		}


		int ans = 0;

		for (int i = 0; i < red.size(); i++) {
			int x, y; 
			x = red[i].a;
			y = red[i].b;
			int val = 0;
			for (int j = 0; j < red.size(); j++) {
				int a = red[j].a, b = red[j].b;
				if ((a >= x && b >= y) ||(a <= x && b <= y)) 
					val += 1;
				
			}
			for (int j = 0; j < blue.size(); j++) {
				int a = blue[j].a, b = blue[j].b;
				if ((a <= x && b >= y) || (a <= x && b >= y)) 
					val += 1;				
			}
			ans = MAX(ans, val);
		}

		for (int i = 0; i < blue.size(); i++) {
			int x = blue[i].a, y = blue[i].b;
			int val = 0;
			for (int j = 0; j < red.size(); j++) {
				int a = red[j].a, b = red[j].b;
				if ((a >= x && b >= y) || (a <= x && b <= y)) 
					val += 1;
				
			}
			for (int j = 0; j < blue.size(); j++) {
				int a = blue[j].a, b = blue[j].b;
				if ((a <= x && b >= y) || (a <= x && b >= y)) 
					val += 1;
				
			}
			ans = MAX(ans, val);
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}