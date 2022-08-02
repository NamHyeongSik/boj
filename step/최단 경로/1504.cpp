#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 1 -> v1 -> v2 -> N 또는 1 -> v2 -> v1 -> N으로 가는 경로 2가지가 존재할 수 있음.
// 따라서 다익스트라 알고리즘을 3번 사용해서 각 구간별 최단거리의 합이 제일 작은 경우를 고르면 됨.
// 이 과정에서 INF를 __INT_MAX__와 같은 값을 사용할 경우 탐색 유무를 체크할 때 문제가 생기므로 주의

#define INF 987654321

int N, E;
vector<pair<int, int>> graph[801];

vector<int> dijkstra(int start) {
    vector<int> dp(N + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    dp[start] = 0;
    while (!q.empty())
    {
        int w = q.top().first;
        int crnt = q.top().second;
        q.pop();
        if (dp[crnt] < w)
            continue;
        for (int i = 0; i < graph[crnt].size(); i++)
        {
            int next = graph[crnt][i].first;
            int nw = graph[crnt][i].second;
            if (nw + w < dp[next])
            {
                dp[next] = nw + w;
                q.push({nw + w, next});
            }
        }
    }
    return dp;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> E;
    
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;
    vector<int> start_first = dijkstra(1);
    vector<int> v1_first = dijkstra(v1);
    vector<int> v2_first = dijkstra(v2);
    int ans = min(start_first[v1] + v1_first[v2] + v2_first[N], start_first[v2] + v2_first[v1] + v1_first[N]);
    if (ans >= INF || ans <= 0)
        cout << -1;
    else
        cout << ans;
}