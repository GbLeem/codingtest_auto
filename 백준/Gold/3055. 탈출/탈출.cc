#include <iostream>
#include <queue>
using namespace std;

int r, c; 
string board[52];
int visw[52][52];
int viss[52][52];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int x = 0; x < r; ++x)
	{
		for (int y = 0; y < c; ++y)
		{
			visw[x][y] = -1;
			viss[x][y] = -1;
		}
	}

	for (int x = 0; x < r; ++x)
	{
		cin >> board[x];
	}
	
	queue<pair<int, int>> wq;
	queue<pair<int, int>> sq;

	for (int x = 0; x < r; ++x)
	{
		for (int y = 0; y < c; ++y)
		{
			if (board[x][y] == '*') //물
			{
				wq.push({ x, y });
				visw[x][y] = 0;
			}
			if(board[x][y] == 'S') //고슴
			{
				sq.push({ x, y });
				viss[x][y] = 0;
			}
		}
	}
	
	while (!wq.empty())
	{
		auto cur = wq.front();
		wq.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (board[nx][ny] == 'X' || board[nx][ny] == 'D' || board[nx][ny] == 'S')
				continue;
			if (visw[nx][ny] != -1)
				continue;
			wq.push({ nx, ny });
			visw[nx][ny] = visw[cur.first][cur.second] + 1;
		}
	}

	/*for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << visw[i][j] << " ";
		}
		cout << "\n";
	}*/
	while (!sq.empty())
	{
		auto cur = sq.front();
		sq.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (board[nx][ny] == 'D')
			{
				cout << viss[cur.first][cur.second] + 1;
				return 0;
			}
			if (viss[nx][ny] != -1)
				continue;
			if (board[nx][ny] == 'X')
				continue;
			if (board[nx][ny] == '*' || (visw[nx][ny] != -1 && viss[cur.first][cur.second] + 1 >= visw[nx][ny]))
				continue;

			sq.push({ nx, ny });
			viss[nx][ny] = viss[cur.first][cur.second] + 1;
		}
	}
	/*for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << viss[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << "KAKTUS";
}