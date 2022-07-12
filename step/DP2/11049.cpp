#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> row(N + 1), col(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> row[i] >> col[i];

    for (int i = 1; i <= N; i++)
    {
        for (int l = 1; l <= N - i; l++)
        {
            int r = l + i;
            dp[l][r] = INT32_MAX;
            for (int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + row[l] * col[k] * col[r]);
        }
    }
    cout << dp[1][N];
}