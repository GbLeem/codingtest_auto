#include <iostream>
#include <algorithm>
using namespace std;

string str1;
string str2;
string ans;
int dp[1002][1002];
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); ++i)
	{
		for (int j = 1; j <= str2.size(); ++j)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			answer = max(answer, dp[i][j]);
		}
	}
	
	int x = str1.size();
	int y = str2.size();
	
	while (dp[x][y] != 0)
	{
		if (dp[x][y] == dp[x][y - 1])
			y--;
		else if (dp[x][y] == dp[x - 1][y])
			x--;
		else
		{
			ans += str1[x-1];
			x--;
			y--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << answer << "\n" << ans;
}