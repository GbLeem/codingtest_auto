#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, k;
int dist[2][500'002]; //짝홀, 위치
//반복하는 거 가능하니까

void bfs()
{
	for (int i = 0; i < 2; ++i)
		fill(dist[i], dist[i] + 500'002, -1);

	queue<pair<int, int>> q; //위치, 시간
	q.push({ n ,0 });
	dist[0][n] = 0;

	while (!q.empty())
	{
		int time, pos;
		tie(pos, time) = q.front();
		q.pop();

		int nxt_time = time + 1;
		int nxt_oe = nxt_time % 2;

		for (int nxt : {pos * 2, pos + 1, pos - 1})
		{
			if (nxt < 0 || nxt > 500'000)
				continue;
			if (dist[nxt_oe][nxt] == -1)
			{
				dist[nxt_oe][nxt] = nxt_time;
				q.push({ nxt, nxt_time });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	bfs();

	int time = 0;
	while (1)
	{
		//time일때 위치 찾기
		int pos = k + time * (time + 1) / 2;

		if (pos > 500'000)
		{
			cout << -1;
			return 0;
		}

		int temp = time % 2;
		if (dist[temp][pos] != -1 && dist[temp][pos] <= time)
		{
			cout << time;
			return 0;
		}
		time++;
	}
}