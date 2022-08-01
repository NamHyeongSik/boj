#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
/*
 처음엔 노드를 삭제해보고 2개로 나눌 수 있는지 체크하려했으나 까다로움
 어차피 2개의 그룹으로 나눌 수 있는지를 따지는 것이므로, 하나의 그룹은 1로, 나머지는 -1로 체크
 탐색중에 이미 그룹으로 구분이 되어있는데 다른 그룹에서 탐색이 되면 종료!
*/
int V, E;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int K;
    cin >> K;
    while (K--)
    {
        cin >> V >> E;
        vector<vector<int>> graph(V + 1);
        vector<int> check(V + 1, 0);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool is_bipartite = true;
        for (int i = 1; i <= V; i++)
        {
            if (is_bipartite == false) break;
            if (check[i]) continue;
            queue<int> q;
            q.push(i);
            check[i] = 1;
            while (!q.empty())
            {
                int crnt = q.front();
                q.pop();
                for (int next : graph[crnt])
                {
                    if (check[next] == 0) {
                        check[next] = check[crnt] * -1;
                        q.push(next);
                    }
                    else if (check[next] == check[crnt])
                    {
                        is_bipartite = false;
                        break;
                    }
                }
            }
        }
        if (is_bipartite)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}