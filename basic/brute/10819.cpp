#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans = -2000;
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    do
    {
        int sum = 0;
        for (int i = 0; i < N - 1; i++)
            sum += abs(v[i] - v[i + 1]);
        ans = max(ans, sum);
    } while (next_permutation(v.begin(), v.end()));
    
    cout << ans << endl;
}