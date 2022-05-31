#include <iostream>

using namespace std;

int arr[4] = {0, 1, 2, 3};

void DFS(int sum, int n, int *answer) {
    if (sum == n)
    {
        (*answer)++;
        return;
    }
    for (int i = 1; i < 4; i++)
    {
        sum += arr[i];
        if (sum <= n)
            DFS(sum, n, answer);
        sum -= arr[i];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int ans = 0;
        DFS(0, n, &ans);
        cout << ans << "\n";
    }
}