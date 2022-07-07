#include <iostream>
#include <stack>
#include <vector>

using namespace std;
//2중for문 -> 시간초과
//stack -> 208ms
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    vector<int> ans(N);
    stack<int> stk;
    for (int i = N - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() <= A[i])
            stk.pop();
        if (stk.empty())
            ans[i] = -1;
        else
            ans[i] = stk.top();
        stk.push(A[i]);
    }
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
}