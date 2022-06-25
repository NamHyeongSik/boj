#include <iostream>
#include <vector>

using namespace std;

//two pointer && 누적합
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, S;
    cin >> N >> S;

    vector<int> v(N + 1);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 1; i <= N; i++)
        v[i] += v[i - 1];

    int i = 0, j = 0;
    int len = N + 1;
    while (i <= j && j <= N) {
        int sum = v[j] - v[i - 1];

        if (sum >= S)
        {
            len = min(len, j - i + 1);
            i++;
            if (i > j)
                j = i;
        }
        else if (sum < S)
            j++;
    }
    if (len == N + 1)
        cout << 0;
    else
        cout << len;
}