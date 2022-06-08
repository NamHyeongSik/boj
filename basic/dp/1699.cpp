#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n;
	cin >> n;

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
    
	return 0;
}