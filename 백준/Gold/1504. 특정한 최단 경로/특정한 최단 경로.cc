#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[802];
const int INF = 1e9/3;
int dist[802];
int n, e;
int v1, v2;
int answer1 = 0;
int answer2 = 0;

void Dijk(int st)
{
	fill(dist, dist + n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	dist[st] = 0;
	pq.push({ dist[st], st });

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
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;

	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });		
	}
	cin >> v1 >> v2;

	//
	Dijk(1);		
	answer1 += dist[v1];
	Dijk(v1);
	answer1 += dist[v2];
	Dijk(v2);
	answer1 += dist[n];

	Dijk(1);
	answer2 += dist[v2];
	Dijk(v2);
	answer2 += dist[v1];
	Dijk(v1);
	answer2 += dist[n];

	int ans = min(answer1, answer2);
	if (ans >= INF)
		cout << -1;
	else
		cout << ans;
}