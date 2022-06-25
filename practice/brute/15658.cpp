#include <iostream>
#include <vector>

using namespace std;

int N;
int A[12];
int op[4];
int max_ans = -10e9, min_ans = 10e9;

int cal(int a, int b, int op) {
    switch (op)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return a / b;
    default:
        break;
    }
}

void DFS(int idx, int num) {
    if (idx == N)
    {
        max_ans = max(max_ans, num);
        min_ans = min(min_ans, num);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (op[i] == 0) continue;
        op[i]--;
        DFS(idx + 1, cal(num, A[idx + 1], i));
        op[i]++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    DFS(1, A[1]);
    cout << max_ans << "\n" << min_ans;
}