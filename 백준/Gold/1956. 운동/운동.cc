#include <iostream>
using namespace std;

int board[402][402];
const int INF = 0x3f3f3f3f;
int v, e;
int answer = INF;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 1; i <= v; ++i)
		fill(board[i] + 1, board[i] + 1 + v, INF);

	for (int i = 1; i <= v; ++i)
		board[i][i] = 0;

	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		board[a][b] = c;
	}

	for (int i = 1; i <= v; ++i)
	{
		for (int j = 1; j <= v; ++j)
		{
			for (int k = 1; k <= v; ++k)
			{
				board[j][k] = min(board[j][k], board[j][i] + board[i][k]);
			}
		}
	}

	for (int i = 1; i <= v; ++i)
	{
		for (int j = i + 1; j <= v; ++j)
		{
			answer = min(answer, board[i][j] + board[j][i]);
		}
	}

	if (answer == INF)
		cout << -1;
	else
		cout << answer;
}