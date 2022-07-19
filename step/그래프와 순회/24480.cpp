#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R, num;

bool visited[100001];
int ans[100001];

void dfs(vector<vector<int>> &V, int start) {
    visited[start] = true;
    ans[start] = ++num;
    if (V[start].size() == 0)
        return ;
    for (int i : V[start])
    {
        if (visited[i] == false)
            dfs(V, i);
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
    dfs(V, R);
    for (int i = 1; i <= N; i++)
        cout << ans[i] << "\n";
}