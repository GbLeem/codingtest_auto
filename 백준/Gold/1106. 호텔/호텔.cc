#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int c, n;
vector<pair<int, int>> vec;
int dp[22][1102]; //i번 도시까지 j명 모았을 때) 최소 비용
int answer = INT_MAX;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> n; //c명 더 늘려야함
	vec.push_back({ 0,0 });
	for (int i = 0; i < n; ++i)
	{
		int cost, cust;
		cin >> cost >> cust;
		vec.push_back({ cost, cust });
	}

	for (int i = 0; i < 22; ++i)
	{
		fill(dp[i], dp[i] + 1102, INT_MAX/2);
	}

	for (int i = 1; i <= n; ++i)
	{
		dp[i][0] = 0;
		for (int j = 1; j <= 1100; ++j)
		{
			//더 넣어야 할 때
			if (j - vec[i].second >= 0)
			{
				dp[i][j] = dp[i][j - vec[i].second] + vec[i].first;
			}						
			//더 작은값 찾기
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			
		}

		//초과된 것 찾기
		for (int j = c; j <= 1100; ++j)
		{
			answer = min(answer, dp[i][j]);
		}
	}
	cout << answer;
}