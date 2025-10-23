#include <iostream>
#include <queue>
using namespace std;

int r, c;
string board[1502];
int vis[1502][1502];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

pair<int, int> st = { -1, -1 };
pair<int, int> en;

queue<pair<int, int>> water;
queue<pair<int, int>> swan;

int answer = 0;

bool Check()
{
	queue<pair<int, int>> next_swan;

	while (!swan.empty())
	{
		auto cur = swan.front();
		swan.pop();
		
		if (cur.first == en.first && cur.second == en.second)
			return true;

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];;

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (vis[nx][ny] == 1)
				continue;
			vis[nx][ny] = 1;
			if (board[nx][ny] == 'X')
				next_swan.push({ nx, ny });
			else
				swan.push({ nx, ny });
		}
	}
	swan = next_swan;
	return false;
}

void melt()
{
	int water_size = water.size();
	while (water_size--)
	{
		auto cur = water.front();
		water.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;

			//얼음이면 
			if (board[nx][ny] == 'X')
			{
				//물로만들기
				board[nx][ny] = '.';
				water.push({ nx, ny });
			}
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
		cin >> board[i];
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			//백조
			if (board[i][j] == 'L')
			{
				if (st.first == -1)
					st = { i, j };
				else
					en = { i, j };
				board[i][j] = '.';
			}
			if(board[i][j] == '.')
			{
				water.push({ i, j });
			}
		}
	}

	swan.push({ st.first, st.second });
	vis[st.first][st.second] = 1;

	while (1)
	{
		if (Check())
		{
			cout << answer;
			break;
		}
		melt();
		answer++;
	}
}