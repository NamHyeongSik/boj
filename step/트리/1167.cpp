#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/**
 * @brief DFS 두번!
 * 
 * 어차피 모든 노드가 이어져있기 때문에 가장 멀리 떨어진 노드를 찾고
 * 그 노드에서 가장 코스트가 높은 코스트를 구하면 끝
 */

#define MAX 100001

int N;
vector< pair<int, int> > v[MAX]; // v[x].first = y, v[x].second = w
bool visited[MAX];
int deep, ans;

void DFS(int next, int dist) {
    visited[next] = true;
    if (dist > ans)
    {
        deep = next;
        ans = dist;
    }
    for (int i = 0; i < v[next].size(); i++)
    {
        int node = v[next][i].first;
        int w = v[next][i].second;
        if (visited[node]) continue;
        visited[node] = true;
        DFS(node, dist + w);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        while (1)
        {
            int y, w;
            cin >> y;
            if (y == -1)
                break;
            cin >> w;
            v[x].push_back(make_pair(y, w));
        }
    }
    DFS(1, 0);
    ans = 0;
    memset(visited, false, N + 1);
    DFS(deep, 0);
    cout << ans;
}