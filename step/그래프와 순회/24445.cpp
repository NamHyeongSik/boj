#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//문제좀 잘 읽으세요...

int N, M, R, num;
bool visited[100001];
int ans[100001];

void bfs(vector<vector<int>> &V, int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    ans[start] = ++num;
    while (!q.empty())
    {
        int crnt = q.front();
        q.pop();
        for (int i = 0; i < V[crnt].size(); i++)
        {
            int next = V[crnt][i];
            if (visited[next] == false)
            {
                visited[next] = true;
                q.push(next);
                ans[next] = ++num;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> R;

    vector<vector<int>> V(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
        sort(V[i].rbegin(), V[i].rend());
    bfs(V, R);
    for (int i = 1; i <= N; i++)
        cout << ans[i] << "\n";
}