#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int check[100001];
int path[100001];

void BFS(void) {
    queue<int> q;
    q.push(N);
    check[N] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == K)
        {
            cout << check[K] - 1 << "\n";
            vector<int> tmp;
            while (x != N)
            {
                tmp.push_back(x);
                x = path[x];
            }
            tmp.push_back(N);
            for (auto itr = tmp.rbegin(); itr != tmp.rend(); ++itr)
                cout << *itr << " ";
            break;
        }
        for (int next : {x - 1, x + 1, x * 2})
        {
            if (next < 0 || next > 100000) continue;
            if (check[next] != 0) continue;
            check[next] = check[x] + 1;
            path[next] = x;
            q.push(next);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> K;
    BFS();
    return 0;
}