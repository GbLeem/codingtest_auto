#include <iostream>
using namespace std;

int n, m, r;
int board[102][102];
int temp[102][102];
int query[1002];

void one()
{
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < m; ++y)
		{
			board[x][y] = temp[n - 1 - x][y];
		}
	}
}

void two()
{
	for (int y = 0; y < m; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			board[x][y] = temp[x][m - 1 - y];
		}
	}
}

void three()
{
	for (int y = 0; y < m; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			board[y][x] = temp[n - 1 - x][y];
		}
	}
	swap(n, m);
}

void four()
{
	for (int y = 0; y < m; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			board[y][x] = temp[x][m - 1 - y];
		}
	}
	swap(n, m);
}

void five()
{
	int tn = n / 2;
	int tm = m / 2;
	int t[52][52] = { 0, };

	for (int x = 0; x < tn; ++x)
	{
		for (int y = 0; y < tm; ++y)
		{
			t[x][y] = temp[x][y];
			board[x][y] = temp[x + tn][y];
		}
	}
	for (int x = tn; x < n; ++x)
	{
		for (int y = 0; y < tm; ++y)
		{
			board[x][y] = temp[x][y + tm];
		}
	}
	for (int x = tn; x < n; ++x)
	{
		for (int y = tm; y < m; ++y)
		{
			board[x][y] = temp[x - tn][y];
		}
	}
	for (int x = 0; x < tn; ++x)
	{
		for (int y = tm; y < m; ++y)
		{
			board[x][y] = t[x][y - tm];
		}
	}
}

void six()
{
	int tn = n / 2;
	int tm = m / 2;
	int t[52][52] = { 0, };

	for (int x = 0; x < tn; ++x)
	{
		for (int y = 0; y < tm; ++y)
		{
			t[x][y] = temp[x + tn][y + tm];
			board[x][y] = temp[x][y + tm];
		}
	}
	for (int x = tn; x < n; ++x)
	{
		for (int y = 0; y < tm; ++y)
		{
			board[x][y] = temp[x - tn][y];
		}
	}
	for (int x = tn; x < n; ++x)
	{
		for (int y = tm; y < m; ++y)
		{
			board[x][y] = temp[x][y - tm];
		}
	}
	for (int x = 0; x < tn; ++x)
	{
		for (int y = tm; y < m; ++y)
		{
			board[x][y] = t[x][y - tm];
		}
	}
}

void copy()
{
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < m; ++y)
		{			
			temp[x][y] = -1;
			temp[x][y] = board[x][y];
		}
	}
}

void print()
{
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < m; ++y)
		{
			cout << board[x][y] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < m; ++y)
		{
			cin >> board[x][y];
			temp[x][y] = board[x][y];
		}
	}

	for (int i = 0; i < r; ++i)
	{
		cin >> query[i];
	}

	for (int i = 0; i < r; ++i)
	{
		switch (query[i])
		{
		case 1:
			one();
			break;
		case 2:
			two();
			break;
		case 3:
			three();		
			break;
		case 4:
			four();
			break;
		case 5:
			five();
			break;
		case 6:
			six();
			break;	
		}
		copy();
	}	
	print();
}