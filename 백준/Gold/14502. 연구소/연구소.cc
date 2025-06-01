#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int arr[8][8];

vector<int> ans;
int used[65];

int dx[4] = { 1, 0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int answer = -1;

int bfs()
{
	int vis[8][8] = {};
	int temp[8][8];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			temp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		int x = ans[i] / m;
		int y = ans[i] % m;

		temp[x][y] = 1;
	}

	queue<pair<int, int>>q;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			//바이러스면
			if (temp[i][j] == 2)
			{
				q.push({ i,j });		
				vis[i][j] = 1;

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
						//벽이거나 바이러스면 넘겨
						if (temp[nx][ny] >= 1)
							continue;
						//방문했으면
						if (vis[nx][ny] == 1)
							continue;
						q.push({ nx,ny });
						temp[nx][ny] = 2;
						vis[nx][ny] = 1;
					}
				}
			}
		}
	}

	int tempAnswer = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (temp[i][j] == 0)
				tempAnswer++;
		}
	}
	return tempAnswer;
}

void Choose(int cur)
{
	if (cur == 3)
	{
		answer = max(bfs(), answer);
		return;
	}

	for (int i = 0; i < n * m; ++i)
	{
		if (!used[i])
		{
			int x = i / m;
			int y = i % m;

			//빈 공간인 경우
			if (arr[x][y] == 0)
			{
				ans.push_back(i);
				used[i] = 1;
				Choose(cur + 1);
				ans.pop_back();
				used[i] = 0;
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m; //세로 가로

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
		}
	}

	//0인 곳을 3개 골라서 벽으로 만들고
	//bfs 돌리기
	Choose(0);

	cout << answer;
}