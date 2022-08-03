#include <iostream>
#include <queue>
#include <vector>

using namespace std;
bool visited[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, N});
    visited[N] = true;
    while (!q.empty())
    {
        int time = q.top().first;
        int crnt = q.top().second;
        q.pop();
        if (crnt == K)
        {
            cout << time;
            break;
        }
        for (int next : {crnt * 2, crnt + 1, crnt - 1})
        {
            if (next > 100000 || next < 0) continue;
            if (visited[next]) continue;
            visited[next] = true;
            if (next == crnt * 2)
                q.push({time, next});
            else
                q.push({time + 1, next});
        }
    }
}