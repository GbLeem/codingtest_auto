#include <iostream>
#include <climits>
using namespace std;

int n;
int board[100'002];
int answer = INT_MAX;
pair<int, int>ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	fill(board, board + 100002, INT_MAX);

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}
	
	int st = 0;
	int en = n - 1;

	while (st < en)
	{
		int sum = board[st] + board[en];
		if (answer > abs(sum))
		{
			answer = abs(sum);
			ans = make_pair(board[st], board[en]);
		}
		//음수
		if (sum < 0)
			st++;
		else
			en--;
	}

	cout << ans.first << " " << ans.second;
	
}