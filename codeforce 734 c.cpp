////���� �������� ���� ���ַ� �����Ѵ�
////�������¼��� ������ 4���� �� ������ ���������� ���� �ε����� ���� ��ǥ�� ������ų������
////���� � ���� ������ ���� �̷� �����߿� �ְų� ���ų� �ϹǷ�
////���� ���������ִ� ���⿡���� ���������� ���� ��� ������ �����ؼ� �������°��� Ȯ�� �Ҽ�����
////���������� �ð��� �̸� ����س��´�...
//
//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<vector>
//#include<algorithm>
//#include<functional>
//#include<iostream>
//#include<cmath>
//#include<string>
//#include<cctype>
//#include<stack>
//#include<queue>
//#include<set>
//#include<sstream>
//#include<map>
//using namespace std;
//
//#define FORD(i,k,n) for(int i=n;i>=k;i--)
//#define FOR(i,k,n) for(int i=k;i<=n;i++)
//#define CLR(a,b) memset(a,b,sizeof(a));
//#define INF 0x3f3f3f3f
//#define LLINF 0x3f3f3f3f3f3f3f3f
//#define ll long long
//#define LL long long
//
//#define maxn (100050)
//
//int n, m, k;
//int d[4][2] = { { 1,1 },{ -1,1 },{ -1,-1 },{ 1,-1 } };
//struct node {
//	int x, y;
//	ll tm;
//	bool operator<(const node&rhs)const {
//		if (x != rhs.x)	return x < rhs.x;
//		else if (y != rhs.y) return y < rhs.y;
//		else return tm < rhs.tm;
//	}
//	node() {}
//	node(int x, int y, int tm) :x(x), y(y), tm(tm) { }
//
//}p[maxn];
//
//int nume;
//node mp[4][maxn * 20];
//void read() {
//	cin >> n >> m >> k;
//	FOR(i, 1, k) {
//		cin >> p[i].x >> p[i].y;
//	}
//}
//
////���� ��ġ���� ���� �ε��������� ����������
//void change(int &x, int &y, int &dir, int& dd) {
//	int nx, ny;
//	if (dir == 0) {
//		dd = min(n - x, m - y);
//		nx = dd + x, ny = dd + y;
//		if (nx == n&&ny == m);
//		else if (nx == n) dir = 1;
//		else dir = 3;
//	}
//	else if (dir == 1) {
//		dd = min(x, m - y);
//		nx = x - dd, ny = dd + y;
//		if (nx == 0 && ny == m);
//		else if (nx == 0) dir = 0;
//		else dir = 2;
//	}
//	else if (dir == 2) {
//		dd = min(x, y);
//		nx = x - dd, ny = y - dd;
//		if (nx == 0 && ny == 0);
//		else if (nx == 0) dir = 3;
//		else dir = 1;
//	}
//	else {
//		dd = min(n - x, y);
//		nx = x + dd, ny = y - dd;
//		if (nx == n&&ny == 0);
//		else if (nx == n) dir = 2;
//		else dir = 0;
//	}
//	x = nx; y = ny;
//}
//
//void preprocess() {
//	int x = 0, y = 0, dir = 0;
//	ll sum = 0;
//	int cnt = 0;
//	while (cnt <= 4 * (m + n)) {
//		node tmp(x, y, sum);
//		int dd = 0;
//		mp[dir][nume++] = tmp;
//		change(x, y, dir, dd);
//		sum += dd;
//		cnt++;
//		// ptl2;
//	}
//	FOR(j, 0, 3) sort(mp[j], mp[j] + nume);
//}
//
//void solve() {
//	FOR(i, 1, k) {
//		ll ans = LLINF;
//		FOR(j, 0, 3) {
//			int x = p[i].x, y = p[i].y, dir = j, dd = 0;
//			change(x, y, dir, dd);
//			node tmp(x, y, 0);
//
//			if (j == 0) dir = 2;
//			else if (j == 2) dir = 0;
//			else if (j == 1) dir = 3;
//			else dir = 1;
//
//			FOR(t, 0, 3) {
//				int p = lower_bound(mp[t], mp[t] + nume, tmp) - mp[t];
//				if ((p >= 0 && p < nume) &&
//					(mp[t][p].x == x && mp[t][p].y == y)) {
//					ans = min(ans, mp[t][p].tm + dd);
//				}
//			}
//		}
//		printf("%I64d\n", ans == LLINF ? -1 : ans);
//	}
//}
//
//int main() {
//	read();
//	preprocess();
//	solve();
//	return 0;
//}