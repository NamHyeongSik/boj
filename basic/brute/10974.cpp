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
        v[i] = i + 1;
    
    do
    {
        for (int n : v)
            cout << n << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
    
    
}