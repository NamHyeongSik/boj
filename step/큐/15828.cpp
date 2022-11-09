#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    queue<int> q;
    int cap = N;
    while (1)
    {
        int n;
        cin >> n;
        if (n == -1)
            break;
        if (n == 0)
        {
            q.pop();
            cap++;
        }
        else
        {
            if (cap)
            {
                q.push(n);
                cap--;
            }
        }
    }
    if (q.empty())
        cout << "empty";
    else
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
}  