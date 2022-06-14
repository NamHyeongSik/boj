#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[101][101];
int maze[101][101];

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++)
            maze[i][j] = tmp[j] - '0';
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    check[0][0] = true;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!pq.empty())
    {
        int wall = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (x == M - 1 && y == N - 1)
        {
            cout << wall;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (check[nx][ny]) continue;
            check[nx][ny] = true;
            if (maze[nx][ny] == 0)
                pq.push({wall, {nx, ny}});
            else
                pq.push({wall + 1, {nx, ny}});
        }
    }
    return 0;
}