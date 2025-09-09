#include <iostream>
using namespace std;

int n, m;
int board[52][52];
int d;
int stX, stY;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int answer = 0;

void clean(int x, int y)
{
	if (board[x][y] == 0)
	{
		board[x][y] = 2;
		answer++;
	}
}

bool find(int x, int y)
{
	for (int dir = 0; dir < 4; ++dir)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		//청소 가능
		if (board[nx][ny] == 0)
			return true;
	}
	return false;
}

void forward(int x, int y, int d)
{
	int nx = x + dx[d];
	int ny = y + dy[d];

	if (nx >= 0 && nx < n && ny >= 0 && ny < m)
	{
		if (board[nx][ny] == 0)
		{
			stX = nx;
			stY = ny;
		}
	}
}
bool backward(int x, int y, int d)
{
	int nx = x - dx[d];
	int ny = y - dy[d];

	if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		return false;
	if (board[nx][ny] == 1)
		return false;

	stX = nx;
	stY = ny;

	return true;		
}

void step()
{
	while (1)
	{
		clean(stX, stY);
	
		if (find(stX, stY)) //빈칸 있음
		{
			//회전
			d -= 1;
			d += 4;
			d %= 4;

			forward(stX, stY, d);
		}
		else //빈칸 없음
		{
			if (!backward(stX, stY, d))
			{
				break;
			}
		}
	}
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	cin >> stX >> stY >> d;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	step();
}
