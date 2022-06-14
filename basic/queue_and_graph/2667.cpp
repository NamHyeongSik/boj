#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
bool check[25][25];
int map[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS(int i, int j) {
    check[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});

    int count = 1;
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
            if (check[nx][ny] == false && map[nx][ny])
            {
                check[nx][ny] = true;
                count++;
                q.push({nx, ny});
            }
        }
    }
    return count;
}

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++)
            map[i][j] = tmp[j] - '0';
    }

    vector<int> section;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (check[i][j] == false && map[i][j])
                section.push_back(BFS(i, j));
        }
    }

    sort(section.begin(), section.end());
    cout << section.size() << "\n";
    for (int n : section)
        cout << n << "\n";
	return 0;
}