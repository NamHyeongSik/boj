#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    
    bool is_next = next_permutation(v.begin(), v.end());
    if (is_next) {
        for (int n : v)
            cout << n << " ";
    }
    else
        cout << -1;
    
}