#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * @brief FAIL 선형대수를 공부해야할 필요성
 * 증명 참고 : https://st-lab.tistory.com/252
 * 
 */

using namespace std;

#define MOD 1000000007
typedef vector<vector<long long>> matrix;
unordered_map<long long, matrix> um;
long long n;

matrix mult_matrix(const matrix &a, const matrix &b) {
    matrix ret(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= MOD;
        }
    }
    return ret;
}

matrix solution(long long n, matrix &m) {
    if (n == 1)
        return m;
    if (um.find(n) != um.end())
        return um[n];
    if (n & 1)
        return um[n] = mult_matrix(m, solution(n - 1, m));
    return um[n] = mult_matrix(solution(n / 2, m), solution(n / 2, m));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    matrix unit = {{1, 1}, {1, 0}};
    matrix ans = solution(n, unit);
    cout << ans[0][1];
}