
// kmp ����
#include <cstdio>
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
//1786 ã��
#define MAX_N 1000001
#define MAX_H 1000001
int pie[MAX_N];//���� �Լ�
char str[MAX_H];//ã�� ¤����
char patern[MAX_N];// ã�� ����
int h;//ã�� ¤���� ����
int n;//ã�� ���� ���� 
vector<int>ans;
void make_Pie() {
	//start =1 �� ������  
	int start = 1, matched = 0;
	while (start + matched < n) {
		if (patern[start + matched] == patern[matched]) {
			matched += 1;
			pie[start + matched - 1] = matched;
		}
		else {
			if (matched == 0)start += 1;
			else {
				start += matched - pie[matched - 1];
				matched = pie[matched - 1];
			}
		}
	}
}

void kmp() {
	make_Pie();
	int matched_count = 0;
	int start = 0, matched = 0;
	while (start <= h - n) {
		//��Ī �Ǿ���
		if (str[start + matched] == patern[matched]
			&& matched < n) {
			matched += 1;
			if (matched == n)
				ans.push_back(start);
		}
		//�� ��...
		else {
			if (matched == 0) start++;
			else {
				start += matched - pie[matched - 1];
				matched = pie[matched - 1];
			}
		}
	}

	return;
}

int main() {
	gets_s(str);
	gets_s(patern);
	n = strlen(patern);
	h = strlen(str);

	kmp();
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i] + 1);
	}


	return 0;
}