#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, C;
    cin >> N >> C;
    vector<int> pos(N);
    for (int i = 0; i < N; i++)
        cin >> pos[i];
    sort(pos.begin(), pos.end());

    int left = 1;
    int right = pos.back();
    int ans = 0;
    while (left <= right)
    {
        int count = 1;
        int start = pos[0];
        int mid = (left + right) / 2; // 찾고 싶은 최대거리
        for (int i = 1; i < N; i++)
        {
            if (pos[i] - start >= mid) // 인접 거리가 최대거리보다 길다면
            {
                start = pos[i]; // 시작점을 바꿔주고 공유기를 한대 설치한다.
                count++;
            }
        }
        if (count >= C)
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << ans;
}