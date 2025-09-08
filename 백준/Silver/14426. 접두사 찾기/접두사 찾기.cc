#include <iostream>
using namespace std;

int n, m;
const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
int nxt[MX][26];
int answer = 0;

int c2i(char c)
{
	return c - 'a';
}

void insert(string& s)
{
	int cur = ROOT;
	for (auto c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
}

bool find(string& s)
{
	int cur = ROOT;
	for (auto c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
			return false;
		cur = nxt[cur][c2i(c)];
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < MX; ++i)
		fill(nxt[i], nxt[i] + 26, -1);

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		insert(str);
	}

	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		if (find(str))		
			answer++;		
	}
	cout << answer;
}
