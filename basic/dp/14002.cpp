#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int N;
	int ans = 1;
	cin >> N;
    vector<int> A(N, 0), dp(N, 1);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int idx = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (ans < dp[i])
        {
            ans = dp[i];
            idx = i;
        }
        // ans = max(ans, dp[i]);
    }
    
    cout << ans << "\n";
    vector<int> arr(ans);
    for (int i = idx; i >= 0; i--)
    {
        if (dp[i] == ans)
        {
            ans--;
            arr[ans] = A[i];
        }
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
	return 0;
}