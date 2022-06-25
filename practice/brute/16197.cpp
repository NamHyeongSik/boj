#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct coin
{
    int x1, y1, x2, y2;
    int count;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char board[20][20];
vector<pair<int, int>> start;
int N, M;

bool out_of_bound(int x, int y)
{
    if(x < 0 || x >= N || y < 0 || y >= M)
        return true;
    return false;
}

int bfs()
{
    queue<coin> q;

    q.push({start[0].first, start[0].second, 
            start[1].first, start[1].second,
            0});
    
    while(!q.empty())
    {
        coin c = q.front();
        
        int x1 = c.x1;
        int y1 = c.y1;
        int x2 = c.x2;
        int y2 = c.y2;
        int crnt = c.count;

        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];
            
            int next = crnt + 1;

            if(11 < next)
                return -1;
            
            bool X1Y1 = out_of_bound(nx1, ny1);
            bool X2Y2 = out_of_bound(nx2, ny2);
            
            if(X1Y1 && X2Y2)
                continue;
            if(!X1Y1 && !X2Y2)
            {
                if(board[nx1][ny1] == '#')
                {
                    nx1 = x1;
                    ny1 = y1;
                }
                if(board[nx2][ny2] == '#')
                {
                    nx2 = x2;
                    ny2 = y2;
                }
                q.push({nx1, ny1, nx2, ny2, next});
            }
            else
                return next;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;

    for(int n = 0; n < N; n++)
    {
        for(int m = 0; m < M; m++)
        {
            cin >> board[n][m];
            if(board[n][m] == 'o')
                start.push_back({n, m});
        }
    }
    
    int sol = bfs();

    if(10 < sol)
        cout << -1;
    else
        cout << bfs();
        
    return 0;
}
