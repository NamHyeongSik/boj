#include <iostream>
#include <vector>

using namespace std;

int N;

void DFS(int energy, int *ans, vector<int> W) {
    if (W.size() == 3)
    {
        energy += (W[0] * W[2]);
        *ans = max(*ans, energy);
        return ;
    }
    for (int i = 1; i < W.size() - 1; i++)
    {
        int x = W[i];
        int tmp = W[i - 1] * W[i + 1];
        W.erase(W.begin() + i);
        DFS(energy + tmp, ans, W);
        W.insert(W.begin() + i, x);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; i++)
        cin >> W[i];
    
    int ans = 0;
    DFS(0, &ans, W);
    cout << ans << "\n";
    return 0;
}
