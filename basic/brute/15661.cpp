#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int N;
int S[21][21];
bool check[21];

void DFS(int idx, int count, int *answer) {
    if (count > N / 2)
        return;
    if (count > 0)
    {
        int start_score = 0, link_score = 0;

        for (int i = 0; i < N - 1; i++)
            for (int j = i + 1; j < N; j++)
            {
                if (check[i] && check[j])
                    start_score += S[i][j] + S[j][i];
                if (!check[i] && !check[j])
                    link_score += S[i][j] + S[j][i];
            }
        if (abs(start_score - link_score) < *answer)
            *answer = abs(start_score - link_score);
    }
    for (int i = idx; i < N; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            DFS(i + 1, count + 1, answer);
            check[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];
    
    int ans = INT_MAX;
    DFS(0, 0, &ans);
    cout << ans << "\n";
}