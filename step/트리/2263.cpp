#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief FAIL
 * 
 * 그림을 그려보면서 분할정복으로 풀어보면 좋습니다.
 * postorder에서 알 수 있는것은 맨 마지막 노드가 무조건 root라는것!
 * 거기서 알아낸 root로 inorder에서 left와 right 서브 트리로 분할하여 문제를 풀면 됨
 * 
 */

#define MAX 100001

int N;

int inorder[MAX];
int postorder[MAX];
int idx[MAX];

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd];
    cout << root << " ";
    // left
    preorder(inStart, idx[root] - 1, postStart, postStart + idx[root] - inStart - 1);
    // right
    preorder(idx[root] + 1, inEnd, postStart + idx[root] - inStart, postEnd - 1);

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 0; i < N; i++)
        cin >> postorder[i];

    preorder(0, N - 1, 0, N - 1);
}