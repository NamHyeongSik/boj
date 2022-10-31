#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<tuple<int, int, float>> v;
vector<pair<float, float>> tmp;
int arr[101];

float get_distance(float x1, float y1, float x2, float y2)
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        float x, y;
        cin >> x >> y;
        tmp.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
    {
        float x1 = tmp[i].first;
        float y1 = tmp[i].second;
        for (int j = i + 1; j < n; j++)
        {
            float x2 = tmp[j].first;
            float y2 = tmp[j].second;
            v.push_back({i, j, get_distance(x1, y1, x2, y2)});
        }
    }

    for (int i = 0; i < n; i++)
        arr[i] = i;

    sort(v.begin(), v.end(), [](tuple<int, int, float> &a, tuple<int, int, float> &b) {
        if (get<2>(a) < get<2>(b))
            return true;
        return false;
    });

    float sum = 0.0;

    for (int i = 0; i < v.size(); i++)
    {
        int x, y;
        float w;
        tie(x, y, w) = v[i];
        if (!find(x, y))
        {
            union_parent(x, y);
            sum += w;
        }
    }
    printf("%.2f\n", sum);
}