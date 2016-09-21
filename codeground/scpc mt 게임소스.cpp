#include <cstdio>
#include <iostream>
#define forin(i,n) for(int i = 0 ;i<n;i++)
#define foriston(i,s,n) for (int i = s ; i< n ; i++)
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a)(((a) < (0))?-(a):(a))
using namespace std;
int dp[12][123][123];
int M, N,K;
int map[123][123];

int f(int i, int j, int k) {
	int  ret;
	ret = dp[i][j][k];
	if (ret != -1) {
		return ret;
	}
	if (i == 0) {
		if (map[i][j]< 0) {
			int map;
		}
		else {

		}
		return ret;
	}
	if (j == 0) {

	}
}

void init() {
	int i, j, k;
	forin(k, 12) {
		forin(i, 123) {
			forin(j, 123) {
				dp[k][i][j] = 123456789;
			}
		}
	}
	forin (i, 123) {
		forin(j, 123) {
			map[i][j] = 0;
		}
	}
	return;
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		init();
		scanf("%d %d %d", &M, &N, &K);
		forin(i, N+1) {
			forin(j, M+1) {
				scanf("%d", &map[i][j]);
			}
		}

		dp[0][0][0] = 0;
		forin(i, N + 1) {
			forin(j, M + 1) {
				if (i > 0) {
					dp[0][i][j] = MIN(dp[0][i][j],
						dp[0][i - 1][j]+ ABS(ABS(map[i-1][j])-ABS(map[i][j])));
				}
				if (j > 0) {
					dp[0][i][j] = MIN(dp[0][i][j],
						dp[0][i][j-1] + ABS(ABS(map[i][j - 1]) - ABS(map[i][j])));
				}					
			}
		} 

		foriston(k, 1, 11) {
			forin(i,N+1){
				forin(j, M + 1) {
					int minus = 0;
					if (map[i][j] < 0) { minus = -1; }
					if (i > 0) {
						dp[k][i][j] = MIN(dp[k][i][j],
							dp[k+minus][i - 1][j] + ABS(ABS(map[i - 1][j]) - ABS(map[i][j])));
					}
					if (j > 0) {
						dp[k][i][j] = MIN(dp[k][i][j],
							dp[k + minus][i][j - 1] + ABS(ABS(map[i][j - 1]) - ABS(map[i][j])));
					}
				}
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		int ans = 123456789; 

		foriston(i,K, 11) {
			//printf("%d\n", dp[i][N][M]);
			ans = MIN(dp[i][N][M], ans);
		}
		printf("%d\n", ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}