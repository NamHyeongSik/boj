#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief FAIL
 * 
 * 키가 중복되는 경우에 대해서 어떻게 해결해야할지 몰랐음
 * pair를 이용해 같은 키의 사람의 수를 세어주어 답에 추가해줌
 * 
 */

int n;
int h[500001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];

    stack<pair<long long, long long>> stk;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long same = 1;
        while (!stk.empty() && stk.top().first <= h[i])
        {
            ans += stk.top().second;
            if (stk.top().first == h[i])
                same = stk.top().second + 1;
            else
                same = 1;
            stk.pop();
        }
        if (!stk.empty())
            ans++;
        stk.push({h[i], same});
    }
    cout << ans;
}