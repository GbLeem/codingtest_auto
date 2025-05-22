#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n, m;
string arr[100005];
unordered_map<string, int> um;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		arr[i] = name;
		um.insert({ name, i + 1 });
	}
	
	for (int i = 0; i < m; ++i)
	{
		string q;
		cin >> q;

		if (isdigit(q[0]))
		{
			cout << arr[stoi(q) - 1] << "\n";
		}
		else
		{
			cout << um[q] << "\n";
		}
	}
}