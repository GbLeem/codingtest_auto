#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int, int>> adj[1002];
int vis[1002];
int n, m;
int st, en;

int main()
{
	cin >> n;
	cin >> m;

	fill(vis, vis + n + 2, INT_MAX);
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	cin >> st >> en;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vis[st] = 0;

	pq.push({ vis[st], st });
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		if (vis[cur.second] != cur.first)
			continue;
		for (auto nxt : adj[cur.second])
		{
			if (vis[nxt.second] <= vis[cur.second] + nxt.first)
				continue;

			vis[nxt.second] = vis[cur.second] + nxt.first;
			pq.push({ vis[nxt.second], nxt.second });
		}
	}
	cout << vis[en];
}