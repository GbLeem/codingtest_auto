#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> board;
int sum = 0;
int max_value = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		board.push_back(num);
		sum += num;
		max_value = max(max_value, num);
	}

	int st = max_value;
	int en = sum;
	int ans = en;

	while (st <= en)
	{
		int mid = (st + en) / 2;

		int cnt = 1;
		int temp = 0;

		for (int i = 0; i < n; ++i)
		{
			if (temp + board[i] > mid)
			{
				cnt++;
				temp = board[i];
			}
			else
				temp += board[i];
		}

		if (cnt <= m)
		{
			ans = mid;
			en = mid - 1;
		}
		else
			st = mid + 1;
	}
	cout << ans;
}