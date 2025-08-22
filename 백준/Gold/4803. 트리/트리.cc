#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = -1;
int m = -1;
vector<int> adj[502];
int p[502];
int vis[502];
int answer = 0;
int tree = 0;

void dfs(int cur)
{
	for (int nxt : adj[cur])
	{
		if (p[cur] == nxt)
			continue;
		p[nxt] = cur;
		dfs(nxt);
	}

}

void bfs(int cur)
{
	queue<int> q;
	q.push(cur);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur])
		{
			if (p[cur] == nxt)
				continue;
			if (vis[nxt])
			{
				tree = false;
				continue;
			}
			p[nxt] = cur;
			vis[nxt] = 1;
			q.push(nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int idx = 1;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;

		fill(vis, vis + 502, 0);
		fill(p, p + 502, 0);

		for (int i = 1; i <= n; ++i)
			adj[i].clear();

		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		answer = 0;

		for (int i = 1; i <= n; ++i)
		{
			if (vis[i])
				continue;
			vis[i] = 1;
			tree = true;
			bfs(i);
			answer += tree;
		}

		cout << "Case " << idx++ << ": ";
		if (answer == 0)
			cout << "No trees.\n";
		else if (answer == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << answer << " trees.\n";
	}
}