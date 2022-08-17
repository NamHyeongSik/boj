#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// 알고리즘은 알고 있었으나 그 조건을 깔끔히 짜는 연습을 많이 해봐야할듯
// 절댓값 == 0에서 부터의 거리
// 포인터를 움직이는 조건을 명확히하자!

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int start = 0;
    int end = N - 1;
    int before = 2e10;
    vector<pair<int, int>> ans(1);
    while (start < end)
    {
        int tmp = v[start] + v[end];
        if (before > abs(tmp))
        {
            before = abs(tmp);
            ans[0] = {v[start], v[end]};
            if (tmp == 0)
                break;
        }
        if (tmp < 0)
            start++;
        else
            end--;
    }
    cout << ans[0].first << " " << ans[0].second;
}