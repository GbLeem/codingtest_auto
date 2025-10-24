#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int board[22][22];
int n;
int vis[22][22];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int shark_size = 2;
pair<int, int> shark_pos;
int answer = 0;
int eat = 0;
	

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 9)
			{				
				shark_pos.first = i;
				shark_pos.second = j;
				board[i][j] = 0;
			}
		}
	}

	while (1)
	{
		for (int i = 0; i < 22; ++i)
			fill(vis[i], vis[i] + 22, -1);

		queue<pair<int, int>> q;
		vector<tuple<int, int, int>> fish;

		q.push({ shark_pos.first, shark_pos.second });
		vis[shark_pos.first][shark_pos.second] = 0;

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				//방문했거나 못감
				if (vis[nx][ny] != -1 || board[nx][ny] > shark_size)
					continue;

				q.push({ nx, ny });
				vis[nx][ny] = vis[cur.first][cur.second] + 1;

				//먹을수있으면
				if (board[nx][ny] > 0 && board[nx][ny] < shark_size)
				{
					fish.push_back({ vis[nx][ny], nx, ny });
				}
			}
		}

		//종료
		if (fish.empty())
		{
			break;
		}

		//가장 가까운 놈 먹기
		sort(fish.begin(), fish.end());

		auto eat_fish = fish[0];

		answer += get<0>(eat_fish);
		eat++;
		board[get<1>(eat_fish)][get<2>(eat_fish)] = 0;
		shark_pos.first = get<1>(eat_fish);
		shark_pos.second = get<2>(eat_fish);

		if (eat == shark_size)
		{
			shark_size++;
			eat = 0;
		}
	}

	cout << answer;
}
