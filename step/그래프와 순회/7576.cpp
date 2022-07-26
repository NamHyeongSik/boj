#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int days[1000][1000];
int box[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> M >> N;
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            days[i][j] = -1;
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                q.push({i, j});
                days[i][j] = 0;
            }
        }
    int ans = 0;
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
            if (box[nx][ny] == -1) continue;
            if (days[nx][ny] != -1) continue;
            days[nx][ny] = days[x][y] + 1;
            ans = days[nx][ny];
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] != -1 && days[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
}