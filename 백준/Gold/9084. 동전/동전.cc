#include <iostream>
using namespace std;

int t;
int coins[22];
int dp[10002];

//n개의 동전으로 m 만들기
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;

	while (t--)
	{
		int n;
		int m;
		int answer = 0;

		cin >> n;

		fill(coins, coins + 22, 0);
		fill(dp, dp + 10002, 0);

		for (int i = 1; i <= n; ++i)
		{
			cin >> coins[i];
		}
		cin >> m;
		dp[0] = 1;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = coins[i]; j <= m; ++j)
			{
				dp[j] += dp[j - coins[i]];
			}
		}
		cout << dp[m] << "\n";
	}

}