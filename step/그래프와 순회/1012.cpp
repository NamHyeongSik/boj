#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, K;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int map[50][50] = {0,};
        bool check[50][50] = {0,};
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++)
        {
            int X, Y;
            cin >> X >> Y;
            map[X][Y] = 1;
        }
        int ans = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] == 0) continue;
                if (check[i][j]) continue;
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                check[i][j] = true;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                        if (check[nx][ny]) continue;
                        if (map[nx][ny] == 0) continue;
                        check[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    
}