#include <iostream>
#include <vector>

/**
 * @brief FAIL
 * 
 * 갈수 없는 곳이면 0을 출력해라 == city[i][j] = 0 임을 i == j일때로 풀어서 한참 고생
 * 3차원 배열로 i->k, k->j로 가는 경로를 최소 비용을 저장하는 과정에서 따로 저장
 *  
 */

using namespace std;
#define INF 10000001

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> city(n + 1, vector<int>(n + 1, INF));
    vector<vector<vector<int>>> ans(n + 1, vector<vector<int>>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) city[i][j] = 0;
            ans[i][j].push_back(i);
            ans[i][j].push_back(j);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        city[a][b] = min(city[a][b], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (city[i][k] + city[k][j] < city[i][j])
                {
                    city[i][j] = city[i][k] + city[k][j];
                    vector<int> tmp = ans[k][j];
                    ans[i][j].clear();
                    ans[i][j] = ans[i][k];
                    for (int m = 1; m < tmp.size(); m++)
                        ans[i][j].push_back(tmp[m]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (city[i][j] == INF)
                city[i][j] = 0;
            cout << city[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (city[i][j] == 0)
                cout << 0 << " ";
            else
            {
                cout << ans[i][j].size() << " ";
                for (int k : ans[i][j])
                    cout << k << " ";
            }
            cout << "\n";
        }
    }

	return 0;
}
