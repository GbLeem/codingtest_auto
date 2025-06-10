#include <iostream>
#include <queue>
using namespace std;

int n, m; // 세로 가로
string board[52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int answer = -1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 'L')
			{
				int temp = -1;

				int vis[52][52] = { };
				queue<pair<int, int>> q;
				q.push({ i, j });
				vis[i][j] = 1;
				
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
						//방문했거나
						if (vis[nx][ny] != 0 || board[nx][ny] == 'W')
							continue;

						q.push({ nx, ny });
						vis[nx][ny] = vis[cur.first][cur.second] + 1;
						temp = max(temp, vis[nx][ny]);
					}
				}
				answer = max(answer, temp - 1);
			}
		}
	}
	cout << answer;
}