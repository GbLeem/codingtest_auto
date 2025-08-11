#include <iostream>
using namespace std;

int n, k;
long long dp[202][202]; //k개 더해서 n 만들기

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	for (int i = 0; i <= k; ++i)
	{
		dp[i][0] = 1;
	}

	for (int i = 0; i <= n; ++i)
	{
		dp[1][i] = 1;
	}

	for (int K = 2; K <= k; ++K)
	{
		for (int N = 1; N <= n; ++N)
		{
			dp[K][N] = (dp[K][N - 1] + dp[K - 1][N]) % 1'000'000'000;
		}
	}
	cout << dp[k][n];
}