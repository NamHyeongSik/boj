#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
        }
        cout << N - 1 << "\n";
    }
}