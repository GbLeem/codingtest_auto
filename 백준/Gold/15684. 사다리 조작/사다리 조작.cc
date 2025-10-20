#include <iostream>
#include <vector>
using namespace std;

int n, m, h;
int board[32][12]; // h n (행, 열)
vector<int> ans;
int answer = -1;

bool Check()
{
	for (int i = 1; i <= n; ++i) // 사다리 타기(열 잡고 시작)
	{
		int curC = i;

		for (int j = 1; j <= h; ++j)
		{
			if (curC < n && board[j][curC] == 1)
				curC += 1;
			else if (curC > 1 && board[j][curC - 1] == 1)
				curC -= 1;
		}

		if (curC != i)
			return false;
	}
	return true;
}

bool dfs(int cnt, int cur, int st)
{
	//cnt개 뽑기
	if (cnt == cur)
	{
		if (Check())
			return true;
		else
			return false;
	}

	for (int i = st; i <= h; ++i) //행
	{
		for (int j = 1; j <= n ; ++j) //열
		{
			//이미 있음
			if (board[i][j] == 1)
				continue;
			//왼쪽 연속
			if (j > 1 && board[i][j - 1] == 1)
				continue;
			//오른 연속
			if (j < n - 1 && board[i][j + 1] == 1)
				continue;

			board[i][j] = 1;

			if (dfs(cnt, cur + 1, i))
			{
				return true;
			}
			board[i][j] = 0;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n >> m >> h;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		board[a][b] = 1; // a번째 가로선 b번째 세로선에서 오른쪽으로 연결된 것
	}

	for (int i = 0; i <= 3; ++i)
	{
		if (dfs(i, 0, 1))
		{
			answer = i;
			break;
		}
	}

	cout << answer;
}