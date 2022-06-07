#include <iostream>

using namespace std;

int main(void){
	int N;
	int ans = 0;
	cin >> N;
    long long dp[91][2] = {0, };
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[N][0] + dp[N][1];
	return 0;
}