#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    unordered_map<string, int> by_name;
    unordered_map<int, string> by_number;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;

        by_name[name] = i + 1;
        by_number[i + 1] = name;
    }
    for (int i = 0; i < M; i++)
    {
        string ans;
        cin >> ans;
        int n = 0;
        if (ans[0] >= '1' && ans[0] <= '9')
            n = stoi(ans);
        if (n)
            cout << by_number[n] << "\n";
        else
            cout << by_name[ans] << "\n";
    }
}