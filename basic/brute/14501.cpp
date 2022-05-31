#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> T, P;

void DFS(int price, int idx, int *answer) {
    if (idx > N)
    {
        *answer = max(*answer, price);
        return;
    }
    if (idx + T[idx] <= N + 1)
        DFS(price + P[idx], idx + T[idx], answer);
    DFS(price, idx + 1, answer);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    T.push_back(0);
    P.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int t, p;
        cin >> t >> p;
        T.push_back(t);
        P.push_back(p);
    }
    int ans = -1;
    DFS(0, 1, &ans);
    cout << ans << endl;
}