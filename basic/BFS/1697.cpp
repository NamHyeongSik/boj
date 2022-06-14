#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int check[100001];

void BFS(void) {
    queue<int> q;
    q.push(N);
    check[N] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == K)
            break;
        if (x - 1 >= 0 && check[x - 1] == 0)
        {
            check[x - 1] = check[x] + 1;
            q.push(x - 1);
        }
        if (x + 1 <= 100000 && check[x + 1] == 0)
        {
            check[x + 1] = check[x] + 1;
            q.push(x + 1);
        }
        if (2 * x <= 100000 && check[2 * x] == 0)
        {
            check[2 * x] = check[x] + 1;
            q.push(2 * x);
        }
    }
    cout << check[K] - 1;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> K;
    BFS();
    return 0;
}