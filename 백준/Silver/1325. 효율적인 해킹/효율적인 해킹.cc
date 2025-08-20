#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[10'002];
bool vis[10'002];
int cnt = 0;
vector<int> ans;
int maxCnt = -1;

void dfs(int cur)
{
	vis[cur] = 1;

	for (int nxt : adj[cur])
	{
		if (!vis[nxt])
		{
			cnt++;
			dfs(nxt);
		}
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
		//adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
	{
		fill(vis, vis + 10'002, 0);
		cnt = 0;
		dfs(i);
		if (maxCnt < cnt)
		{
			ans.clear();
			ans.push_back(i);
			maxCnt = cnt;
		}
		else if (maxCnt == cnt)
		{
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());
	for (const auto& a : ans)
	{
		cout << a << " ";
	}
}