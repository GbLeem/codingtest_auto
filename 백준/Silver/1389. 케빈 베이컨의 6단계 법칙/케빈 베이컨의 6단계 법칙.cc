#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<int> adj[102];
int vis[102];
vector<pair<int, int>> answer;

void bfs(int cur)
{
	fill(vis, vis + n + 2, -1);
	queue<int> q;
	q.push(cur);
	vis[cur] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur])
		{
			if (vis[nxt] == -1)
			{
				q.push(nxt);
				vis[nxt] = vis[cur] + 1;
			}
		}
	}

	int temp = 0;
	for (int i = 1; i <= n; ++i)
	{
		temp += vis[i];
	}
	answer.push_back({ temp, cur });
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i)
	{
		bfs(i);
	}
	int minValue = INT_MAX;
	for (auto a : answer)
	{
		minValue = min(minValue, a.first);
	}
	int result = INT_MAX;
	for (auto a : answer)
	{
		if (a.first == minValue)
		{
			result = min(result, a.second);
		}
	}

	cout << result;
 }

