#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n;
	cin >> n;

    vector<int> T(n + 1), P(n + 1), dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> T[i] >> P[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (T[j] + j <= i && T[i] + i <= n + 1)
                dp[i] = max(dp[i], dp[j] + P[i]);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;
    
	return 0;
}