#include <iostream>
#include <unordered_map>
using namespace std;

int r, c;
char board[22][22];
bool vis[28];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int answer = 0;

void dfs(int x, int y, int cnt)
{
	answer = max(answer, cnt);

	for (int dir = 0; dir < 4; ++dir)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;

		if (!vis[board[nx][ny] -'A'])
		{
			vis[board[nx][ny]-'A'] = 1;
			dfs(nx, ny, cnt + 1);
			vis[board[nx][ny]-'A'] = 0;
		}

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> board[i][j];
		}
	}

	vis[board[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << answer;
}