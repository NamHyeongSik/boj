#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
long long ans = 0;
int n, m;
int a[1000], b[1000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> left, right;
    for (int i = 0; i < n; i++)
    {
        int sum = a[i];
        left.push_back(sum);
        for (int j = i + 1; j < n; j++)
        {
            sum += a[j];
            left.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int sum = b[i];
        right.push_back(sum);
        for (int j = i + 1; j < m; j++)
        {
            sum += b[j];
            right.push_back(sum);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for (int i = 0; i < left.size(); i++)
    {
        int lower = lower_bound(right.begin(), right.end(), T - left[i]) - right.begin();
        int upper = upper_bound(right.begin(), right.end(), T - left[i]) - right.begin();
        ans += upper - lower;
    }
    cout << ans;
}