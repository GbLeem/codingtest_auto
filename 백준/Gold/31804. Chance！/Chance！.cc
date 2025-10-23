#include <iostream>
#include <queue>
using namespace std;

int a, b;
int dist[1'000'002][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;

	//+1, *2, *10
	for (int i = 0; i < 1'000'002; ++i)
		fill(dist[i], dist[i] + 2, -1);
	
	queue<pair<int,int>> q;

	q.push({ a, 0 });
	dist[a][0] = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int nxt : {cur.first + 1, cur.first * 2})
		{
			if (nxt <= b && dist[nxt][cur.second] == -1)
			{
				dist[nxt][cur.second] = dist[cur.first][cur.second] + 1;
				q.push({ nxt, cur.second});
			}			
		}
		if (cur.second == 0)
		{
			int nxt = cur.first * 10;
			
			if (nxt <= b && dist[nxt][1] == -1)
			{
				dist[nxt][1] = dist[cur.first][0] + 1;
				q.push({ nxt, 1 });
			}			
		}
	}

	if (dist[b][0] == -1)
		cout << dist[b][1];
	else if (dist[b][1] == -1)
		cout << dist[b][0];
	else
		cout << min(dist[b][0], dist[b][1]);
	
}