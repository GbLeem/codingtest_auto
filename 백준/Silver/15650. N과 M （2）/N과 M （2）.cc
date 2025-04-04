#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ans;

void Choose(int cur, int start)
{
	if (cur == m)
	{
		for (const int& a : ans)
		{
			cout << a << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = start; i <= n; ++i)
	{
		
        ans.push_back(i);
        Choose(cur + 1, i + 1);
        ans.pop_back();
		
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	Choose(0, 1);
}