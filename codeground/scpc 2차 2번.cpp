#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

#define MAX(a,b) (((a)>(b))? (a):(b))
#define MIN(a,b) (((a)<(b))? (a):(b))
#define ABS(a) (((a)<(0))? (-(a)):(a))
#define ll long long
#define si(a) scanf("%d",&a)

using namespace std;
int n, m, k;
int memo[10001][3];
int p[10001], q[10001];
void init() {
	for (int i = 0; i < 10001; i++) {
		memo[i][0] = -1;
		memo[i][1] = -1;
		memo[i][2] = -1;
		p[i] = 0;
		q[i] = 0;
	}
}
int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		init();
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		si(n);
		for (int i = 0; i < n; i++) {
			int a;
			si(a);
			p[i + 1]=a; 
		}
		for (int i = 0; i < n; i++) {
			int a;
			si(a);
			q[i + 1] = a;
		}

		memo[0][0] = 0;
		memo[0][1] = 0;
		memo[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			//x
			memo[i][0] = MAX(memo[i][0], memo[i - 1][0]);
			memo[i][0] = MAX(memo[i][0], memo[i - 1][1]);
			memo[i][0] = MAX(memo[i][0], memo[i - 1][2]);


			//p
			memo[i][1] = MAX(memo[i][1], memo[i - 1][0]);
			memo[i][1] = MAX(memo[i][1], memo[i - 1][1]+p[i]);
			memo[i][1] = MAX(memo[i][1], memo[i - 1][2]+p[i]);

			//q
			if (i - 2 <0) {
				memo[i][2] = MAX(memo[i][2], q[i]);
			}
			else {
				memo[i][2] = MAX(memo[i][2], memo[i - 2][0]);
				memo[i][2] = MAX(memo[i][2], memo[i - 2][1] + q[i]);
				memo[i][2] = MAX(memo[i][2], memo[i - 2][2] + q[i]);

			}

		}
		int ans = 0;
		ans = MAX(ans, memo[n][0]);
		ans = MAX(ans, memo[n][1]);
		ans = MAX(ans, memo[n][2]);



		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}