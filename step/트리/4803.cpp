#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/**
 * @brief FAIL
 * 
 * 예제에 대한 출력을 제대로 이해못함
 * 사이클은 DFS로 쉽게 찾을 수 있지만, 양방향 연결이기 때문에 이전에 방문한 노드일 경우 continue로 넘어가줘야함
 * n개의 노드에 n-1개의 간선이 있어야 트리이기 때문에, n번만큼 반복문을 돌면 자연스럽게 간선의 개수가 세어짐.
 * 
 */

int n, m;
vector<int> graph[501];
bool visited[501];

bool dfs(int crnt, int before)
{
    visited[crnt] = true;
    for (const int &next : graph[crnt])
    {
        if (next == before) continue;
        if (visited[next])
            return false;
        if (!dfs(next, crnt))
            return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c = 1;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        
        for (int i = 1; i <= n; i++)
            graph[i].clear();
        memset(visited, false, sizeof(visited));
        
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (!visited[i])
                if (dfs(i, 0))
                    ans++;
        
        cout << "Case " << c++;
        if (ans == 0)
            cout << ": No trees.";
        else if (ans == 1)
            cout << ": There is one tree.";
        else
            cout << ": A forest of " << ans << " trees.";
        cout << "\n";
    }
}