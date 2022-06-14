#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[100001];

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, K;
    cin >> N >> K;

    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, N});
    check[N] = true;
    while (!pq.empty())
    {
        int time = pq.top().first;
        int crnt = pq.top().second;
        pq.pop();
        if (crnt == K)
        {
            ans = time;
            break;
        }
        int next[3] = {crnt * 2, crnt - 1, crnt + 1};
        for (int i = 0; i < 3; i++)
        {
            if (next[i] < 0 || next[i] > 100000) continue;
            if (check[next[i]]) continue;
            check[next[i]] = true;
            if (i == 0)
                pq.push({time, next[i]});
            else
                pq.push({time + 1, next[i]});
        }
    }

    cout << ans << "\n";
}