#include <iostream>
#include <queue>
using namespace std;

int n, k;
pair<int, int>board[100'002];
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	queue<int> q;
	q.push(n);
	board[n] = { 1, 1 }; //값, 갯수
	bool first = true;

	if (n == k)
	{
		cout << 0 << "\n" << 1;
		return 0;
	}

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt < 0 || nxt > 100'000)
				continue;

			if (board[nxt].first == 0)
			{
				q.push(nxt);
				board[nxt].first = board[cur].first + 1;
				board[nxt].second += board[cur].second;
			}
			else if (board[nxt].first == board[cur].first + 1)
			{
				board[nxt].second += board[cur].second;
			}			
		}
	}
	cout << board[k].first - 1 << "\n" << board[k].second;
}