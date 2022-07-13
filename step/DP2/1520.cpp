#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1차시도 -> BFS로 구현 -> 한쪽 방향으로 모두 이동 하지 않고 그때 그때의 상황을 보기 때문에 원하는 값이 나오지 않음.
// 2차시도 -> DFS로 구현 -> dp 초기값을 0으로 했다가 실패 -> -1로 고쳐서 성공

int dp[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;

int DFS(int i, int j, vector<vector<int>> &v)
{
    if (i == N && j == M) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 0;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x > N || y > M || x < 1 || y < 1) continue;
        if (v[x][y] < v[i][j])
            dp[i][j] += DFS(x, y, v);
    }

    return dp[i][j];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<vector<int>> v(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = -1;
            cin >> v[i][j];
        }

    int ans = DFS(1, 1, v);
    cout << ans;
}