#include <iostream>
using namespace std;

int t, l;
long long dp[2502];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	dp[0] = 1;
	for (int i = 1; i <= 2500; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % 1'000'000'007;
		}
	}
	while (t--)
	{
		cin >> l;
		if (l % 2 != 0)
			cout << "0\n";
		else
			cout << dp[l / 2] << "\n";
	}
}