#include <iostream>
#include <vector>

using namespace std;

int arr[201];
int city[201][201];

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

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
        arr[i] = i;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> city[i][j];

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (city[i][j])
                union_parent(i, j);
    
    vector<int> route(M);
    for (int i = 0; i < M; i++)
        cin >> route[i];
    for (int i = 0; i < M - 1; i++)
    {
        if (!find_parent(route[i] - 1, route[i + 1] - 1))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}