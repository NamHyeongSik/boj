#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int N;
	int ans = 0;
	cin >> N;
    vector<int> A(N, 0), dp(N, 1);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    for (int i = 0; i < N; i++)
        ans = max(ans, dp[i]);
    cout << ans;
	return 0;
}