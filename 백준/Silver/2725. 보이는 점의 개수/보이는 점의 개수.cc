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
	
	board[1] = 3;

	for (int i = 2; i <= 1000; ++i)
	{
		int cnt = 0;

		for (int j = 1; j < i; j++)
		{
			if (gcd(i, j) == 1)
				cnt++;
		}
		board[i] = board[i - 1] + cnt * 2;
	}
	while (c--)
	{
		cin >> n;
		
		cout << board[n] << "\n";
	}
}