#include <iostream>
using namespace std;

int h, w;
char arr[102][102];
int answer[102][102];

int Check(int x, int y)
{
	int cnt = 0;
	while (y >= 0)
	{
		if (arr[x][y] == 'c')
			return cnt;
		y--;
		cnt++;
	}
	return -1;	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			answer[i][j] = Check(i, j);
		}
	}
	
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

}
