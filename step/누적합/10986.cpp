#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> sum(N + 1, 0);
    vector<long long> count(M, 0);
    count[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        sum[i] = sum[i - 1] + A[i];
        sum[i] %= M;
        count[sum[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < M; i++)
        ans += count[i] * (count[i] - 1) / 2;
    cout << ans;
    
}