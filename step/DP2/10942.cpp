#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DP는 확실히 순서가 매우 중요!
// 1글자 -> 2글자 -> N글자로 가야지, 1글자 -> 2글자 해놓고 3 ~ N, 4 ~ N을 반복하니까 틀림...

bool dp[2001][2001];
int N, M;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> v[i];

    for (int i = 1; i <= N; i++)
        dp[i][i] = true;
    
    for (int i = 1; i < N; i++)
        if (v[i] == v[i + 1])
            dp[i][i + 1] = true;

    for (int i = 2; i < N; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            if (v[j] == v[j + i] && dp[j + 1][j + i - 1])
                dp[j][j + i] = true;
        }
    }

    cin >> M;
    while (M--)
    {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}