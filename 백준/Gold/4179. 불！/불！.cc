#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int R, C; //세로(행) 가로(열)
string board[1002];
int dist[1002][1002];
int dist_fire[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		cin >> board[i];
		fill(dist[i], dist[i] + C, -1);
		fill(dist_fire[i], dist_fire[i] + C, -1);
	}
	queue<pair<int, int>> Q;
	queue<pair<int, int>> Q_fire;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (board[i][j] == 'F')
			{
				Q_fire.push({ i, j });
				dist_fire[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				Q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}

	//불은 지훈이에 대해 영향 안받아서 먼저 돌려버려도 ok
	while (!Q_fire.empty())
	{
		auto cur = Q_fire.front();
		Q_fire.pop();
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (dist_fire[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			dist_fire[nx][ny] = dist_fire[cur.first][cur.second] + 1;
			Q_fire.push({ nx, ny });
		}
	}

	//지훈이는 불에 영향 받음
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) //성공
			{
				cout << dist[cur.first][cur.second] + 1;
				return 0;
			}
			if (dist[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			if (dist_fire[nx][ny] != -1 && dist_fire[nx][ny] <= dist[cur.first][cur.second] + 1)
				continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
}