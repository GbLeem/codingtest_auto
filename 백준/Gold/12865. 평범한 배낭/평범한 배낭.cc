#include <iostream>
using namespace std;

int n, k;
pair<int, int> props[102];
int dp[102][100'002];
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		int w, v;
		cin >> w >> v;

		props[i].first = w;
		props[i].second = v;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			//넣을 수 있다면,
			if (j + props[i].first <= k)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + props[i].first] + props[i].second);
			else
				dp[i][j] = dp[i - 1][j];

			answer = max(answer, dp[i][j]);
		}
	}
	cout << answer;
}