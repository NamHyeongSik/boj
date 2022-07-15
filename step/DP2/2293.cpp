#include <iostream>
#include <vector>

using namespace std;

// dp[i] == i원을 만들 수 있는 경우의 수
// dp[k] = dp[k - coin]

/* ex. 1, 2, 5원으로 10원을 만든다면
    dp[1] = 1, dp[2] = 1 ... dp[10] = 1 -> step 1
    dp[2] = dp[2] + dp[0], dp[3] = dp[3] + dp[1] ... dp[10] = dp[10] + dp[8] -> step 2
    dp[5] = dp[5] + dp[0], dp[6] = dp[6] + dp[1] ... dp[10] = dp[10] + dp[5] -> step 3
    ans = dp[10];
*/

int n, k;
int dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    vector<int> coin(n);
    for (int &c : coin)
        cin >> c;
    
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j <= k; j++)
        {
            dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[k];
    return 0;
}