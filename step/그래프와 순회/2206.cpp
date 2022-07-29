#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int map[1000][1000];
int dist[1000][1000][2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            map[i][j] = tmp[j] - '0';
            dist[i][j][0] = dist[i][j][1] = __INT_MAX__;
        }
    }
    
    
    queue<tuple<int, int, bool>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    while(!q.empty())
    {
        int x, y;
        bool wall;
        tie(x, y, wall) = q.front();
        q.pop();
        if (x == N - 1 && y == M - 1)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (map[nx][ny] == 1 && wall == false)
            {
                dist[nx][ny][!wall] = dist[x][y][wall] + 1;
                q.push({nx, ny, !wall});
            }
            else if (map[nx][ny] == 0 && dist[nx][ny][wall] == __INT_MAX__)
            {
                dist[nx][ny][wall] = dist[x][y][wall] + 1;
                q.push({nx, ny, wall});
            }
        }
    }
    int ans = min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);
    ans == __INT_MAX__ ? cout << -1 : cout << ans;
}