#include <iostream>
#include <stack>
using namespace std;

int n, m;
int board[2002];
bool dp[2002][2002]; // s에서 e까지 펠린드롬인지 아닌지

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> board[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		dp[i][i] = 1;
	}
	
	for (int i = 1; i < n; ++i)
	{
		if (board[i] == board[i + 1])
		{
			dp[i][i + 1] = 1;
		}
	}

	//길이
	for (int i = 3; i <= n; ++i)
	{
		//시작
		for (int st = 1; st <= n - i + 1; ++st)
		{
			//끝
			int en = st + i - 1;

			if (board[st] == board[en] && dp[st + 1][en - 1])
			{
				dp[st][en] = 1;
			}
		}
	}

	cin >> m;

	while (m--)
	{
		int s, e;
		cin >> s >> e;

		cout << dp[s][e] << "\n";
	}
}