#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS(int i, int j, int N, vector<vector<int>> &map) {
    check[i][j] = true;

    int count = 0;
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = nx + dx[i];
            int y = ny + dy[i];
            if (x >= 0 && y >= 0 && x < N && y < N && check[x][y] == false && map[x][y])
            {
                check[x][y] = true;
                q.push({x, y});
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> map(N, vector<int>(N, 0));
    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        for (int j = 0; j < N; j++)
            map[i][j] = tmp[j] - '0';
    }

    vector<int> section;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (check[i][j] == false && map[i][j])
                section.push_back(BFS(i, j, N, map) + 1);
        }
    }
    cout << section.size() << endl;
    sort(section.begin(), section.end());
    for (int s : section)
        cout << s << "\n";
}