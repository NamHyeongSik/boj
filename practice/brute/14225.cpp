#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool check[2000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<int> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
        check[s[i]] = true;
    }

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
                    sum += s[j];

            check[sum] = true;
        } while (next_permutation(ind.begin(), ind.end()));
    }

    for (int i = 1; i <= 2000000; i++)
    {
        if (check[i] == false)
        {
            cout << i;
            return 0;
        }
    }
}