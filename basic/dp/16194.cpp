#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> dp(N + 1, 1000000);
    vector<int> P(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> P[i];
    dp[0] = 0;
    dp[1] = P[1];
    for (int i = 2; i <= N; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = min(dp[i - j] + P[j], dp[i]);
    cout << dp[N];
}