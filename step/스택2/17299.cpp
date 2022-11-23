#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> f(1000001, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    
    stack<int> stk, ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (stk.empty())
            ans.push(-1);
        else
        {
            while (!stk.empty() && f[stk.top()] <= f[a[i]])
                stk.pop();
            if (stk.empty())
                ans.push(-1);
            else
                ans.push(stk.top());
        }
        stk.push(a[i]);
    }
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}