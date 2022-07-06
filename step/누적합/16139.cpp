#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    int q;
    cin >> q;

    //누적합
    int len = S.size();
    vector<vector<int>> sum(26, vector<int>(len + 1, 0));
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (S[j] == i + 'a')
                sum[i][j + 1] = 1;
            sum[i][j + 1] += sum[i][j];
        }
    }

    while (q--)
    {
        char a;
        int l, r;
        cin >> a >> l >> r;
        cout << sum[a - 'a'][r + 1] - sum[a - 'a'][l] << "\n";
    }
}