#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k, x;
vector<pair<int, int>>adj[300'002];
int dist[300'002];
const int INF = 1e9 + 10;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back({ 1, v });
	}

	fill(dist, dist + 300'002, INF);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	dist[x] = 0;
	pq.push({ dist[x], x });

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		if (dist[cur.second] != cur.first)
			continue;
			
		for (auto nxt : adj[cur.second])
		{
			if (dist[nxt.second] <= dist[cur.second] + nxt.first)
				continue;
			dist[nxt.second] = dist[cur.second] + nxt.first;
			pq.push({ dist[nxt.second], nxt.second });
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n; ++i)
	{
		if (dist[i] == k)
			ans.push_back(i);		
	}

	if (ans.empty())
		cout << -1;
	else
	{
		sort(ans.begin(), ans.end());
		for (const auto& a : ans)
			cout << a << "\n";
	}
}