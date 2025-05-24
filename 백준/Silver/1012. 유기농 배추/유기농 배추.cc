#include <iostream>
#include <queue>
using namespace std;

int t;
int m, n, k; //가로 세로 배추
//int vis[52][52];
int arr[52][52];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int T = 0; T < t; ++T)
	{		
		for (int i = 0; i < n; ++i)
			fill(arr[i], arr[i] + m, 0);

		cin >> m >> n >> k; //가로 세로

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> y >> x;

			arr[x][y] = 1;
		}

		queue<pair<int, int>> q;
		int answer = 0;

		for (int x = 0; x < n; ++x)
		{
			for (int y = 0; y < m; ++y)
			{
				//배추 시작
				if (arr[x][y] == 1)
				{
					answer++;

					q.push({ x, y });
					arr[x][y] = 2;

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
							if (arr[nx][ny] == 2 || arr[nx][ny] == 0)
								continue;

							q.push({ nx, ny });
							arr[nx][ny] = 2;
						}
					}
				}
			}
		}

		cout << answer << "\n";
	}
}