#include <iostream>
#include <queue>
using namespace std;

int r, c;
string arr[1002];
int visJ[1002][1002];
int visF[1002][1002];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	
	for (int i = 0; i < r; ++i)
	{
		cin >> arr[i];
	}
	queue<pair<int, int>> qf;
	queue<pair<int, int>> qj;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			//불 여러개?
			if (arr[i][j] == 'F')
			{
				qf.push({ i, j });
				visF[i][j] = 1;
			}
			if (arr[i][j] == 'J')
			{
				qj.push({ i, j });
				visJ[i][j] = 1;
			}
		}
	}

	while (!qf.empty())
	{		
		auto cur = qf.front();
		qf.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;

			//방문, 벽
			if (visF[nx][ny] >= 1 || arr[nx][ny] == '#')
				continue;

			visF[nx][ny] = visF[cur.first][cur.second] + 1;
			qf.push({ nx, ny });
		}		
	}

	while (!qj.empty())
	{
		auto cur = qj.front();
		qj.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			{
				cout << visJ[cur.first][cur.second];
				return 0;
			}
			if (visJ[nx][ny] >= 1 || arr[nx][ny] == '#')
				continue;
			//
			if (visF[nx][ny] >= 1 && visF[nx][ny] <= visJ[cur.first][cur.second] + 1)
				continue;
			visJ[nx][ny] = visJ[cur.first][cur.second] + 1;
			qj.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
}