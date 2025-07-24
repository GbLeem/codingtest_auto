#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

int n, m;
int arr[10][10];
int temp[10][10];
vector<tuple<int, int, int>> pos;
vector<int> posdir;
int answer = INT_MAX;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Move(int x, int y, int dir)
{
	int nx;
	int ny;
	int cnt = 1;

	while (1)
	{
		nx = x + dx[dir] * cnt;
		ny = y + dy[dir] * cnt;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			break;
		if (temp[nx][ny] == 6) //벽이거나 cctv
			break;
		if(temp[nx][ny] == 0)
			temp[nx][ny] = -1;
		cnt++;
	}
}
void Change(int x, int y, int idx, int dir)
{
	if (idx == 1)
	{
		Move(x, y, dir);
	}
	else if (idx == 2)
	{
		Move(x, y, dir);
		Move(x, y, (dir + 2) % 4);
	}
	else if (idx == 3)
	{
		Move(x, y, dir);
		Move(x, y, (dir + 1) % 4);
	}
	else if (idx == 4)
	{
		Move(x, y, dir);
		Move(x, y, (dir + 1) % 4);
		Move(x, y, (dir + 2) % 4);
	}
	else if (idx == 5)
	{
		Move(x, y, dir);
		Move(x, y, (dir + 1) % 4);
		Move(x, y, (dir + 2) % 4);
		Move(x, y, (dir + 3) % 4);
	}
}

int Check()
{	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			temp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < posdir.size(); ++i)
	{
		Change(get<0>(pos[i]), get<1>(pos[i]), get<2>(pos[i]), posdir[i]);
	}

	int tempAns = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (temp[i][j] == 0)
				tempAns++;
		}
	}
	return tempAns;
}

void Choose(int cur)
{
	if (cur == pos.size())
	{
		answer = min(answer, Check());
		return;
	}
	//우 하 좌 상
	for (int dir = 0; dir < 4; ++dir)
	{
		posdir.push_back(dir);
		Choose(cur + 1);
		posdir.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];

			if (arr[i][j] != 0 && arr[i][j] != 6)
				pos.push_back({ i, j, arr[i][j] });
		}
	}

	Choose(0);
	
	cout << answer;
}