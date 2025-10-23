#include <iostream>
#include <set>
using namespace std;

int c, n;
int board[1002];

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c;

	for (int i = 0; i <= 1000; ++i)
	{
		for (int j = 0; j <= 1000; j++)
		{
			if (gcd(i, j) == 1)
				board[max(i, j)] += 1;
		}
	}
	for (int i = 1; i <= 1000; ++i)
		board[i] += board[i - 1];
	while (c--)
	{
		cin >> n;
		
		cout << board[n] << "\n";
	}
}