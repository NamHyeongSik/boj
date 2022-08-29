#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// meet in the middle
// 이분탐색과 이분법에 대해서 좀 더 알아야 할 필요가 있을듯

int N, C;
int w[30];
vector<long long> a, b;

void dfs(int start, int end, vector<long long> &v, long long sum) {
    if (start > end)
    {
        v.push_back(sum);
        return ;
    }
    else
    {
        dfs(start + 1, end, v, sum);
        dfs(start + 1, end, v, sum + w[start]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> w[i];

    dfs(0, N / 2, a, 0);
    dfs(N / 2 + 1, N - 1, b, 0);
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += upper_bound(b.begin(), b.end(), C - a[i]) - b.begin();

    cout << ans;
}