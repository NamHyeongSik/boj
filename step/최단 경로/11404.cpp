#include <iostream>
#include <vector>

using namespace std;

#define INF 10000000

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> city(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        city[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        city[a][b] = min(city[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (city[i][j] == INF)
                cout << "0 ";
            else
                cout << city[i][j] << " ";
        }
        cout << "\n";
    }
    
}