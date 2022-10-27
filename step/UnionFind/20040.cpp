#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[500001];

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
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        arr[i] = i;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (!find(x, y))
            union_parent(x, y);
        else if (ans == 0)
            ans = i + 1;
    }
    cout << ans;
}