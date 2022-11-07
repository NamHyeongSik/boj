#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

int N, M;
int arr[7];
vector<pair<int, int>> v[7];
int map[11][11];
bool visited[11][11];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int get_distance(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 || y1 == y2)
    {
        if (x1 == x2)
        {
            if (y1 > y2)
                swap(y1, y2);
            for (int i = y1 + 1; i < y2; i++)
                if (map[x1][i])
                    return 0;
        }
        else
        {
            if (x1 > x2)
                swap(x1, x2);
            for (int i = x1 + 1; i < x2; i++)
                if (map[i][y1])
                    return 0;
        }
        return (abs(x1 - x2) + abs(y1 - y2) - 1);
    }
    return 0;
}

int get_parent(int x)
{
    if (arr[x] == x)
        return x;
    return arr[x] = get_parent(arr[x]);
}

void union_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a < b)
        arr[b] = a;
    else
        arr[a] = b;
}

bool find(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a == b)
        return true;
    return false;
}

void BFS(int sx, int sy, int num) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    v[num].push_back({sx, sy});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
            v[num].push_back({nx, ny});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j]) continue;
            if (map[i][j] == 0) continue;
            visited[i][j] = true;
            BFS(i, j, ++num);
        }
    }

    vector<tuple<int, int, int>> ans;
    for (int i = 1; i < num; i++)
    {
        for (int j = i + 1; j <= num; j++)
        {
            int tmp = 10000;
            for (const auto &p : v[i])
            {
                int x1 = p.first;
                int y1 = p.second;
                for (const auto &pp : v[j])
                {
                    int x2 = pp.first;
                    int y2 = pp.second;
                    int d = get_distance(x1, y1, x2, y2);
                    if (d <= 1) continue;
                    ans.push_back({i, j, d});
                }
            }
        }
    }

    sort(ans.begin(), ans.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
        return get<2>(a) < get<2>(b);
    });

    int sum = 0;
    int count = 0;
    for (int i = 1; i <= num; i++)
        arr[i] = i;
    for (int i = 0; i < ans.size(); i++)
    {
        int x, y, w;
        tie(x, y, w) = ans[i];
        if (!find(x, y))
        {
            count++;
            union_parent(x, y);
            sum += w;
        }
    }
    if (count != num - 1)
        cout << -1;
    else
        cout << sum << endl;
}