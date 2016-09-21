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

vector<int> iv;
vector<int>::iterator iit;
vector<double> dv;
priority_queue <int> PQ;
queue <int>  Q;
map<int, string> istrmap;
map <long long, int>iimap;
struct mp {
	int a, b;
};
#define ABS(a)(((a) < (0))?-(a):(a))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


int n, m, K, L;
int G[101][101];

int dist[1000001];
///////////////1000000000
#define MAXDIS 1234567890;
vector <int > start;
long long ans = 0;
int dir[1000001];
int vlevel[101];
int vdelete[101];
int number;
int vl[101];
int G2[101][101];
void init() {

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			G[i][j] = 0;
		}
		vlevel[i] = 0;
		vdelete[i] = 0;
	}
	ans = 0;
}
//������ ������ ���� ������
void f1() {
	while (1) {
		int flag = false;
		for (int i = 1; i < n + 1; i++) {
			if (vlevel[i] < K&& vlevel[i] >0) {
				flag = true;
				vlevel[i] = 0;
				for (int j = 1; j < n + 1; j++) {
					if (G[i][j] == 1) {
						vlevel[j] -= 1;
					}
					G[i][j] = 0;
					G[j][i] = 0;
				}
			}
		}
		if (flag == false) { break; }
	}
	for (int i = 1; i < n + 1; i++) {
		if (vlevel[i] == 0) {
			//printf("## %d\n", i);
			ans += i;
			vdelete[i] = 1; 
			vlevel[i] = -1;
		}
	}
}

int maxlevel() {
	int ret = 0;
	for (int i = 1; i < n + 1; i++) {
		ret = MAX(ret, vlevel[i]);
	}
	return ret;
}

void f2() {

	
	while (number != 0) {
		//�ּ� ������ ã��
		if (maxlevel() <= number - 1 - L) {
			break;
		}
		int index =0;
		int val = -1;
	
		//���� ũ�� �������� ����
		for (int i = 1; i < n + 1; i++) {
			if (val < vlevel[i]) {
				index = i;
				val = vlevel[i];
			}
		}
		//�׳��� �����Ѵ�
		vlevel[index] = -1;
		for (int i = 1; i < n + 1; i++) {
			if (G[index][i] == 1) {
				G[i][index] = 0;
				vlevel[i] -= 1;
				G[index][i] = 0;
			}
		}
		ans += index;
		number -= 1;
		//printf("## %d\n", index);

	}
}
int main(int argc, char** argv) {
	//setbuf(stdout, NULL);

	int TC;
	scanf("%d", &TC);	// cin ��� ����
	for (int test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		scanf("%d %d ", &K, &L);
		scanf("%d %d", &n, &m);

		init();
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			G[a][b] = 1;
			G[b][a] = 1;
			vlevel[a] += 1;
			vlevel[b] += 1;

		}

		while (1) {
			f1();
			//printf("\n");
			number = 0;
			for (int i = 1; i < n + 1; i++) {
				if (vlevel[i] >= 0)
					number += 1;
			}
			int oldval = number;

			f2();
			//printf("\n");
			if (oldval == number)
				break;
		}

		
		// �� �κп��� ������ ����Ͻʽÿ�.


		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%lld\n", ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}