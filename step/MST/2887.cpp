#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

/**
 * @brief FAIL
 * 
 * N이 10만이기 때문에 모든 간선을 이어주려고 하면 O(N*N)이므로 시간초과
 * tuple을 2개 이상쓰면 메모리초과가 날 수 있으므로 조심
 * 
 * 따라서 비용을 계산하는 방식을 토대로 각 축에대해서 정렬을 해주고
 * 각 좌표에서 인접한 좌표들끼리만 간선을 만들어주면 3(N - 1)개의 간선만 생성되므로 시간을 줄일 수 있습니다.
 * 
 */

using namespace std;

int arr[100001];
vector<tuple<int, int, int>> v;
vector<pair<int, int>> cx, cy, cz;

int get_parent(int x)
{
    if (arr[x] == x)
        return x;
    return arr[x] = get_parent(arr[x]);
}

void union_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a < b)
        arr[b] = a;
    else
        arr[a] = b;
}

bool find(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a == b)
        return true;
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        cx.push_back({x, i});
        cy.push_back({y, i});
        cz.push_back({z, i});
    }

    sort(cx.begin(), cx.end());
    sort(cy.begin(), cy.end());
    sort(cz.begin(), cz.end());

    for (int i = 0; i < N; i++)
        arr[i] = i;

    for (int i = 1; i < N; i++)
    {
        v.push_back({abs(cx[i - 1].first - cx[i].first), cx[i - 1].second, cx[i].second});
        v.push_back({abs(cy[i - 1].first - cy[i].first), cy[i - 1].second, cy[i].second});
        v.push_back({abs(cz[i - 1].first - cz[i].first), cz[i - 1].second, cz[i].second});
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int w, x, y;
        tie(w, x, y) = v[i];
        if (!find(x, y))
        {
            union_parent(x, y);
            ans += w;
        }
    }
    cout << ans;
}