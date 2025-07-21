#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int t, n;
unordered_map<string, int> um;
vector<string> arr;

bool cmp(const string& a, const string& b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n;

		um.clear();
		arr.clear();

		for (int i = 0; i < n; ++i)
		{
			string num;
			cin >> num;

			arr.push_back(num);
		}
		sort(arr.begin(), arr.end(), cmp);

		bool check = false;

		for (const string& ai : arr)
		{
			for (int i = 1; i < ai.size(); ++i)
			{
				string temp = ai.substr(0, i);
				if (um[temp])
				{
					check = true;
					break;
				}
			}
			if (check)
				break;
			else
				um[ai]++;
		}
		if (check)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}