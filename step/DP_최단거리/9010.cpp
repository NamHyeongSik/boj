#include <iostream>
#include <queue>
#include <cstring>

/**
 * @brief SUCCESS 멍청아 실수좀 줄여라
 * 
 * Test케이스가 있으면 visited배열을 매번 초기화
 * 문제를 꼼꼼히 읽어볼것!
 */

using namespace std;
int A, B;
bool visited[10000];

void BFS() {
    queue<pair<int, string>> q;
    q.push({A, ""});
    visited[A] = true;
    while (!q.empty())
    {
        int a = q.front().first;
        string cmd = q.front().second;
        q.pop();
        if (a == B)
        {
            cout << cmd << "\n";
            break;
        }
        int D, S, L, R;
        D = (a * 2) % 10000;
        S = (a - 1) < 0 ? 9999 : a - 1;
        L = (a % 1000) * 10 + a / 1000;
        R = (a % 10) * 1000 + a / 10;
        if (visited[D] == false)
        {
            visited[D] = true;
            q.push({D, cmd + "D"});
        }
        if (visited[S] == false)
        {
            visited[S] = true;
            q.push({S, cmd + "S"});
        }
        if (visited[L] == false)
        {
            visited[L] = true;
            q.push({L, cmd + "L"});
        }
        if (visited[R] == false)
        {
            visited[R] = true;
            q.push({R, cmd + "R"});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> A >> B;
        memset(visited, false, sizeof(visited));
        BFS();
    }
	return 0;
}
