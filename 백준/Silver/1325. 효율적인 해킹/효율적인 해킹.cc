#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[10'002];
int vis[10'002];
int depth[10'002];


void dfs(int cur)
{
	vis[cur] = 1;
	depth[cur]++;
	for (int nxt : adj[cur])
	{
		if (vis[nxt])
			continue;
		dfs(nxt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; ++i)
	{
		fill(vis +1, vis + n + 1, 0);
		dfs(i);
	}

	int answer = *max_element(depth + 1, depth + n + 1);

	for (int i = 1; i <= n; ++i)
	{
		if (answer == depth[i])
			cout << i << " ";
	}
}