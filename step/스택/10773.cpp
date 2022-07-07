#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;

    stack<int> stk;
    int ans = 0;
    while (K--)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
        {
            ans -= stk.top();
            stk.pop();
        }
        else
        {
            stk.push(tmp);
            ans += tmp;
        }
    }
    cout << ans;
}