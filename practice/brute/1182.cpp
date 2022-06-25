#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    int ans = 0;
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 1; i <= N; i++)
    {
        vector<int> ind;
        for (int j = 0; j < i; j++)
            ind.push_back(1);
        for (int j = 0; j < N - i; j++)
            ind.push_back(0);
        sort(ind.begin(), ind.end());

        do {
            int sum = 0;
            for (int j = 0; j < N; j++)
                if (ind[j])
                    sum += v[j];
            if (sum == S)
                ans++;
        } while (next_permutation(ind.begin(), ind.end()));
    }
    cout << ans;
}