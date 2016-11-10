//2209 ���� �͹̳�

//minimum diameter spanning tree 
//�ּ� ���� ���� Ʈ�� �� ����Ʈ���϶� �ּ� ������ ���ϴ� ����
//�� ������ Ǯ���ִ�
//
//n^3 Ǯ��
//n == 2�϶��� ���� ó��
//�߽� h1,h2�� �ɼ� �ִ� ��� �ֿ����Ͽ� �˻��Ѵ�.
//
//�߽����� �ƴ� ��� �������� h1 �Ǵ� h2�� �����ؾ��Ѵ�.
//-> ���������� �������ִ�
//Ʈ���� ������ �Ǵ� ���� �糡 ��尡 a,b �ϋ� 
//	a <-> h1 <-> b
//	a <-> h1 <-> h2 <-> b

// �ΰ��� ��찡 �����Ѵ�
// ������ h1 �� ������ ����� ������ A, h2�� ������ ������ ������ B��� �θ���.
// ������ h1,h2�� ���Ͽ� ���� ���տ��� ���� ū�Ͱ� �ι�°�� ū��
// �׸��� ������ ���տ��� ���� ū�Ͱ� h1 ~ h2 ������ �Ÿ� �� ���� ū��
// �� 3���� �� ���� ū ���� ���������� ������������ �����̴�.
// �츮�� �����ִ°��� �����տ��� ���� ū�Ͱ� �ι�°�� ū���̴�.
// ���� A���� ���� ū ���� ������ ��带 ������ ������ ���� B�� �̵���Ű�� �ʴ°���
// �̵� ��Ű�� �ͺ��� �̵��� ����
// �Ѿ�ٸ� ����B���� �̵���Ų ��尡 ���� ū���Ǵ� �ι�°�� ū������ ũ�ٸ� ������ �� Ŀ����
// ���� A���տ��� ���� ū���� B�������� �ϳ��� �����鼭 ������ �˻��ϸ� �ȴ�

// A������ �������ִ� �ִ밪�� �ι�° �ִ밪�� ����������
// B������ �ִ밪�� �ι�° �ִ밪�� ���� �۰� ������� A���տ��� �ִ�� �����°��� �̵��̴�


#include <stdio.h>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <string.h>
#include <set>
#include <map>
#include <functional>

using namespace std;
typedef long long		LL;
typedef pair<int, int>	pii;

#define si(a)			scanf("%d",&(a))
#define ss(a)			scanf("%s",(a))
#define sLL(a)			scanf("%lld",&(a))
#define all(a)			(a).begin(), (a).end()
#define INF				2e9
#define MAXN			501

int n;
int A[MAXN], B[MAXN];
int dist[MAXN][MAXN];
vector< pii > di[MAXN];

int ans = INF;
int st1[1000];
int st2[1000];
int vi[1000];
int main() {
	si(n);
	for (int i = 0; i < n; i++) {
		si(A[i]);	si(B[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = abs(A[i] - A[j]) + abs(B[i] - B[j]);
			di[i].push_back(pii(dist[i][j], j));
		}
	}

	for (int i = 0; i < n; i++) {
		sort(all(di[i]));
	}

	ans = INF;
	if (n == 2) {
		ans = dist[0][1];
		printf("%d\n", ans);
		return 0;
	}
	for (int a = 0; a < n; a++) {
		for (int b = a + 1; b < n; b++) {
			if (a == b) continue;

			//st �� ���� ������
			int sti1 = 0;
			int sti2 = 0;
			int mid = dist[a][b];
			int val = INF;

			int visize = 0;
			//a,b�� ����
			for (int i = 0; i < n; i++) {
				if (di[a][i].second == a || di[a][i].second == b) continue;
				vi[visize++] = i;

			}

			for (int j = visize; j >= 0; j--) {
				int i = vi[j];
				if (di[a][i].second == a || di[a][i].second == b) continue;
				int ma1 = 0, ma2 = 0, mb1 = 0, mb2 = 0, temp = 0;

				ma1 = di[a][i].first;
				if (j >= 1) ma2 = di[a][vi[j - 1]].first;

				// cal mb1,mb2
				mb1 = st1[sti1];
				mb2 = st2[sti2];

				temp = max(temp, ma1 + ma2);
				temp = max(temp, mb1 + mb2);
				temp = max(temp, ma1 + mid + mb1);
				val = min(val, temp);
				//printf("%d : %d <= %d %d : %d %d : %d\n", i, temp, ma1,ma2, mb1,mb2, mid);

				// cal st1,st2
				int idx = di[a][i].second;
				int topval = dist[b][idx];
				if (topval >= st1[sti1]) {
					sti2++;
					st2[sti2] = st1[sti1];
					sti1++;
					st1[sti1] = topval;
				}
				else if (topval >= st2[sti2]) {
					sti2++;
					st2[sti2] = topval;
				}

			}
			//printf("## %d %d  : %d \n", a + 1, b + 1, val);
			ans = min(ans, val);
		}
	}

	printf("%d\n", ans);
	return 0;
}

