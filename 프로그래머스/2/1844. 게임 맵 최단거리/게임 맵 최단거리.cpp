#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>>map;
int vis[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int solution(vector<vector<int>>maps)
{
	int n = maps.size(); //x
	int m = maps[0].size();//y

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			vis[i][j] = -1;
		}
	}

	queue<pair<int, int>> q;
	q.push({0, 0});
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
            if (maps[nx][ny] == 0)
                continue;
            if(vis[nx][ny] >= 0)
                continue;
			q.push({ nx, ny });
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
		}
	}

	return vis[n-1][m-1];
}