#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[32'010];
int deg[32'010];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> answer;

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
		deg[b]++;
	}

	for (int i = 1; i <= n; ++i)
	{
		//조건없는 애들
		if (deg[i] == 0)
			pq.push(i);
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();

		answer.push_back(cur);

		for (int nxt : adj[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0)
				pq.push(nxt);
		}
	}
	for (const auto& a : answer)
	{
		cout << a << " ";
	}
}