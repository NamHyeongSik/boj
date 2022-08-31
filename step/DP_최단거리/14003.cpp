#include <iostream>
#include <vector>
#include <algorithm>

// 그냥 너무어렵습니다... LIS에 대해서 좀 제대로 숙지를 해야 할 것 같습니다.

using namespace std;

int N;
int dp[1000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int idx = 0;
    int len = 0;
    vector<int> LIS;
    for (int i = 0; i < N; i++)
    {
        if (LIS.empty() || LIS.back() < arr[i])
        {
            LIS.push_back(arr[i]);
            dp[i] = LIS.size();
        }
        else
        {
            auto itr = lower_bound(LIS.begin(), LIS.end(), arr[i]);
            *itr = arr[i];
            dp[i] = (itr - LIS.begin()) + 1;
        }
        if (dp[i] > len)
        {
            len = dp[i];
            idx = i;
        }
    }
    cout << LIS.size() << "\n";
    vector<int> ans;
    ans.push_back(arr[idx]);
    for (int i = idx - 1; i >= 0; i--)
    {
        if (arr[i] < arr[idx] && dp[i] + 1 == dp[idx])
        {
            idx = i;
            ans.push_back(arr[i]);
        }
    }
    for (auto itr = ans.rbegin(); itr != ans.rend(); ++itr)
        cout << *itr << " ";
}