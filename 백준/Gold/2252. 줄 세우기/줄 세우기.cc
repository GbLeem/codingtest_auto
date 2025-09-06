#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[32'002];
int deg[32'002];
vector<int> answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;


	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); //a가 b앞
		deg[b]++; //b는 a가 필요해
	}
	queue<int>q;
	for (int i = 1; i <= n; ++i)
	{
		if (deg[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		answer.push_back(cur);

		for (int nxt : adj[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0)
				q.push(nxt);
		}
	}

	for (const auto& a : answer)
	{
		cout << a << " ";
	}
}
