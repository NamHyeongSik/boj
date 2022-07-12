#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int dp[501][501];// x ~ y까지의 합
int sum[501]; //누적합 배열

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;
        for (int i = 1; i <= K; i++)
        {
            int tmp;
            cin >> tmp;
            sum[i] = sum[i - 1] + tmp;
        }
        
        for (int i = 1; i <= K; i++)
        {
            for (int x = 1; x <= K - i; x++)
            {
                int y = x + i;
                dp[x][y] = INT_MAX;
                for (int mid = x; mid < y; mid++)
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
            }
        }
        cout << dp[1][K] << "\n";
    }
    
}