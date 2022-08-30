#include <iostream>
using namespace std;

// DFS -> 당연히 시간초과
// 메모이제이션으로 시간초과 해결

#define INF 987654321

int N;
int dp[1000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    dp[2] = dp[3] = 1;
    for (int i = 4; i <= N; i++)
        dp[i] = INF;

    for (int i = 4; i <= N; i++)
    {
        if (i % 3 == 0)
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        if (i % 2 == 0)
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }

    cout << dp[N] << '\n';

    while (1)
    {
        cout << N << " ";
        if (N == 1) break;
        if (N % 3 == 0 && (dp[N / 3] + 1) == dp[N])
            N /= 3;
        else if (N % 2 == 0 && (dp[N / 2] + 1) == dp[N])
            N /= 2;
        else
            N--;
    }
}