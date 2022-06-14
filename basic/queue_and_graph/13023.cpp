#include <iostream>
#include <vector>

using namespace std;

vector<int> friends[2000];
bool founded = false;
bool check[2000];

void find_friend(int a, int count) {
    check[a] = true;
    if (count == 4)
    {
        founded = true;
        return ;
    }
    for (int i = 0; i < friends[a].size(); i++)
    {
        if (founded) return ;
        if (check[friends[a][i]] == false)
            find_friend(friends[a][i], count + 1);
    }
    check[a] = false;
}

int main(void){
	int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            check[j] = false;
        find_friend(i, 0);
        if (founded == true)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
	return 0;
}