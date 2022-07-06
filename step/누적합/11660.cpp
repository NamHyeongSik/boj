#include <iostream>
#include <vector>

using namespace std;

//2차원 누적합에 대해서 더 공부할것!
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> v[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= N; j++)
            v[i + 1][j] += v[i][j];
        
    for (int i = 0; i <= N; i++)
        for (int j = 1; j < N; j++)
            v[i][j + 1] += v[i][j];
    
    while (M--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << v[x1 - 1][y1 - 1] + v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] << "\n";
    }
}