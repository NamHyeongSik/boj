#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool check[1001];

void BFS(int u) {
    check[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int crnt = q.front();
        q.pop();
        for (int i = 0; i < graph[crnt].size(); i++)
        {
            if (check[graph[crnt][i]] == false)
            {
                check[graph[crnt][i]] = true;
                q.push(graph[crnt][i]);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (check[i] == false)
        {
            BFS(i);
            ans++;
        }
    }
    cout << ans;
	return 0;
}