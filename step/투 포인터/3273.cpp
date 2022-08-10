#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;

    sort(a.begin(), a.end());
    int start = 0;
    int end = n - 1;
    int ans = 0;
    while (start < end)
    {
        int num = a[start] + a[end];
        if (num == x)
        {
            ans++;
            start++;
        }
        else if (num < x)
            start++;
        else
            end--;
    }
    cout << ans;
}