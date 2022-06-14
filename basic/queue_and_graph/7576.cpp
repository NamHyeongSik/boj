#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int check[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> box(M, vector<int>(N, 0));

    queue<pair<int, int>> q;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                check[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    int days = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N &&
                check[nx][ny] == 0 && box[nx][ny] != -1)
                {
                    check[nx][ny] = check[x][y] + 1;
                    days = check[nx][ny];
                    q.push({nx, ny});
                }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (box[i][j] == 0 && check[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << days;
    return 0;
}