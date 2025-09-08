#include <iostream>
#include <string>
#include <queue>
using namespace std;

string board[13];
int vis[13][7];
int answer = 0;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void print()
{
	for (int x = 0; x < 12; ++x)
	{
		for (int y = 0; y < 6; ++y)
		{
			cout << board[x][y];
		}
		cout << "\n";
	}
}
bool bfs(int x, int y)
{
	for (int i = 0; i < 13; ++i)
		fill(vis[i], vis[i] + 7, 0);
	queue<pair<int,int>> q;
	vector<pair<int, int>> same;
	
	q.push({ x, y });
	same.push_back({ x,y });
	char color = board[x][y];
	vis[x][y] = 1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
				continue;
			if ((board[nx][ny] == color && vis[nx][ny]) || board[nx][ny] != color)
				continue;

			q.push({ nx,ny });
			same.push_back({ nx, ny });
			vis[nx][ny] = 1;
		}		
	}
	if (same.size() >= 4)
	{
		for (const auto& s : same)
		{
			board[s.first][s.second] = '.';
		}
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; ++i)
	{
		cin >> board[i];
	}

	while (1)
	{
		bool flag = false;

		for (int x = 0; x < 12; ++x)
		{
			for (int y = 0; y < 6; ++y)
			{
				if (board[x][y] != '.')
				{
					if (bfs(x, y))
						flag = true;
				}
			}
		}

		//한바퀴 다 돌았음
		if (flag)
		{
			answer++;

			for (int y = 0; y < 6; ++y)
			{
				vector<char>temp;
				for (int x = 11; x >= 0; --x)
				{
					if (board[x][y] != '.')
						temp.push_back(board[x][y]);
				}
				for (int x = 0; x < 12; ++x)
					board[x][y] = '.';

				int idx = 11;
				for (const auto& t : temp)
				{
					board[idx][y] = t;
					idx--;
				}
			}
		}		
		else
			break;
	}

	cout << answer;
}

