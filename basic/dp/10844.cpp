#include <iostream>

using namespace std;
int num[10] = { 0, };
int dp[10] = { 1, 1, 2, 2, 2, 2, 2, 2, 2, 1};

int main(void){
	int N;
	int ans = 0;
	cin >> N;
	if (N == 1) {
		cout << 9 << "\n";
	}
	else {
		for (int i = 2; i < N; i++) {
			for (int j = 0; j <= 9; j++) {
				if (j == 0)
					num[j] = dp[j + 1];
				else if (j == 9)
					num[j] = dp[j - 1];
				else
					num[j] = (dp[j - 1] + dp[j + 1]) % 1000000000;
			}
			for (int j = 0; j <= 9; j++)
				dp[j] = num[j];
		}
		for (int i = 0; i <= 9; i++) {
			ans = (ans + dp[i]) % 1000000000;
		}
		cout << ans % 1000000000;
	}
	return 0;
}