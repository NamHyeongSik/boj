#include <iostream>
#include <vector>

using namespace std;

int N;

typedef struct node {
    int left;
    int right;
} t_node;

t_node Node[26];

void preorder(int n) {
    cout << (char)(n + 'A');
    if (Node[n].left != -1)
        preorder(Node[n].left);
    if (Node[n].right != -1)
        preorder(Node[n].right);
}

void inorder(int n) {
    if (Node[n].left != -1)
        inorder(Node[n].left);
    cout << (char)(n + 'A');
    if (Node[n].right != -1)
        inorder(Node[n].right);
}

void postorder(int n) {
    if (Node[n].left != -1)
        postorder(Node[n].left);
    if (Node[n].right != -1)
        postorder(Node[n].right);
    cout << (char)(n + 'A');
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        Node[i].left = Node[i].right = -1;

    for (int i = 0; i < N; i++)
    {
        char p, l ,r;
        cin >> p >> l >> r;
        p -= 'A';
        if (l != '.')
            Node[p].left = l - 'A';
        if (r != '.')
            Node[p].right = r - 'A';
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
}