#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// snake일때 무시하면 된다고 생각했지만, snake여도 가긴 가야함

using namespace std;
int N, M;
int board[101];
int ladder[101];
int snake[101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    queue<int> q;
    q.push(1);
    board[1] = 1;
    while (!q.empty())
    {
        int crnt = q.front();
        q.pop();
        if (crnt == 100)
            break;
        for (int i = 1; i <= 6; i++)
        {
            int next = crnt + i;
            if (next > 100) continue;
            if (snake[next])
                next = snake[next];
            else if (ladder[next])
                next = ladder[next];
            if (board[next]) continue;
            board[next] = board[crnt] + 1;
            q.push(next);
        }
    }
    cout << board[100] - 1;
    return 0;
}