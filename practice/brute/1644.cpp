#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> prime;
    for (int i = 2; i <= N; i++)
        if (is_prime(i))
            prime.push_back(i);
    prime.push_back(N + 1);
    int start = 0, end = 0;
    int sum = prime[0];
    int ans = 0;
    while (start <= end && end < prime.size())
    {
        if (sum == N)
        {
            ans++;
            sum += prime[++end];
        }
        else if (sum < N)
            sum += prime[++end];
        else {
            sum -= prime[start++];
            if (start > end) {
                end = start;
                sum = prime[start];
            }
        }
    }
    cout << ans;
}