#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int len = 1;
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        len = max(len, dp[i]);
    }
    cout << len << "\n";
    vector<int> ans(len);
    for (int i = N - 1; i >= 0; i--)
    {
        if (dp[i] == len)
        {
            len--;
            ans[len] = arr[i];
        }
    }
    for (int n : ans)
        cout << n << " ";
}