#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; i++)
        dq.push_back(i);

    int count = 0;
    while (M--)
    {
        int n;
        cin >> n;
        int left, right;
        for (int i = 0; i < dq.size(); i++)
        {
            if (n == dq[i])
            {
                left = i;
                right = dq.size() - i;
                break;
            }
        }
        if (left == 0)
            dq.pop_front();
        else if (left <= right)
        {
            while (dq.front() != n)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
            dq.pop_front();
        }
        else
        {
            count++;
            while (dq.back() != n)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
            dq.pop_back();
        }
    }
    cout << count;
}  