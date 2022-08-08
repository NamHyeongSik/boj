#include <iostream>
#include <vector>
#include <tuple>

// 벨만-포드 알고리즘(음의 가중치가 있을때 사용)
// 다익스트라와 같이 vector<pair<int, int>>를 사용하여 반복문을 돌리게 되면 안되는 케이스가 발생
// tuple을 사용하여 A, B, C를 한번에 담도록 변경

using namespace std;
#define INF 50000001
int N, M;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    vector<tuple<int, int, int>> city;
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        city.push_back({A, B, C});
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < city.size(); j++)
        {
            int from, to, w;
            tie(from, to, w) = city[j];
            if (dist[from] == INF) continue;
            if (dist[to] > dist[from] + w)
                dist[to] = dist[from] + w;
        }
    }

    for (int i = 0; i < city.size(); i++)
    {
        int from, to, w;
        tie(from, to, w) = city[i];
        if (dist[from] == INF) continue;
        if (dist[to] > dist[from] + w)
        {
            cout << -1;
            return 0;
        }
    }
    for (int i = 2; i <= N; i++)
        if (dist[i] == INF)
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
}