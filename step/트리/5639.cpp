#include <iostream>
#include <vector>

/**
 * @brief FAIL
 * 
 * 재귀로 참 못짠다... 어디가 root고 어디가 left고 어디가 right인줄 알면 접근하기 쉬움
 * 
 */

using namespace std;

int node[10001];

void postorder(int root, int n) {
    if (root >= n) return;
    if (root == n - 1)
    {
        cout << node[root] << "\n";
        return;
    }
    
    int next = root + 1;
    while (next < n)
    {
        if (node[next] > node[root])
            break;
        next++;
    }
    postorder(root + 1, next);
    postorder(next, n);
    cout << node[root] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n = -1;
    while (cin >> node[++n])
        ;
    postorder(0, n);
}