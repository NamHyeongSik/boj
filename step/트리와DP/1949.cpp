#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief FAIL 너무 어렵습니다...
 * 노드를 방문하면서 그 노드가 우수마을일때, 일반마을일때를 구분해서 값을 저장
 *     dp[crnt][0] : 현재 일반마을일때
 *     dp[crnt][1] : 현재 우수마을일때
 * 현재 일반마을이라면 다음 마을이 일반/우수 일때의 최대값을 저장
 * 현재 우수마을이라면 다음 마을은 무조건 일반마을이어야 하므로 일반일대의 최대값을 저장
 */

int n;
int w[10001];
int dp[10001][2];
bool visited[10001];
vector<int> tree[10001];

void dfs(int crnt)
{
    visited[crnt] = true;

    dp[crnt][0] = 0;
    dp[crnt][1] = w[crnt];

    for (const int next : tree[crnt])
    {
        if (visited[next]) continue;
        dfs(next);

        dp[crnt][0] += max(dp[next][0], dp[next][1]);
        dp[crnt][1] += dp[next][0];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}