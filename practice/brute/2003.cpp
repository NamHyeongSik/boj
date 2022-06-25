#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        A[i] += A[i - 1];
    int i = 0, j = 1;
    int ans = 0;
    while (i <= j && j <= N)
    {
        int n = A[j - 1] - A[i - 1];
        if (n == M)
        {
            ans++;
            j++;
        }
        else if (n > M)
            i++;
        else
            j++;
    }
    cout << ans;
}
