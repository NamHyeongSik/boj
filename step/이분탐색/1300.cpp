#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    int l = 1;
    int r = K;
    int ans = 1;
    while (l <= r)
    {
        int count = 0;
        int mid = (l + r) / 2;
        for (int i = 1; i <= N; i++)
            count += min(mid / i, N);
        if (count < K)
            l = mid + 1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans;
}