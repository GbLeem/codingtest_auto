#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[10];
vector<int> ans;

void Choose(int cur, int start)
{
	if (cur == m)
	{
		for (const int& a : ans)
			cout << a << " ";
		cout << "\n";
		return;
	}

	//index
	for (int i = start; i < n; ++i)
	{
		ans.push_back(board[i]);
		Choose(cur + 1, i + 1);
		ans.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}
	sort(board, board + n);
	Choose(0,0);

}