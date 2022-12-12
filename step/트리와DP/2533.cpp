#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief FAIL 이제 문제 유형은 확실히 알겠는데 잘 못풀겠습니다...
 * 이전의 1949 - 우수마을 과 아주 비슷한 유형입니다.
 * 1번을 root로 잡고 끝 노드까지 탐색 하면서
 * 그 노드가 얼리 어답터일 때 vs 아닐 때로 구분해서 dp에 추가해주면 됩니다.
 * 
 */

#define MAX_NODES 1000001

int N;
vector<int> tree[MAX_NODES];
int dp[MAX_NODES][2];
bool visited[MAX_NODES];

void DFS(int crnt) {
    visited[crnt] = true;
    dp[crnt][0] = 0;
    dp[crnt][1] = 1;
    for (const int &next : tree[crnt])
    {
        if (visited[next]) continue;
        DFS(next);
        dp[crnt][0] += dp[next][1];
        dp[crnt][1] += min(dp[next][0], dp[next][1]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    DFS(1);
    cout << min(dp[1][0], dp[1][1]);
}