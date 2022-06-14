#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//2차원 배열로 해야한다는 것을 생각 못함.
int check[1001][1001];

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int S;
    cin >> S;
    
    queue<pair<int, int>> q;

    //window & clipboard
    q.push({1, 0});
    check[1][0] = 1;
    while (!q.empty())
    {
        int crnt = q.front().first;
        int clip = q.front().second;
        q.pop();
        if (crnt == S)
        {
            cout << check[crnt][clip] - 1;
            break;
        }
        if (check[crnt][crnt] == 0)
        {
            q.push({crnt, crnt});
            check[crnt][crnt] = check[crnt][clip] + 1;
        }
        if (clip && crnt + clip <= S && check[crnt + clip][clip] == 0)
        {
            q.push({crnt + clip, clip});
            check[crnt + clip][clip] = check[crnt][clip] + 1;
        }
        if (crnt > 0 && check[crnt - 1][clip] == 0)
        {
            q.push({crnt - 1, clip});
            check[crnt - 1][clip] = check[crnt][clip] + 1;
        }
    }

    return 0;
}