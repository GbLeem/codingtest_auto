#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int value[102];
int dp[100'002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> value[i];
	}
	sort(value, value + n);
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = value[i]; j <= k; ++j)
		{
			dp[j] += dp[j - value[i]];
		}
	}
	cout << dp[k];
}