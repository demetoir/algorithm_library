// ���ϲ��� �׶��� ��ĵ

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
#define all(a) (a).begin(),(a).end()
//////////////////////////////////////////////////////////////////////////////////

//1708 ���� ����

#define MAX_N 100001

struct vector2 {
	LL x, y;
	vector2() {  };
	vector2(LL x_, LL y_) : x(x_), y(y_) {}

	vector2 operator - (const vector2 other)const {
		return vector2(x - other.x, y - other.y);
	}
	LL cross(const vector2 & other) {
		return x*other.y - y*other.x;
	}
};
vector2 minp(INF, INF);
LL ccw(vector2 a, vector2 b) {
	LL ccw = a.cross(b);
	return ccw;
}
bool cmp(const vector2 a, const vector2 b) {
	vector2 A = a - minp;
	vector2 B = b - minp;
	LL val = ccw(A, B);
	if (val > 0) return true;
	else if (val <= 0) return false;

	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
vector2 points[MAX_N];
int n;

int scan() {
	//���� ���� ���� ã�� �Ǿ����� ����
	int minindex;
	for (int i = 0; i < n; i++) {
		if (minp.x > points[i].x ||
			minp.x == points[i].x && minp.y > points[i].y) {
			minp.x = points[i].x;
			minp.y = points[i].y;
			minindex = i;
		}
	}
	points[minindex] = points[0];
	points[0] = minp;

	// ������ ������ �����������κ����� ���������� ��Ʈ�Ѵ�
	sort(points + 1, points + n, cmp);

	//�������κ��� �ݽð� ������ �������� ���� ����
	stack <vector2> st;
	st.push(points[0]);
	st.push(points[1]);
	for (int i = 2; i < n; i++) {
		vector2 b = st.top(); st.pop();
		vector2 a = st.top();

		while (1) {
			LL val = ccw(points[i] - a, points[i] - b);
			if (val > 0) {
				st.push(b);
				st.push(points[i]);
				break;
			}
			else {
				if (st.size() == 1) {
					st.push(points[i]);
					break;
				}
				else {
					b = st.top(); st.pop();
					a = st.top();
				}
			}
		}
	}
	return st.size();
}
int main() {
	int test = 1;
	int ans = 0;
	//si(test);
	for (; test > 0; test--) {
		si(n);
		for (int i = 0, a, b; i < n; i++) {
			sLL(points[i].x); sLL(points[i].y);
		}
		ans = scan();

		printf("%d\n", ans);
	}
	return 0;
}