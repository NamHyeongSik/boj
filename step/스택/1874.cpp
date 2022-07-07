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
    vector<int> A(n);
    stack<int> stk;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    string ans;
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        stk.push(i);
        ans.push_back('+');
        while (!stk.empty() && stk.top() == A[j])
        {
            stk.pop();
            ans.push_back('-');
            j++;
        }
    }
    if (!stk.empty())
    {
        cout << "NO";
        return 0;
    }
    for (char c : ans)
        cout << c << "\n";
}