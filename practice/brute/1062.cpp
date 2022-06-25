#include <iostream>
#include <vector>

using namespace std;

int N, K;
bool check[26];
int ans = 0;

void DFS(int idx, int count, vector<string> &word) {
    if (count == K - 5)
    {
        int tmp = 0;
        for (string s : word) {
            bool can_read = true;
            for (int i = 4; i < s.size() - 4; i++) {
                if (check[s[i] - 'a']) continue;
                can_read = false;
                break;
            }
            if (can_read)
                tmp++;
        }
        ans = max(ans, tmp);
        return ;
    }
    for (int i = idx; i < 26; i++)
    {
        if (check[i]) continue;
        check[i] = true;
        DFS(i, count + 1, word);
        check[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    vector<string> word(N);
    for (int i = 0; i < N; i++)
        cin >> word[i];
    if (K < 5)
        cout << 0;
    else
    {
        for (int w : {'a', 'n', 't', 'i', 'c'})
            check[w - 'a'] = true;
        DFS(0, 0, word);
        cout << ans;
    }
}
