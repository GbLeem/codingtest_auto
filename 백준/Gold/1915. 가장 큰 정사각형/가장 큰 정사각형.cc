#include <iostream>
using namespace std;

int n, m;
string board[1002];
int answer = 0;
int dp[1002][1002]; //i, j 왔을때 최대의 넓이

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}
	
	for (int i = 0; i < n; ++i)
	{
		dp[i][0] = board[i][0] - '0';
		if (dp[i][0] == 1)
			answer = 1;
	}

	for (int j = 0; j < m; ++j)
	{
		dp[0][j] = board[0][j] - '0';
		if (dp[0][j] == 1)
			answer = 1;
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (board[i][j] == '1')
			{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				answer = max(answer, dp[i][j]);
			}
		}
	}
	cout << answer * answer;
}