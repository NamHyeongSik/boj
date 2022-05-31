#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
bool check[15];

bool is_password(string tmp) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u')
            a++;
        else
            b++;
    }
    if (a >= 1 && b >= 2)
        return true;
    return false;
}

void DFS(int idx, vector<string> &words, string ans)
{
    if (ans.size() == L)
    {
        if (is_password(ans))
            cout << ans << "\n";
        return;
    }
    if (idx == words.size())
        return;
    ans += words[idx];
    DFS(idx + 1, words, ans);
    ans.pop_back();
    DFS(idx + 1, words, ans);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;
    vector<string> words;
    for (int i = 0; i < C; i++)
    {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);
    }
    sort(words.begin(), words.end());
    DFS(0, words, "");
}