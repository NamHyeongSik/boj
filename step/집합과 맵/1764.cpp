#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    unordered_set<string> us;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        us.insert(tmp);
    }
    int count = 0;
    set<string> ans;
    for (int i = 0; i < M; i++)
    {
        string tmp;
        cin >> tmp;
        if (us.find(tmp) != us.end())
        {
            count++;
            ans.insert(tmp);
        }
    }
    cout << count << "\n";
    for (string s : ans)
        cout << s << "\n";
}