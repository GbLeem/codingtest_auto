#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[102][102];
int vis[102][102];
int answer = 0;
int cnt = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	while (1)
	{
		for (int i = 0; i < 102; ++i)
			fill(vis[i], vis[i] + 102, 0);
		vector<pair<int, int>> vec;
		queue<pair<int, int>> q;

		q.push({ 0,0 });
		vis[0][0] = 1;

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (vis[nx][ny])
					continue;
				vis[nx][ny] = 1;
				if (board[nx][ny] == 0)
					q.push({ nx, ny });
				else
					vec.push_back({ nx, ny });
			}
		}
		if (vec.empty())
			break;

		cnt = vec.size();
		for (const auto& v : vec)
		{
			board[v.first][v.second] = 0;
		}
		answer++;
	}
	cout << answer;
	cout << '\n' << cnt;
}
