#include <iostream>
#include <queue>
using namespace std;

int N, L, R;
int arr[52][52];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int answer = 0;
vector<pair<int, int>> vec; //바꿀것

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}

	while (1)
	{
		bool check = false;
		int vis[52][52] = {  };

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (vis[i][j])
					continue;

				queue<pair<int, int>> q;
				vec.clear();
				q.push({ i,j });
				vis[i][j] = 1;
				vec.push_back({ i, j });
				int temp = arr[i][j]; //합

				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if (vis[nx][ny])
							continue;

						int dist = abs(arr[cur.first][cur.second] - arr[nx][ny]);
						if (dist >= L && dist <= R)
						{
							q.push({ nx, ny });
							vis[nx][ny] = 1;
							vec.push_back({ nx, ny });
							temp += arr[nx][ny];							
						}						
					}
				}
				if (vec.size() == 1)
					continue;

				int res = temp / vec.size();
				for (auto v : vec)
				{
					arr[v.first][v.second] = res;
					check = true;
				}
			}
		}
		if (!check) //처음부터 끝까지 다돌아도 바뀐거없으면
			break;

		answer++;
		/*cout << "\n";
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}*/
	}
	cout << answer;
}