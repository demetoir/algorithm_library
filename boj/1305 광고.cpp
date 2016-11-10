//1305 ����
//
//kmp 
//�ݺ��Ǵ°��� ���� ���� ���� �� ã�� ����
//���� �ݺ��Ǳ⶧���� ó������ ���� ��ŭ �ݺ��ϰ� ���� ���� �պκ� �� ���� �ȴ�
//ó������ sa �� ������
//�ٵ� Ʋ��
//kmp�� �ٲپ ���� kmp ���� pie�� ����� �κ��� ���̵ȴ�
//pie[i]== i���� ���� ��Ī������ ���� �� ���� ����, ���λ�� ���̻� ������ ���� �� ����
//���� n - pie[n-1] ��ü ���̿��� ���λ�� ���̻� �� ���� ����� ���� ����� ������ ���̵�
//sa�� �Ƹ� �ٷ� �տ��ִ°Ÿ��ؼ� Ʋ���ϴ� ��Ȯ���� ��

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>

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

#define INF 2e9
#define all(a) (a).begin(),(a).end()
#define MAX_N 1000001

using namespace std;

vector<int> make_pie(string &str) {
	int n = str.size();
	vector <int> pie(n);

	int start = 1;
	int match = 0;
	while (start + match < n) {
		if (str[start + match] == str[match]) {
			match++;
			pie[start + match - 1] = match;
		}
		else {
			if (match == 0) start++;
			else {
				start += match - pie[match - 1];
				match = pie[match - 1];
			}
		}
	}
	return pie;

}

char buff[MAX_N];
int n;
int main() {
	si(n);
	ss(buff);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	string str(buff);
	vector<int>pie;
	pie = make_pie(str);
	int ans = n - pie[n - 1];

	printf("%d\n", ans);
	return 0;
}
