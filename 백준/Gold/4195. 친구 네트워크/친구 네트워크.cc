#include <iostream>
#include <unordered_map>
using namespace std;

int t, f;
unordered_map<string, string> Board;
unordered_map<string, int> Rank;

string Find(string x)
{
	if (Board[x] == x)
		return x;
	Board[x] = Find(Board[x]);

	return Board[x];
}

void Union(string x, string y)
{
	string rootX = Find(x);
	string rootY = Find(y);

	if (rootX != rootY)
	{		
		Board[rootY] = rootX;
		Rank[rootX] += Rank[rootY];		
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> f;

		Board.clear();
		Rank.clear();

		for (int i = 0; i < f; ++i)
		{
			string a, b;
			cin >> a >> b;

			if (Board.count(a) == 0)
			{
				Board.insert({ a, a });
				Rank.insert({ a, 1 });
			}
			if (Board.count(b) == 0)
			{
				Board.insert({ b, b });
				Rank.insert({ b, 1 });
			}
			Union(a, b);
			cout << Rank[Find(a)] << "\n";
		}
	}
}