#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, S;
    cin >> N >> S;
    vector<int> arr(N + 1);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++)
        arr[i] += arr[i - 1];

    int len = N + 1;
    int i = 0, j = 0;
    while (i <= j && j <= N)
    {
        int sum = arr[j] - arr[i - 1];
        if (sum >= S)
        {
            len = min(len, j - i + 1);
            i++;
        }
        else
            j++;
        if (i > j)
            j = i;
    }
    if (len == N + 1)
        cout << 0;
    else
        cout << len;
}