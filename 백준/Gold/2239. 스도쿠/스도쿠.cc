#include <iostream>
#include <string>
using namespace std;

string inputboard[10];
int board[10][10];

bool Check(int x, int y, int num)
{	
	for (int i = 0; i < 9; ++i)
	{
		if (board[i][y] == num)
			return false;	
	}
	for (int j = 0; j < 9; ++j)
	{
		if (board[x][j] == num)
			return false;
	}
	int X = (x / 3) * 3;
	int Y = (y / 3) * 3;

	for (int i = X; i < X + 3; ++i)
	{
		for (int j = Y; j < Y + 3; ++j)
		{
			if (board[i][j] == num)
				return false;
		}
	}

	return true;
}

bool Choose()
{
	int x = -1;
	int y = -1;

	bool flag = false;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] == 0)
			{
				x = i;
				y = j;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	if (!flag)
		return true;

	for (int i = 1; i <= 9; ++i)
	{
		if (Check(x, y, i))
		{
			board[x][y] = i;

			if (Choose())
				return true;

			board[x][y] = 0;
		}
	}
	return false;
}

void Print()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 9; ++i)
	{		
		cin >> inputboard[i];	
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			board[i][j] = inputboard[i][j] - '0';
		}
	}	

	if (Choose())
		Print();
}