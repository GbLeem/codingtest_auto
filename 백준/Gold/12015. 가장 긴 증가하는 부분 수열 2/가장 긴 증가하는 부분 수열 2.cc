#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> board;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		board.push_back(num);
	}
	
	vec.push_back(board[0]);
	
	for (int i = 1; i < board.size(); ++i)
	{
		if (board[i] > vec.back())
		{
			vec.push_back(board[i]);
		}
		else
		{
			auto it = lower_bound(vec.begin(), vec.end(), board[i]);
			*it = board[i];
		}
	}

	cout << vec.size();
}