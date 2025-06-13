#include <iostream>
#include <queue>
using namespace std;

int n, k;
int board[100005];
int cnt = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	queue<int> q;
	fill(board, board + 100002, -1);
	board[n] = 0;
	q.push(n);

	bool first = true;
	int temp = -1;

	if (n == k)
	{
		cout << 0 << "\n" << 1;
		return 0;
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : {cur + 1, cur - 1, cur * 2})
		{
			if (nxt < 0 || nxt > 100000)
				continue;
			
			//이미 방문했을때
			if (board[nxt] != -1)
			{
				//우리가 찾고자하는 값이면
				if (nxt == k && board[cur] + 1 == temp)
				{
					cnt++;
				}
				//이전 방문 횟수랑 이번 방문 횟수랑 같으면 허용
				else if(board[nxt] == board[cur] + 1)
				{
					q.push(nxt);
					board[nxt] = board[cur] + 1;
					continue;
				}
				//아니면
				else
					continue;
			}

			q.push(nxt);
			board[nxt] = board[cur] + 1;

			if (first && nxt == k)
			{
				temp = board[nxt];
				//cout << "temp: " << temp << "\n";
				first = false;
				cnt++;
			}
		}
	}
	cout << board[k] << "\n";
	cout << cnt;

}