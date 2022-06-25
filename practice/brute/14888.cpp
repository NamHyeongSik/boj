#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int min_a = INT_MAX, max_a = INT_MIN;
int op[4];

void DFS(vector<int> &A, int sum, int idx) {
    if (idx == N)
    {
        min_a = min(sum, min_a);
        max_a = max(sum, max_a);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (op[i] == 0)
            continue;
        if (i == 0)
            sum += A[idx];
        else if (i == 1)
            sum -= A[idx];
        else if (i == 2)
            sum *= A[idx];
        else
            sum /= A[idx];
        op[i]--;
        DFS(A, sum, idx + 1);
        op[i]++;
        if (i == 0)
            sum -= A[idx];
        else if (i == 1)
            sum += A[idx];
        else if (i == 2)
            sum /= A[idx];
        else
            sum *= A[idx];
    }
}

int main(void) {
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];

    DFS(A, A[0], 1);
    cout << max_a << "\n" << min_a;
}