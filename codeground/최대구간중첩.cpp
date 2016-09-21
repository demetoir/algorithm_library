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

vector<char> v;
priority_queue <int> PQ;
queue <int>  Q;
map<int, string> istrmap;
int cmp(const void* a, const void* b) {
	return a > b;
}
struct myPair {
	myPair(int _a, int _b) {
		a = _a;
		b = _b;
	}
	int a, b;
};
bool operator < (const myPair A, const myPair B) {
	if (A.a == B.a) {
		return A.b < B.b;
	}
	return !(A.a < B.a);
}
int a[12] = { 4,3,2,1,0, };

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int TC;
	scanf("%d", &TC);	// cin ��� ����
	for (int test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		vector <myPair> v;
		int a, b;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back(myPair(a, b));
		}
		sort(v.begin(), v.end());
		//printf("\n");
		//for (int i= 0; i < n; i++) {
		//	printf("%d %d\n", v[i].a, v[i].b);
		//}
		vector <int> lis;
		lis.push_back(v[0].b);

		for (int i = 1; i < n; i++) {
			int val = v[i].b;
			if (lis.back() <= val) {
				lis.push_back(val);
			}
			else {
				vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), val);
				*it = val;
			}
		}
		//printf("\n");
		//for (int i = 0; i < lis.size(); i++) {
		//	printf("%d ", lis[i]);
		//}
		//printf("\n");
		//printf("\n");

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", lis.size());
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}