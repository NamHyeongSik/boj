#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @brief FAIL
 * 
 * 두 집합을 합칠때 각 집합의 원소수를 합치도록 합니다.
 * 또한 숫자일때는 더 작은 값을 기준으로 저장했지만, 이 경우에는 단순 한방향으로만 저장합니다.
 * 그렇기 때문에 연결된 친구의 수를 세어줄 때 기준이 되는 이름으로 찾아주면 됩니다.
 * 만약 두 부모가 같으면 이미 연결 되어있는 상태이기 때문에 아무것도 진행하지 않도록 해주었습니다.
 * 
 */

unordered_map<string, string> um;
unordered_map<string, int> network;

string get_parent(string x) {
    if (um[x] == x) return x;
    else return um[x] = get_parent(um[x]);
}

void union_parent(string a, string b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a == b) return ;
    um[b] = a;
    network[a] += network[b];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, F;
    cin >> T;
    while (T--)
    {
        cin >> F;
        um.clear();
        network.clear();
        for (int i = 0; i < F; i++)
        {
            string a, b;
            cin >> a >> b;
            if (um[a].empty())
            {
                um[a] = a;
                network[a] = 1;
            }
            if (um[b].empty())
            {
                um[b] = b;
                network[b] = 1;
            }
            union_parent(a, b);
            cout << network[get_parent(a)] << "\n";
        }
    }
}