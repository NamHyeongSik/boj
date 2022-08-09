#include <iostream>
#include <vector>

using namespace std;

#define INF 4000001

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> town(V + 1, vector<int>(V + 1, INF));
    for (int i = 1; i <= V; i++)
        town[i][i] = 0;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        town[a][b] = c;
    }
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                town[i][j] = min(town[i][j], town[i][k] + town[k][j]);

    int ans = INF;
    for (int i = 1; i <= V; i++)
        for (int j = i + 1; j <= V; j++)
            ans = min(ans, town[i][j] + town[j][i]);
            
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}