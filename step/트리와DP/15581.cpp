#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/**
 * @brief HINT가 너무 결정적이었습니다.
 * 
 */

int N, R, Q;
vector<int> tree[100001];
int dp[100001];

void dfs(int current, int before)
{
    dp[current] = 1;
    for (const int &next : tree[current])
    {
        if (next == before) continue;
        dfs(next, current);
        dp[current] += dp[next];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(R, 0);
    for (int i = 0; i < Q; i++)
    {
        int u;
        cin >> u;
        cout << dp[u] << "\n";
    }
}