#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dist[100][100];
int maze[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = tmp[j] - '0';
            dist[i][j] = -1;
        }
    }

    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (maze[nx][ny] == 0) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[N - 1][M - 1] + 1;
}