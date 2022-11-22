#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * @brief FAIL
 * 
 * 문자열 인덱싱을 아직도 잘 못하다니... 반성합시다.
 */

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str, bomb;
    cin >> str >> bomb;
    char ans[1000001];

    int idx = 0;
    for (int i = 0; i < str.size(); i++)
    {
        ans[idx++] = str[i];
        if (idx < bomb.size()) continue;
        if (ans[idx - 1] == bomb.back())
        {
            bool check = true;
            for (int j = 0; j < bomb.size(); j++)
            {
                if (ans[idx - 1 - j] != bomb[bomb.size() - 1 - j])
                {
                    check = false;
                    break;
                }
            }
            if (check)
                idx -= bomb.size();
        }
    }
    if (idx == 0)
        cout << "FRULA";
    else
    {
        for (int i = 0; i < idx; i++)
            cout << ans[i];
    }
}