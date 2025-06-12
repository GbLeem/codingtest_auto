#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
int arr[12][12];
int isused[102];
vector<pair<int, int>> ans;
int answer = INT_MAX;

int dx[5] = {0, 1, 0, -1, 0 };
int dy[5] = {0, 0, 1, 0, -1 };

int Check()
{
	int temp[12][12] = {};
	int tempCost = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int dir = 0; dir < 5; ++dir)
		{
			int nx = ans[i].first + dx[dir];
			int ny = ans[i].second + dy[dir];

			//이미 꽃 있는 경우
			if (temp[nx][ny] == 1)
				return INT_MAX;
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				return INT_MAX;

			temp[nx][ny] = 1;
			tempCost += arr[nx][ny];
		}
	}
	return tempCost;
}

void Choose(int cur)
{
	if (cur == 3)
	{
		answer = min(Check(), answer);
		return;
	}

	for (int i = 0; i < N * N; ++i)
	{
		int nx = i / N;
		int ny = i % N;

		if (nx > 0 && nx < N- 1 && ny > 0 && ny < N - 1)
		{
			if (!isused[i])
			{
				ans.push_back({ nx, ny });
				isused[i] = 1;
				Choose(cur + 1);
				ans.pop_back();
				isused[i] = 0;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}

	Choose(0);

	cout << answer;
}