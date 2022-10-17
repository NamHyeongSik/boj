#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define MAX 10001

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
    for (int i = 0; i < N - 1; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back(make_pair(y, w));
        v[y].push_back(make_pair(x, w));
    }
    DFS(1, 0);
    ans = 0;
    memset(visited, false, N + 1);
    DFS(deep, 0);
    cout << ans;
}