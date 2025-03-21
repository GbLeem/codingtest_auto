#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int board[12];
int sign[4];
vector<int> ans;
int answerMax = INT_MIN;
int answerMin = INT_MAX;

void Choose(int cur)
{
	if (cur == n - 1)
	{
		int temp = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i == 0)
				temp = board[i];
			else
			{
				if (ans[i-1] == 0)
				{
					temp = temp + board[i];
				}
				else if (ans[i-1] == 1)
				{
					temp = temp - board[i];
				}
				else if (ans[i-1] == 2)
				{
					temp = temp * board[i];
				}
				else if (ans[i-1] == 3)
				{
					temp = temp / board[i];
				}
			}
		}
		answerMax = max(answerMax, temp);		
		answerMin = min(answerMin, temp);
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (sign[i] > 0)
		{
			sign[i]--;
			ans.push_back(i);
			Choose(cur + 1);
			sign[i]++;
			ans.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> sign[i];
	}

	Choose(0);

	cout << answerMax << "\n" << answerMin;
}