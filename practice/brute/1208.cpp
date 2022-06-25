#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int arr[40];
long long ans = 0;

void make_left(int idx, int sum, vector<int> &left) {
    sum += arr[idx];
    if (idx >= N / 2) return ;
    if (sum == S) ans++;
    left.push_back(sum);
    make_left(idx + 1, sum - arr[idx], left);
    make_left(idx + 1, sum, left);
}

void make_right(int idx, int sum, vector<int> &right) {
    sum += arr[idx];
    if (idx >= N) return ;
    if (sum == S) ans++;
    right.push_back(sum);
    make_right(idx + 1, sum - arr[idx], right);
    make_right(idx + 1, sum, right);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    vector<int> left, right;
    make_left(0, 0, left);
    make_right(N / 2, 0, right);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int i = 0; i < left.size(); i++)
    {
        int tmp = S - left[i];
        int lower = lower_bound(right.begin(), right.end(), tmp) - right.begin();
        int upper = upper_bound(right.begin(), right.end(), tmp) - right.begin();
        ans += upper - lower; 
    }
    cout << ans;
}