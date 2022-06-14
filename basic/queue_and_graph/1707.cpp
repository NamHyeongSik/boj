#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//https://hongjw1938.tistory.com/117 -> 이분탐색
void BFS(int start, vector<int> *graph, int *color, bool *is_bipartite) {
	queue<int> q;
	color[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int crnt = q.front();
		q.pop();
		for (int next : graph[crnt]) {
			if (color[next] == 0) {
				color[next] = color[crnt] * -1;
				q.push(next);
			}
			else if (color[next] == color[crnt]) {
				*is_bipartite = false;
				return ;
			}
		}
	}
}

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int k;
	cin >> k;
	while (k--)
	{
		int V, E;
		cin >> V >> E;

		vector<int> graph[20001];
		int color[20001] = {0, };

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		bool is_bipartite = true;
		for (int i = 1; i <= V; i++)
		{
			if (is_bipartite == false) break;
			if (color[i] == 0)
				BFS(i, graph, color, &is_bipartite);
		}
		if (is_bipartite == false)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
    
	return 0;
}