#include <iostream>
#include <queue>
#include <vector>

/**
 * @brief FAIL
 * 
 * 다익스트라 알고리즘은 알고 있었지만, 경로를 역추적하는 과정을 몰랐음
 * union find 처럼 그때그때마다 경로를 저장하여 역추적 하면 됨
 * 
 */

using namespace std;
#define INF 987654321

int n, m;
int A, B;
vector<pair<int, int>> city[1001];
vector<int> ans;
int dist[1001];
int route[1001];

void BFS() {
    priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, A});
    dist[A] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int crnt = pq.top().second;
        pq.pop();
        if (dist[crnt] < cost) continue;
        for (int i = 0; i < city[crnt].size(); i++)
        {
            int next = city[crnt][i].first;
            int next_cost = city[crnt][i].second + cost;
            if (next_cost < dist[next])
            {
                dist[next] = next_cost;
                route[next] = crnt;
                pq.push({next_cost, next});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        city[a].push_back({b, w});
    }
    cin >> A >> B;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    BFS();
    cout << dist[B] << endl;
    while (B)
    {
        ans.push_back(B);
        B = route[B];
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
	return 0;
}
