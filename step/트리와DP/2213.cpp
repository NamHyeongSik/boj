#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

/**
 * @brief FAIL
 * 1949번 - 우수마을과 똑같은 알고리즘 + 트랙킹
 * 우수마을 알고리즘을 정확히 알고 있었다면 트랙킹도 좀만 더 생각했으면 풀었을지도 모릅니다.
 * 즉 이전의 알고리즘을 정확히 몰랐다고 판단해서 FAIL처리 했습니다.
 * 우수마을에서 최대값을 선택하는 과정을 직접 작성해보면
 * 현재 방문한 노드를 선택했을 때의 dp값이 클때 그 노드를 경로에 추가해주면 됩니다.
 * 
 */

int n;
int w[10001];
int dp[10001][2];
bool visited[10001];
vector<int> tree[10001];
vector<int> path;

void tracking(int crnt, int before) {
    if (false == visited[before] && dp[crnt][1] > dp[crnt][0])
    {
        path.push_back(crnt);
        visited[crnt] = true;
    }
    for (const int &next : tree[crnt])
    {
        if (before == next) continue;
        tracking(next, crnt);
    }
}

void dfs(int crnt)
{
    visited[crnt] = true;

    dp[crnt][0] = 0;
    dp[crnt][1] = w[crnt];

    for (const int next : tree[crnt])
    {
        if (visited[next]) continue;
        dfs(next);

        dp[crnt][0] += max(dp[next][0], dp[next][1]);
        dp[crnt][1] += dp[next][0];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    memset(visited, false, 10001);
    tracking(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    sort(path.begin(), path.end());
    for (int i : path)
        cout << i << " ";
}