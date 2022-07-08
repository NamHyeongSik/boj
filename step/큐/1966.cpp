#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        vector<int> p(N);
        vector<int> a(N);
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
            p[i] = a[i];
        }
        sort(p.rbegin(), p.rend());

        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++)
            q.push({i, a[i]});
        
        int i = 0;
        int count = 1;
        while (!q.empty() && i < N)
        {
            int index = q.front().first;
            int priority = q.front().second;
            if (index == M && priority == p[i])
            {
                cout << count << "\n";
                break;
            }
            if (priority == p[i])
            {
                i++;
                count++;
                q.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
    }
}  