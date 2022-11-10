#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int ans[3];
void dfs(int x, int y, int n) {
    if (n == 1)
    {
        switch (board[x][y])
        {
        case -1:
            ans[0]++;
            break;
        case 0:
            ans[1]++;
            break;
        case 1:
            ans[2]++;
            break;
        default:
            break;
        }
        return;
    }

    bool minus = false, zero = false, one = false;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (board[i][j] == -1)
                minus = true;
            else if (board[i][j] == 0)
                zero = true;
            else
                one = true;
            
            if ((minus && zero) || (minus && one) || (zero && one))
                break;
        }
        if ((minus && zero) || (minus && one) || (zero && one))
                break;
    }
    if (minus && !zero && !one)
        ans[0]++;
    else if (!minus && zero && !one)
        ans[1]++;
    else if (!minus && !zero && one)
        ans[2]++;
    else
    {
        dfs(x, y, n / 3);
        dfs(x, y + n / 3, n / 3);
        dfs(x, y + 2 * n / 3, n / 3);
        dfs(x + n / 3, y, n / 3);
        dfs(x + n / 3, y + n / 3, n / 3);
        dfs(x + n / 3, y + 2 * n / 3, n / 3);
        dfs(x + 2 * n / 3, y, n / 3);
        dfs(x + 2 * n / 3, y + n / 3, n / 3);
        dfs(x + 2 * n / 3, y + 2 * n / 3, n / 3);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
            cin >> v[j];
        board.push_back(v);
    }
    dfs(0, 0, n);
    for (int i : ans)
        cout << i << endl;
}