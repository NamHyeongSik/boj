#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2번 연속 틀렸습니다.
// 처음에는 소수 집합의 누적합을 이용했으니 실패
// 그때 그때 값을 더해주고 빼주는 방식을 사용하여 성공

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> prime;
    for (int i = 2; i <= N; i++)
        if (is_prime(i))
            prime.push_back(i);

    int i = 0, j = 0;
    int ans = 0;
    int sum = prime[0];
    while (i <= j && j < prime.size())
    {
        if (sum <= N)
        {
            if (sum == N)
                ans++;
            sum += prime[++j];
        }
        else
            sum -= prime[i++];
        if (i > j)
        {
            j = i;
            sum = prime[j];
        }
    }
    cout << ans;
}