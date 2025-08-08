#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, m, x;
vector<pair<int, int>> adj[1002];
int dist[1002];
int answer[1002];

//min(n에서 x로 + x에서 n으로) 의 최대 값

int D(int i, int j) //st, en
{
	fill(dist, dist + 1002, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[i] = 0;

	pq.push({ dist[i], i });
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
	return dist[j];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;
	fill(answer, answer + 1002, INT_MAX);

	for (int i = 0; i < m; ++i)
	{
		int u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back({ t, v });
	}

	//n에서 시작
	for (int i = 1; i <= n; ++i)
	{
		answer[i] = D(i, x) + D(x, i);
	}	
	cout << *max_element(answer + 1, answer + n + 1);
}