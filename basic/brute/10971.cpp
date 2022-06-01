#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
bool visited[11];

void DFS(int root, int start, int count, int cost, int *answer, vector<vector<int>> &w) {
    if (count == N - 1)
    {
        if (w[start][root])
            *answer = min(*answer, cost + w[start][root]);
        return ;
    }
    for (int i = 0; i < N; i++)
    {
        if (w[start][i] == 0) continue;
        if (visited[i]) continue;

        visited[i] = true;
        DFS(root, i, count + 1, cost + w[start][i], answer, w);
        visited[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<vector<int>> w(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> w[i][j];

    int ans = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        visited[i] = true;
        DFS(i, i, 0, 0, &ans, w);
        visited[i] = false;
    }
    cout << ans << endl;
}