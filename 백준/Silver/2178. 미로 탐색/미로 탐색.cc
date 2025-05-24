#include <iostream>
#include <queue>
using namespace std;

int n, m;
string arr[102];
int vis[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int r = 0; r < n; ++r)
	{		
		cin >> arr[r];
	}

	queue<pair<int, int>> q;
	vis[0][0] = 1;
	q.push({ 0,0 });

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
			if (arr[nx][ny] == '0')
				continue;
			if (vis[nx][ny] > 0)
				continue;

			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
	cout << vis[n - 1][m - 1];
}