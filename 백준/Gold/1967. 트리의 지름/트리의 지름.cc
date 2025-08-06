#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> adj[10002];
bool vis[10002];
int ans;
int node;

void dfs(int cur, int dist)
{
	if (ans < dist)
	{
		node = cur;
		ans = dist;
	}
	for (auto [n, d] : adj[cur])
	{
		if (vis[n])
			continue;
		vis[n] = 1;
		dfs(n, dist + d);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n - 1 ; ++i)
	{
		int p, c, d;
		cin >> p >> c >> d;
		adj[p].push_back({ c,d });
		adj[c].push_back({ p,d });
	}
	//1에서 시작해서 dfs 도착에서 다시 반대로 dfs
	vis[1] = 1;
	dfs(1, 0);
	fill(vis, vis + 10002, 0);
	vis[node] = 1;
	dfs(node, 0);
	cout << ans;
}