#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[2002];
int vis[2002];
bool flag = false;

void dfs(int cur, int depth)
{
	if (depth == 4)
	{
		flag = true;
		return;
	}
	for (int nxt : adj[cur])
	{
		if (!vis[nxt])
		{
			vis[nxt] = 1;
			dfs(nxt, depth + 1);
			vis[nxt] = 0;
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
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i = 0; i < n; ++i)
	{		
		fill(vis, vis + n, 0);
		flag = false;
		vis[i] = 1;
		dfs(i, 0);
		//존재 하는 경우
		if (flag)
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}