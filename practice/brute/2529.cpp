#include <iostream>

using namespace std;

int k;
char op[10];
int arr[10];
bool check[10];
long long max_ans = 0;
long long min_ans = 9876543210;

void DFS(int idx, int num) {
    arr[idx] = num;
    if (idx == k)
    {
        long long tmp = 0;
        for (int i = 0; i <= k; i++)
            tmp = tmp * 10 + arr[i];
        max_ans = max(max_ans, tmp);
        min_ans = min(min_ans, tmp);
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (check[i]) continue;
        if ((op[idx] == '<' && arr[idx] < i) || (op[idx] == '>' && arr[idx] > i))
        {
            check[i] = true;
            DFS(idx + 1, i);
            check[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> op[i];
    for (int i = 0; i < 10; i++)
    {
        check[i] = true;
        DFS(0, i);
        check[i] = false;
    }

    string max_str = to_string(max_ans);
    string min_str = to_string(min_ans);
    if (max_str.size() != k + 1)
        cout << "0" + max_str << "\n";
    else
        cout << max_str << "\n";
    if (min_str.size() != k + 1)
        cout << "0" + min_str;
    else
        cout << min_str;
}