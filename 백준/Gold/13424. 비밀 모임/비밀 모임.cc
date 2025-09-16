#include <iostream>
using namespace std;

int t;
int n, m;
int k;

int board[102][102];
const int INF = 0x3f3f3f3f;
int f[102];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	
	while (t--)
	{
		cin >> n >> m;

		for (int i = 0; i < 102; ++i)
		{
			fill(board[i], board[i] + 102, INF);
		}
		fill(f, f + 102, 0);

		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			board[a][b] = min(board[a][b], c);
			board[b][a] = min(board[b][a], c);
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				for (int k = 1; k <= n; ++k)
				{
					board[j][k] = min(board[j][k], board[j][i] + board[i][k]);
				}
			}
		}

		cin >> k;
		for (int i = 0; i < k; ++i)
		{
			cin >> f[i];
		}

		int answer = INF;
		int idx = INF;

		//방
		for (int i = 1; i <= n; ++i)
		{
			int temp = 0;
			//인간
			for (int j = 0; j < k; ++j)
			{
				if (i == f[j])
					continue;
				temp += board[f[j]][i];
			}
			if (answer > temp)
			{
				answer = temp;
				idx = i;
			}
			else if (answer == temp)
			{
				idx = min(idx, i);
			}
		}
		cout << idx << "\n";		
	}
}