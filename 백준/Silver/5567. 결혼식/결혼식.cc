#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[502];
int vis[502];
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int>q;
	q.push(1);
	vis[1] = 1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int nxt : adj[cur])
		{
			if (!vis[nxt])
			{
				vis[nxt] = 1;
				answer++;
				if(cur == 1)
					q.push(nxt);
			}
		}
	}

	cout << answer;
}