#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string A, B;
    cin >> A >> B;
    
    string tmp = "";
    if (A.size() > B.size())
    {
        for (int i = 0; i < A.size() - B.size(); i++)
            tmp += "0";
        B = tmp + B;
    }
    else if (B.size() > A.size())
    {
        for (int i = 0; i < B.size() - A.size(); i++)
            tmp += "0";
        A = tmp + A;
    }

    string ans = "";
    int carry = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        int a = A[i] - '0';
        int b = B[i] - '0';
        ans.insert(ans.begin(), (a + b + carry) % 10 + '0');
        if (a + b + carry >= 10)
            carry = 1;
        else
            carry = 0;
    }
    if (carry)
        ans.insert(ans.begin(), '1');
    cout << ans;
}