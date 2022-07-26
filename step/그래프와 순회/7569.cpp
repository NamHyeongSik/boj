#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int days[100][100][100];
int box[100][100][100];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int N, M, H;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> M >> N >> H;
    queue<tuple<int, int, int>> q;

    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                {
                    days[i][j][k] = -1;
                    cin >> box[i][j][k];
                    if (box[i][j][k] == 1)
                    {
                        q.push({i, j, k});
                        days[i][j][k] = 0;
                    }
                }
    int ans = 0;
    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M ||
                nz < 0 || nz >= H) continue;
            if (box[nx][ny][nz] == -1) continue;
            if (days[nx][ny][nz] != -1) continue;
            days[nx][ny][nz] = days[x][y][z] + 1;
            ans = days[nx][ny][nz];
            q.push({nx, ny, nz});
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < H; k++)
            {
                if (box[i][j][k] != -1 && days[i][j][k] == -1)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << ans;
}