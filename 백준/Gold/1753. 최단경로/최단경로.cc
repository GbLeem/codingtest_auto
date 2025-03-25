#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e, st;

vector<pair<int, int>> adj[20005];
const int INF = 1e9 + 10;
int dist[20005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> st;
	fill(dist, dist + v + 1, INF);

	while (e--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	//시작점 처리
	dist[st] = 0;

	//pq에 시작점 넣기
	pq.push({ dist[st], st });
	while (!pq.empty())
	{
		//w가 가장 작은 값을 cur로 설정함
		auto cur = pq.top();
		pq.pop();

		if (dist[cur.second] != cur.first)
			continue;
		for (auto nxt : adj[cur.second])
		{
			//dist에 적혀있는 값보다 새롭게 갱신할 값이 더 크면 continue;
			if (dist[nxt.second] <= dist[cur.second] + nxt.first)
				continue;
			//갱신할 값이 작은 경우 dist 업데이트
			//1 - > 2 인 경우
			//INF > 0 + 3 이므로 dist[2] = 3으로 업데이트
			dist[nxt.second] = dist[cur.second] + nxt.first;
			//업데이트 된 경우는 pq에 값 추가
			pq.push({ dist[nxt.second], nxt.second });
		}
	}
	for (int i = 1; i <= v; ++i)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}