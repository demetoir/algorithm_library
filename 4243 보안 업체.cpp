//// 4243 ���� ��ü
////
////
////dp �͸�����, ���̵��, ������?? ���
////�ϴ� �͸����� dp�̴�
////���� ������ �۸� �п� 
////
////��ȭ���� ���ϴ� �Ŵ� ��� �������̱� ������ �Ź� ���� ���� ���� ���ϴ°Ű� �������
////�ܼ��� �� �ܰ迡�� �ּ� �����ð��̳� �ּ� ���� �ð���
////������ �ܰ踸 �츮�� ���Ϸ��� �������� ������ �߰� �ܰ��� ���� ���� �߰� �ܰ��� �������� �ƴ� dp �̴�
////�� �ܰ迡�� ���ϴ°Ű�  �״ܰ������ �������� �� �ƴ϶� ��ü ���������� ������ �����ִ� ���� �� �����̴�
////���� ���̽��� ����
////1
////1 2
////1 2 2 1 4
////1 2 2 1 4 7
////�̷������� �Ŵܰ���� �ɸ��� �ð��� �̷��� �ɸ���
////��������
////1 + 1 2 + 1 2 2 1 4 + 1 2 2 1 4 7
////�̷��� �Ǵµ�
////���� 
////1 �� 4��
////2 �� 3��
////2 1 4 �� 2��
////7 �� 1��
////�̷��� �Ǳ⶧���� 
////�Ź� ���ϴ� ���� = �Ź� �߰� �Ǵ� �� * �ݺ��Ǵ� Ƚ��
////���� 
////dleft[i][j] = min( dright[i+1][j] + ���� , dleft[i+1][j] + ����)
////
////dright[i][j] = min( dright[i][j-1] + ���� , dleft[i][j-1] + ���� )
//
//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <math.h>
//#include <functional>
//#include <utility>
//#include <limits.h>
//
//typedef long long LL;
//using namespace std;
//
//#define pii pair<int, int>
//#define PLL pair<LL,LL>
//#define si(a) scanf("%d", &(a))
//#define sc(a) scanf("%c", &(a))
//#define ss(a) scanf("%s",a)
//#define sll(a) scanf("%lld", &(a))
//#define pi(a) printf("%d\n", (a))
//#define pc(a) printf("%c",a);
//#define ENDL printf("\n");
//#define pll(a) printf("%lld\n", (a))
//#define INF 2e9
//#define LLINF 1e17 
//#define all(a) (a).begin(),(a).end()
//
//#define MAX_N 101
//
//LL t[MAX_N];
//LL n, a;
//LL ans;
//
////������
//LL dpl[MAX_N][MAX_N];
//LL dpr[MAX_N][MAX_N];
//
//int main() {
//	int test = 0;
//	for (si(test); test > 0; test--) {
//		sll(n);
//		sll(a);
//		for (int i = 1; i < n; i++) {
//			sll(t[i]);
//		}
//		for (int i = 0; i <= 100; i++) {
//			for (int j = 0; j <= 100; j++) {
//				dpl[i][j] = LLINF;
//				dpr[i][j] = LLINF;
//			}
//		}
//
//		dpl[a][a] =0;
//		dpr[a][a] = 0;
//
//		for (int len = 1; len < n ; len++) {
//			for (int i = 1; i <= n; i++) {
//				int j = i + len;
//				if (j > n) continue;
//
//				LL sum = 0,l,r;
//				for (int k = i; k < j; k++) sum += t[k];
//
//				//dpl
//				l = dpl[i + 1][j] + t[i]*(n-len );
//				r = dpr[i + 1][j] + sum *(n - len );
//				dpl[i][j]= min(l,r);
//				//dpr
//				l = dpl[i][j-1] + sum*(n-len);
//				r = dpr[i][j-1]+ t[j-1]*(n - len);
//				dpr[i][j]= min(l,r);
//				//printf("##L %lld %lld %lld \n", i, j, dpl[i][j]);
//				//printf("##R %lld %lld %lld \n", i, j, dpr[i][j]);
//			}
//		}
//		
//		ans = min(dpl[1][n],dpr[1][n]);	
//		pll(ans);
//	}
//	return 0;
//}
