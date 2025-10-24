#include <iostream>
using namespace std;

string board[52];
int dist[52][52];
const int INF = 1e9 + 10;
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; ++i)
		cin >> board[i];

	//초기화
	for (int i = 0; i < n; ++i)
		fill(dist[i], dist[i] + 52, INF);

	//대각
	for (int i = 0; i < n; ++i)
		dist[i][i] = 0;

	//시작
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == 'Y')
			{
				dist[i][j] = min(dist[i][j], 1);
				dist[j][i] = min(dist[j][i], 1);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	int answer = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		for (int j = 0; j < n; ++j)
		{
			if (dist[i][j] <= 2 && dist[i][j] > 0)
				temp++;
		}
		answer = max(answer, temp);		
	}

	cout << answer;
}