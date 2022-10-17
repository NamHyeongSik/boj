#include <iostream>
#include <vector>

/**
 * @brief FAIL
 * 단순히 부모노드만 찾으면 됩니다.
 * 루트 노드가 1인것을 알려줬기 때문에 1번노드에서부터 연결된 노드를 탐색하면서
 * 자신이 부모노드임을 알려주도록 구현
 */

using namespace std;
#define MAX 100001

int N;
int ans[MAX];
vector<int> v[MAX];
bool visited[MAX];

void DFS(int next) {
    visited[next] = true;
    for (int i = 0; i < v[next].size(); i++)
    {
        if (visited[v[next][i]]) continue;
        ans[v[next][i]] = next;
        DFS(v[next][i]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    DFS(1);
    for (int i = 2; i <= N; i++)
        cout << ans[i] << "\n";
}