#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int board[20][20];
int isused[20];
vector<int> ans;
vector<int> ans2;
int answer = INT_MAX;

int Check(const vector<int>& ans)
{
	int temp = 0;
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = i + 1; j < ans.size(); ++j)
		{
			temp += (board[ans[i]][ans[j]] + board[ans[j]][ans[i]]);
		}
	}
	return temp;
}

void Choose(int cur)
{
	if (cur == n / 2)
	{
		int scoreA = 0;
		int scoreB = 0;

		for (int i = 0; i < n; ++i)
		{
			if (!isused[i])
				ans2.push_back(i);
		}

		scoreA = Check(ans);
		scoreB = Check(ans2);
		
		answer = min(answer, abs(scoreA - scoreB));
		ans2.clear();

		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!isused[i])
		{
			if (ans.empty() || (!ans.empty() && ans.back() < i))
			{
				isused[i] = 1;
				ans.push_back(i);
				Choose(cur + 1);
				isused[i] = 0;
				ans.pop_back();
			}
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
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}
	
	Choose(0);

	cout << answer;
}