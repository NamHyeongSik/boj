#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> graph[1001];
bool check[1001];
int N, M, V;

void dfs(int v) {
    cout << v << " ";
    check[v] = true;
    if (graph[v].size() == 0)
        return ;
    sort(graph[v].begin(), graph[v].end());
    for (int next : graph[v])
    {
        if (check[next] == false)
        {
            dfs(next);
        }
    }
}

void bfs(int v) {
    cout << v << " ";
    check[v] = true;
    queue<int> q;
    q.push(v);

    while (!q.empty())
    {
        int crnt = q.front();
        q.pop();
        sort(graph[crnt].begin(), graph[crnt].end());
        for (int next : graph[crnt])
        {
            if (check[next] == false)
            {
                check[next] = true;
                q.push(next);
                cout << next << " ";
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >>V;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(V);
    cout << "\n";
    for (int i = 1; i <= N; i++)
        check[i] = false;
    bfs(V);
}