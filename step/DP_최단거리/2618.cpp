#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/**
 * @brief FAIL
 * 1. Greedy하게 순간순간 제일 빨리 갈 수 있는 것을 선택하려 했으나 실패
 * 2. 아예 완전탐색에 DP로 시간을 줄여주는 방식을 사용해야 성공
 */

int N, W;
pair<int, int> work[1001];
int dp_table[1001][1001];

int dist(pair<int, int>a, pair<int, int>b)
{
	return abs(b.first - a.first) + abs(b.second - a.second);
}

int dp(int x, int y)
{
	if (x == W || y == W)
		return 0;

	//memoization
	int &cache = dp_table[x][y];
	if (cache != -1)
        return dp_table[x][y];

	int next = max(x, y) + 1;	//다음사건
	int dist1, dist2;
	
	//base
	//x가 next로 움직일때,
	if (x == 0)
		dist1 = dist({1, 1}, work[next]);
	else
		dist1 = dist(work[x], work[next]);

	//y가 next로 움직일때
	if (y == 0)
		dist2 = dist({N, N}, work[next]);
	else
		dist2 = dist(work[y], work[next]);

	cache = min(dp(next, y) + dist1, dp(x, next) + dist2);
	return cache;
}

void dfs(int x, int y)
{
	if (x == W || y == W)
		return;

	int next = max(x, y) + 1;	//다음사건
	int dist1, dist2;

	//base
	//x가 next로 움직일때,
	if (x == 0)
		dist1 = dist({1, 1}, work[next]);
	else
		dist1 = dist(work[x], work[next]);

	//y가 next로 움직일때
	if (y == 0)
		dist2 = dist({N, N}, work[next]);
	else
		dist2 = dist(work[y], work[next]);

	if (dp_table[next][y] + dist1 > dp_table[x][next] + dist2) {
		cout << 2 << "\n";
		dfs(x, next);
	}
	else
	{
		cout << 1 << "\n";
		dfs(next, y);
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> N >> W;
	for (int i = 1; i <= W; ++i) 
        cin >> work[i].first >> work[i].second;
	memset(dp_table, -1, sizeof(dp_table));

	cout << dp(0, 0) << endl;
	dfs(0, 0);
	
	return 0;
}

// int dist(int x, int y, int a, int b)
// {
//     int ret = abs(a - x) + abs(b - y);
//     return ret;
// }

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     cin >> N >> W;
//     vector<int> ans(W, 0);
//     int sum = 0;
//     int ox = 1, oy = 1, nx = N, ny = N;
//     for (int i = 0; i < W; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         dp[1][i] = dist(ox, oy, x, y);
//         dp[2][i] = dist(nx, ny, x, y);
//         if (dp[1][i] < dp[2][i])
//         {
//             sum += dp[1][i];
//             ans[i] = 1;
//             ox = x;
//             oy = y;
//         }
//         else
//         {
//             sum += dp[2][i];
//             ans[i] = 2;
//             nx = x;
//             ny = y;
//         }
//     }
//     cout << sum << endl;
//     for (int i : ans)
//         cout << i << "\N";
// }