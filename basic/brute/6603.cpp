#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int S[50];

void DFS(int idx, int count, int prev, vector<int> &lotto) {
    if (count == 6)
    {
        for (int l : lotto)
            cout << l << " ";
        cout << "\n";
        return;
    }
    if (idx == k)
        return;
    if (S[idx] > prev)
    {
        lotto.push_back(S[idx]);
        DFS(idx + 1, count + 1, S[idx], lotto);
        lotto.pop_back();
    }
    DFS(idx + 1, count, prev, lotto);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
            cin >> S[i];
        vector<int> lotto;
        DFS(0, 0, 0, lotto);
        cout << "\n";
    }    
}