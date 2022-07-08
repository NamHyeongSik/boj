#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);
    vector<int> v;
    int count = 1;
    while (!q.empty())
    {
        if (count == K)
        {
            count = 1;
            v.push_back(q.front());
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    cout << "<";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ", ";
    }
    cout << ">";
}  