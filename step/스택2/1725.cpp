#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int h[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    
    stack<int> stk;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && h[stk.top()] > h[i])
        {
            long long height = h[stk.top()];
            stk.pop();
            long long width = i;
            if (!stk.empty())
                width = i - stk.top() - 1;
            ans = max(ans, height * width);
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        long long height = h[stk.top()];
        stk.pop();
        long long width = n;
        if (!stk.empty())
            width = n - stk.top() - 1;
        ans = max(ans, height * width);
    }
    cout << ans;
}