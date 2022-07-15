#include <iostream>
#include <vector>

using namespace std;

//매우 어려움... 다시 풀어보도록!

int N, M;
int A[101], C[101];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
        sum += C[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = sum; j >= C[i]; j--)
            dp[j] = max(dp[j], dp[j - C[i]] + A[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < sum; i++)
        if (dp[i] < M)
            ans++;

    cout << ans;
    
    return 0;
}