#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size())
        swap(a, b);
    int N = a.size();
    int M = b.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    cout << dp[N][M] << endl;
    if (dp[N][M] == 0)
        return 0;
    int i = N - 1, j = M - 1;
    string ans;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == b[j])
        {
            ans = a[i] + ans;
            i--;
            j--;
        }
        else
        {
            if (dp[i + 1][j] > dp[i][j + 1])
                j--;
            else
                i--;
        }
    }
    cout << ans;
}