#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> start;
pair<int, int> dest;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void BFS(int N) {
    int check[300][300] = {0, };
    check[start.first][start.second] = 1;
    queue<pair<int, int>> q;
    q.push({start.first, start.second});

    int turn = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == dest.first && y == dest.second)
            break;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (check[nx][ny]) continue;
            check[nx][ny] = check[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << check[dest.first][dest.second] - 1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l;
        cin >> l;
        cin >> start.first >> start.second;
        cin >> dest.first >> dest.second;
        BFS(l);
    }
    return 0;
}