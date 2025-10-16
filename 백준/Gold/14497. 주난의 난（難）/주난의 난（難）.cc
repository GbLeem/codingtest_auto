#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int X1, Y1, X2, Y2;
string board[302];
int vis[302][302];
int answer = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> X1 >> Y1 >> X2 >> Y2;

	X1 -= 1;
	Y1 -= 1;
	X2 -= 1;
	Y2 -= 1;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}
	
	while (1)
	{
		queue<pair<int, int>> q;
		vector<pair<int, int>> vec;
		for (int i = 0; i < 302; ++i)
			fill(vis[i], vis[i] + 302, 0);

		q.push({ X1, Y1});
		vis[X1][Y1] = 1;
		answer++;

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
				if (nx == X2 && ny == Y2)
				{
					cout << answer;
					return 0;
				}
				if (board[nx][ny] == '1')
				{
					vec.push_back({ nx, ny });
				}
				else
				{
					q.push({ nx, ny });
				}
			}
		}
		for (const auto& v : vec)
		{
			board[v.first][v.second] = '0';
		}
	}
}