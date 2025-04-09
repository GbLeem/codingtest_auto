#include <iostream>
using namespace std;

int n;
pair<int, int> board[22];
int dp[22][102]; //현재 i번째 왔을때 남은 체력 j 일때의 기쁨
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> board[i].first; //체력
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> board[i].second; //기쁨
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 100; j >= 0; --j)
		{
			if (j - board[i].first > 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - board[i].first] + board[i].second);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
			answer = max(answer, dp[i][j]);
		}
	}

	cout << answer;
}