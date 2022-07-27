#include <iostream>
#include <queue>

using namespace std;
int check[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;

    queue<int> q;
    q.push(N);
    check[N] = 1;
    while (!q.empty())
    {
        int crnt = q.front();
        q.pop();
        if (crnt == K)
            break;
        for (int next : {crnt - 1, crnt + 1, 2 * crnt})
        {
            if (next < 0 || next > 100000) continue;
            if (check[next]) continue;
            check[next] = check[crnt] + 1;
            q.push(next);
        }
    }
    cout << check[K] - 1;
}