#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> board[4];
vector<int> sumA;
vector<int> sumB;
long long answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		board[0].push_back(a);
		board[1].push_back(b);
		board[2].push_back(c);
		board[3].push_back(d);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			sumA.push_back(board[0][i] + board[1][j]);
			sumB.push_back(board[2][i] + board[3][j]);
		}
	}

	sort(sumB.begin(), sumB.end());

	for (const auto& a : sumA)
	{
		int target = -a;

		int st = lower_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
		int en = upper_bound(sumB.begin(), sumB.end(), target) - sumB.begin();

		answer += (long long)(en - st);
	}

	cout << answer;
}