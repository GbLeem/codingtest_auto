#include <iostream>
#include <climits>
using namespace std;

int n;
int board[1002][3];
int dp[1002][3];
int answer = 1'000'002;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> board[i][j];
		}
	}

	//첫번째 색 고정
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == i)
				dp[1][j] = board[1][j];
			else
				dp[1][j] = 1'000'002;
		}

		for (int j = 2; j <= n; ++j)
		{
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + board[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + board[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + board[j][2];
		}

		for (int j = 0; j < 3; ++j)
		{
			if (j != i)
			{
				answer = min(answer, dp[n][j]);
			}
		}
	}
	cout << answer;	
}