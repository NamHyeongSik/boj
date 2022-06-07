#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    vector<int> dp(x + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= x; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0 && dp[i] > dp[i / 2])
            dp[i] = dp[i / 2] + 1;
        if (i % 3 == 0 && dp[i] > dp[i / 3])
            dp[i] = dp[i / 3] + 1;
    }
    cout << dp[x] << endl;
}