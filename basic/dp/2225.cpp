#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n, k;
	cin >> n >> k;

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
    for (int i = 1; i <= k; i++)
        dp[1][i] = i;
    for (int i = 2; i <= k; i++)
    {
        dp[i][1] = 1;
        for (int j = 2; j <= k; j++)
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
    }
    cout << dp[n][k];
	return 0;
}