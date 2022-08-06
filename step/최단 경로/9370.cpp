#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define INF 987654321

int n, m, t;
int s, g, h;
vector<pair<int, int>> graph[2001];
bool visited[2001];

vector<int> dijkstra(int start) {
    vector<int> dp(n + 1, INF);
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
            int nw = w + graph[crnt][i].second;
            if (nw < dp[next])
            {
                dp[next] = nw;
                q.push({nw, next});
            }
        }
    }
    return dp;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        memset(graph, 0, sizeof(graph));
        memset(visited, false, sizeof(visited));
        vector<int> candidate;
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }
        for (int i = 0; i < t; i++)
        {
            int x;
            cin >> x;
            candidate.push_back(x);
        }
        sort(candidate.begin(), candidate.end());

        vector<int> start = dijkstra(s);
        vector<int> g_start = dijkstra(g);
        vector<int> h_start = dijkstra(h);
        for (int c : candidate)
        {
            if (start[c] == start[g]+ g_start[h] + h_start[c] ||
                start[c] == start[h] + h_start[g] + g_start[c])
                cout << c << "\n";
        }
    }
}