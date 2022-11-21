#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief FAIL
 * 들어오는 블록에 대해 처리해주어야 할 상황이 2개밖에 없음
 *  1. 현재 블록이 스택의 top의 블록보다 작을때
 *  2. 클때
 * 큰경우에는 그냥 stack에 push하면 되므로 PASS!
 * 
 * 작은 경우에는 stack을 역추적하면서 만들 수 있는 직사각형의 넓이의 최대값을 찾음
 * 이때 가로의 길이를 잘 계산해주어야함
 * 이 방식은 마지막에 stack이 남는 경우가 생길 수 있으므로, 반복문이 끝나도 한번 더 스택을 검사해주어야함.
 * 
 */

int n;
int h[10001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1) {
        cin >> n;
        if (n == 0)
            break;
        long long ans = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++)
            cin >> h[i];
        
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && h[stk.top()] > h[i])
            {
                long long height = h[stk.top()];
                stk.pop();
                long long w = i;
                if (!stk.empty())
                    w = i - stk.top() - 1;
                ans = max(ans, w * height);
            }
            stk.push(i);
        }
        while (!stk.empty())
        {
            long long height = h[stk.top()];
            stk.pop();
            long long w = n;
            if (!stk.empty())
                w = n - stk.top() - 1;
            ans = max(ans, w * height);
        }
        cout << ans << "\n";
    }
}