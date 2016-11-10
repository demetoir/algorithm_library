//5882 ���� �κ� ���ڿ�
//dp�ε� Ǯ�������� ũ�Ⱑ ũ�ٸ� ���̻� �迭�� Ǯ����Ѵ�
//�ι��ڿ��� ��� ������ ���ڿ�(�ι��ڿ����� ������ �ʴ� ����)�� �߰��Ͽ� ����
//ū���ڿ��� sa ,lcp�� ���Ѵ�
//sa �� ������ ���̻��� ����κ��� ���� ū ���·� ���� �ǹǷ�
//��ģ ���ڿ��� sa �� ���̻�� ���� ���� �κ��� ���� ũ�� ���ĵȴ�
//�̶� ���� ���� ���ڿ� ���̿����� lcs�� ���ü������Ƿ� ������ ���ڿ��� 
//�����̻簡 � ���ڿ� ���ϴ� �������� Ȯ���Ҽ��ִ�
//���� �پ� ���� ���� ���� �ٸ� ���ڿ��� ���̻糢���� ����κ��� �����ϴ� �͵麸�� 
//���� �����Ƿ� ������ ���̻� �߿��� ���� �ٸ� ���ڿ� �� ���ϴ� ����� lcs �� ���̴�
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

#define ll long long
#define pii pair<int, int>
#define si(a) scanf("%d", &(a))
#define sc(a) scanf("%c", &(a))
#define ss(a) scanf("%s",a)
#define sll(a) scanf("%lld", &(a))
#define pi(a) printf("%d\n", (a))
#define pc(a) printf("%c",a);
#define ENDL printf("\n");
#define pll(a) printf("%lld\n", (a))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define FOR(a,b,c) for((a)=(b);(a)<=(c);(a)++)
#define _FOR(a,b,c) for((a)=(b);(a)<(c);(a)++)
#define INF 2e9
#define all(a) (a).begin(),(a).end()
#define MAX_N 100000

using namespace std;

struct CMP {
	const vector<int> &g;
	int k;
	CMP(vector<int> &g ,int k): g(g),k(k){}
	bool operator() (int a, int b) {
		if (g[a] != g[b])return g[a] < g[b];
		return g[a+k] < g[b+k];
	}
};
vector<int> make_sa(string &str) {
	int size = str.size();
	vector<int> perm(size);
	vector<int> g(size+1);
	int k = 1;
	for (int i = 0; i < size; i++) {
		g[i] = str[i];
		perm[i] = i;
	}
	g[size] = -1;
	

	while (k < size) {
		CMP cmp(g, k);
		sort(all(perm), cmp);

		k *= 2;
		if (k >= size)
			break;
	
		vector<int>newg(size +1);
		newg[size] = -1;
		newg[perm[0]] = 0;
		for (int i = 1; i < size; i++) {
			if (cmp(perm[i - 1], perm[i]))
				newg[perm[i]] = newg[perm[i - 1]] + 1;
			else
				newg[perm[i]] = newg[perm[i - 1]] ;
		}
		g = newg;
	}
	return perm;
}

vector<int> make_lcp(string &str, vector<int>& sa) {
	int size = str.size();
	vector<int> rev(size,0);
	vector<int> lcp(size,0);

	for (int i = 0; i < size; i++)
		rev[sa[i]] = i;
	int k = 0;
	for (int i = 1; i < size; i++) {
		if (rev[i] == 0) {
			k = 0; 	continue;
		}

		int j = sa[rev[i] - 1];
		while (i + k < size && j + k < size && str[i+k] == str[j+k])k++;
		lcp[rev[i]] = k;
		k = max(k - 1, 0);
	}
	return lcp;
}
char buff[MAX_N];
int main() {
	ss(buff);
	string str1(buff);
	ss(buff);
	string str2(buff);
	string str;
	int mid = str1.size();
	str = str1 +'#'+ str2;
	vector<int>sa,lcp;

	sa = make_sa(str);
	lcp = make_lcp(str, sa);
	int size = str.size();
	/*
	for (int i = 0; i < size; i++) {		
		printf("%d ", lcp[i]);
		for (int j = sa[i]; j < size; j++)
			pc(str[j]);
		ENDL;
	}*/

	int ans = 0;
	for (int i = 1; i < size; i++) {
		if (sa[i] > mid && sa[i - 1] < mid)
			ans = max(lcp[i], ans);
		if (sa[i] <mid && sa[i - 1]>mid)
			ans = max(lcp[i], ans);
	}

	printf("%d\n", ans);
	
	return 0;
}
