#include <iostream>
#include <vector>
#include <tuple>
#include <string.h>
#include <algorithm>

using namespace std;

int m, n;
int arr[200001];
vector<tuple<int, int, int>> road;

int get_parent(int x) {
    if (x == arr[x])
        return x;
    return arr[x] = get_parent(arr[x]);
}

void union_parent(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a < b)
        arr[b] = a;
    else
        arr[a] = b;
}

bool find(int a, int b) {
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
    while (1) {
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        road.clear();

        int total = 0;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            road.push_back({x, y, z});
            total += z;
        }

        for (int i = 0; i < m; i++)
            arr[i] = i;
        sort(road.begin(), road.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b){
            if (get<2>(a) < get<2>(b))
                return true;
            return false;
        });

        int ans = 0;
        for (int i = 0; i < road.size(); i++)
        {
            int a, b, w;
            tie(a, b, w) = road[i];
            if (find(a, b) == false)
            {
                union_parent(a, b);
                ans += w;
            }
        }

        cout << total - ans << "\n";
    }
}