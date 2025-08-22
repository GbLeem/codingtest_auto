#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

string str;

bool vis[100];

void solve(int st, int en)
{
	if (st > en)
		return;

	int minIdx = en + 1;
	char minChar = 'Z' + 1;
	for (int i = st; i <= en; ++i)
	{
		if (minChar > str[i])
		{
			minChar = str[i];
			minIdx = i;
		}
	}
	vis[minIdx] = 1;
	string temp = "";
	for (int i = 0; i < str.size(); ++i)
	{
		if (vis[i])
			temp += str[i];
	}
	
	cout << temp << "\n";
	solve(minIdx + 1, en);
	solve(st, minIdx - 1);
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	solve(0, str.size() - 1);
}