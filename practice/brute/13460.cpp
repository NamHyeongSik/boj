#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<pair<int, int>> start(2);
bool check[10][10][10][10];

struct ball {
    int rx, ry, bx, by;
    int count;
};

int BFS(vector<vector<int>> &board) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<ball> q;
    check[start[0].first][start[0].second][start[1].first][start[1].second] = true;
    q.push({start[0].first, start[0].second,
            start[1].first, start[1].second,
            0});
    while (!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int crnt = q.front().count;
        q.pop();
        if (crnt > 10)
            break;
        if (board[rx][ry] == 'O' && board[bx][by] != 'O')
            return crnt;
        for (int i = 0; i < 4; i++)
        {
            int nrx = rx;
            int nbx = bx;
            int nry = ry;
            int nby = by;

            while (board[nrx][nry] != '#' && board[nrx][nry] != 'O')
            {
                nrx += dx[i];
                nry += dy[i];
            }
            if (board[nrx][nry] == '#')
            {
                nrx -= dx[i];
                nry -= dy[i];
            }

            while (board[nbx][nby] != '#' && board[nbx][nby] != 'O')
            {
                nbx += dx[i];
                nby += dy[i];
            }
            if (board[nbx][nby] == '#')
            {
                nbx -= dx[i];
                nby -= dy[i];
            }
            if (nrx == nbx && nry == nby && board[nrx][nry] != 'O')
            {
                int red_dist, blue_dist;
                if (i < 2)
                {
                    red_dist = abs(nrx - rx);
                    blue_dist = abs(nbx - bx);
                }
                else
                {
                    red_dist = abs(nry - ry);
                    blue_dist = abs(nby - by);
                }
                if (red_dist > blue_dist)
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }
            if (check[nrx][nry][nbx][nby]) continue;
            check[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, crnt + 1});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            board[i][j] = tmp[j];
            if (tmp[j] == 'R')
            {
                start[0].first = i;
                start[0].second = j;
            }
            if (tmp[j] == 'B')
            {
                start[1].first = i;
                start[1].second = j;
            }
        }
    }
    cout << BFS(board);
}
