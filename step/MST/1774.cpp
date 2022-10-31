#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
vector<tuple<int, int, double>> v;
vector<pair<int, int>> tmp;
set<pair<int, int>> s;
int arr[1001];

double get_distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int get_parent(int x) {
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
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        tmp.push_back({x, y});
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        s.insert({x - 1, y - 1});
    }

    for (int i = 0; i < n; i++)
    {
        int x1 = tmp[i].first;
        int y1 = tmp[i].second;
        for (int j = i + 1; j < n; j++)
        {
            int x2 = tmp[j].first;
            int y2 = tmp[j].second;
            if (s.find({i, j}) != s.end() || s.find({j, i}) != s.end())
                v.push_back({i, j, 0});
            else
                v.push_back({i, j, get_distance(x1, y1, x2, y2)});
        }
    }

    for (int i = 0; i < n; i++)
        arr[i] = i;

    sort(v.begin(), v.end(), [](tuple<int, int, double> &a, tuple<int, int, double> &b) {
        if (get<2>(a) < get<2>(b))
            return true;
        return false;
    });

    double sum = 0.0;

    for (int i = 0; i < v.size(); i++)
    {
        int x, y;
        double w;
        tie(x, y, w) = v[i];
        if (!find(x, y))
        {
            union_parent(x, y);
            sum += w;
        }
    }
    printf("%.2f\n", sum);
}