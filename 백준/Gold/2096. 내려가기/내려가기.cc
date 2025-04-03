#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int board[100'002][3];

int dp_max[3];
int dp_min[3];
int max_temp[3];
int min_temp[3];

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i][0] >> board[i][1] >> board[i][2];
	}

	dp_max[0] = board[0][0];
	dp_max[1] = board[0][1];
	dp_max[2] = board[0][2];

	dp_min[0] = board[0][0];
	dp_min[1] = board[0][1];
	dp_min[2] = board[0][2];

	for (int i = 1; i < n; ++i)
	{
		//하나 전 기록
		for (int j = 0; j < 3; ++j)
			max_temp[j] = dp_max[j];

		for (int j = 0; j < 3; ++j)
			min_temp[j] = dp_min[j];

		dp_max[0] = max(max_temp[0], max_temp[1]) + board[i][0];
		dp_max[1] = max(max(max_temp[0], max_temp[1]),max_temp[2]) + board[i][1];
		dp_max[2] = max(max_temp[2], max_temp[1]) + board[i][2];

		dp_min[0] = min(min_temp[0], min_temp[1]) + board[i][0];
		dp_min[1] = min(min(min_temp[0], min_temp[1]), min_temp[2]) + board[i][1];
		dp_min[2] = min(min_temp[2], min_temp[1]) + board[i][2];
	}

	cout << *max_element(dp_max, dp_max + 3) << " " << *min_element(dp_min, dp_min + 3);
}