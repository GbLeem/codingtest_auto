#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[100'002];
int answer = 1e9 + 2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}
	
	int st = 0;
	int en = n - 1;

	while (st < en)
	{
		int value = board[st] + board[en];
		if (abs(value) < abs(answer))
			answer = value;
		if (value < 0)
			st++;
		else
			en--;
	}
	cout << answer;
}