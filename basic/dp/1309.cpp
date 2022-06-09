#include <iostream>
#include <vector>

using namespace std;

//사자가 1, 2, 3.. 마리일때를 따지지 말고, n-1번째에 놓지 않을지, 좌측 or 우측에 놓을지를 따져야함
int main(void){
	int n;
    cin >> n;
    int dp[100001][3] = {0,};
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
	return 0;
}