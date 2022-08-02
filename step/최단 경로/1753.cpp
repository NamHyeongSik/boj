#include <iostream>
#include <queue>
#include <vector>
// 2차원 벡터를 사용하게 되면 메모리 초과!
// 따라서 벡터 배열을 사용
using namespace std;

int V, E, K;
int dp[20001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> V >> E >> K;
    vector<pair<int, int>> graph[20001];
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    for (int i = 1; i <= V; i++)
        dp[i] = __INT_MAX__;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({K, 0});
    dp[K] = 0;
    while (!q.empty())
    {
        int crnt = q.top().first;
        int w = q.top().second;
        q.pop();
        if (dp[crnt] < w)
            continue;
        for (int i = 0; i < graph[crnt].size(); i++)
        {
            int next = graph[crnt][i].first;
            int nw = graph[crnt][i].second;
            if (nw == 0) continue;
            if (nw + w < dp[next])
            {
                dp[next] = nw + w;
                q.push({next, nw + w});
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (dp[i] == __INT_MAX__)
            cout << "INF\n";
        else
            cout << dp[i] << "\n";
    }
}