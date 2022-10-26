#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];

int get_parent(int x) {
    if (arr[x] == x) return x;
    else return arr[x] = get_parent(arr[x]);
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

bool find_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a == b)
        return true;
    else
        return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i <= n; i++)
        arr[i] = i;
    while (m--)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 0)
        {
            union_parent(a, b);
        }
        else
        {
            if (find_parent(a, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}