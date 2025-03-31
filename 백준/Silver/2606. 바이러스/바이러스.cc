#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[105];
bool vis[105];
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	while (m--)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cnt = 0;

	queue<int>q;
	vis[1] = true;
	q.push(1);	

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (const auto nxt : adj[cur])
		{
			if (vis[nxt])
				continue;
			q.push(nxt);
			vis[nxt] = true;
			cnt++;
		}
	}
	
	cout << cnt;
}