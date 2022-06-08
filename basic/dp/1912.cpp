#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n;
	int ans = -1001;
	cin >> n;
    vector<int> v(n, 0), dp(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    dp[0] = v[0];
    for (int i = 1; i < n; i++)
        dp[i] = max(dp[i - 1] + v[i], v[i]);
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
	return 0;
}