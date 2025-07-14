#include <iostream>
#include <queue>
using namespace std;

int dx[8] = { 1,0,-1,0,1,1,-1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,1,-1 };

int w, h;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		int board[52][52] = {};
		int vis[52][52] = {};
		int cnt = 0;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (board[i][j] == 1 && !vis[i][j])
				{
					queue<pair<int, int>>q;
					vis[i][j] = 1;
					q.push({ i, j });
					cnt++;

					while (!q.empty())
					{
						auto cur = q.front();
						q.pop();

						for (int dir = 0; dir < 8; ++dir)
						{
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= h || ny < 0 || ny >= w)
								continue;
							if (vis[nx][ny] == 1 || board[nx][ny] == 0)
								continue;
							q.push({ nx, ny });
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
		cout << cnt << "\n";
	}
}