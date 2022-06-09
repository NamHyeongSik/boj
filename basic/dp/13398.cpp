#include <iostream>
#include <vector>

using namespace std;

//ans 초기값 뻘짓...
int main(void){
	int n;
	int ans;
	cin >> n;
    int v[100000] = {0, };
    int dp[100000][2] = {0, };
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ans = dp[0][0] = v[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + v[i], v[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
	return 0;
}