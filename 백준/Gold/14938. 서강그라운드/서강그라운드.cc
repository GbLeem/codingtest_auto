#include <iostream>
using namespace std;

int n, m, r;
int item[102];
int board[102][102];
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; ++i)
	{
		cin >> item[i];
	}

	for (int i = 1; i <= n; ++i)
		fill(board[i], board[i] + 1 + n, INF);

	for (int i = 0; i < r; ++i)
	{
		int a, b, l;
		cin >> a >> b >> l;
		board[a][b] = min(board[a][b], l);
		board[b][a] = min(board[b][a], l);
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

	int answer = -1;
	//시작점
	for (int i = 1; i <= n; ++i)
	{
		int temp = item[i];
		for (int j = 1; j <= n; ++j)
		{
			if (board[i][j] != INF && i != j)
			{
				if (board[i][j] <= m)
					temp += item[j];
			}
		}
		answer = max(answer, temp);
	}
	cout << answer;
}