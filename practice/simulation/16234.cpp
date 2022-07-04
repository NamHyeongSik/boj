#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

using namespace std;

int N, L, R;
int A[51][51];
bool check[51][51];

bool BFS(int r, int c) {
    queue<pair<int, int>> q;
    check[r][c] = true;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    q.push({r, c});

    int sum = A[r][c];
    int n = 1;
    vector<pair<int, int>> v;
    v.push_back({r, c});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (check[nx][ny]) continue;

            int dist = abs(A[nx][ny] - A[x][y]);
            if (dist < L || dist > R) continue;
            check[nx][ny] = true;
            q.push({nx, ny});
            v.push_back({nx, ny});
            sum += A[nx][ny];
            n++;
        }
    }
    if (n == 1)
        return false;
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        A[x][y] = sum / n;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> A[r][c];

    int ans = 0;
    while (1)
    {
        bool next = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                check[i][j] = false;
        
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (check[r][c]) continue;
                if (BFS(r, c))
                    next = true;
            }
        }
        if (next)
            ans++;
        else
            break;
    }
    cout << ans;
}
