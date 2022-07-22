#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> computer[101];
bool check[101];
int N, M;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        computer[u].push_back(v);
        computer[v].push_back(u);
    }

    check[1] = true;
    queue<int> q;
    q.push(1);
    int ans = 0;
    while (!q.empty())
    {
        int crnt = q.front();
        q.pop();
        for (int n : computer[crnt])
        {
            if (check[n] == false)
            {
                ans++;
                q.push(n);
                check[n] = true;
            }
        }
    }
    cout << ans;
}