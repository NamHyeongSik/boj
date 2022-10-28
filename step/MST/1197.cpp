#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int arr[10001];

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
    int V, E;
    cin >> V >> E;
    for (int i = 1; i <= V; i++)
        arr[i] = i;

    long long sum = 0;
    vector<tuple<int, int ,int>> v;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    sort(v.begin(), v.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
        if (get<2>(a) < get<2>(b))
            return true;
        return false;
    });

    for (int i = 0; i < v.size(); i++)
    {
        int x, y, w;
        
        tie(x, y, w) = v[i];
        if (!find(x, y))
        {
            union_parent(x, y);
            sum += w;
        }
    }
    cout << sum;
}