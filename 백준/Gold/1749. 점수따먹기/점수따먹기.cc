#include <iostream>
#include <climits>
using namespace std;

int n, m;
int arr[202][202];
int dp[202][202];
int answer = INT_MIN;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> arr[i][j];
		}
	}

	//시작점으로 가능한게 40000개
	//시작점을 잡고, dp를 통해 모든 점까지의 합 구함
	//다 구한다음 가장 큰 차이를 가진곳 찾기

	for (int j = 1; j <= m; ++j)
	{
		dp[1][j] = dp[1][j - 1] + arr[1][j];
	}
	for (int i = 1; i <= n; ++i)
	{
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 2; j <= m; ++j)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	}

	for (int r1 = 1; r1 <= n; ++r1)
	{
		for (int c1 = 1; c1 <= m; ++c1)
		{
			for (int r2 = r1; r2 <= n; ++r2)
			{
				for (int c2 = c1; c2 <= m; ++c2)
				{
					int temp = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
					answer = max(answer, temp);
				}
			}
		}
	}
	cout << answer;
}