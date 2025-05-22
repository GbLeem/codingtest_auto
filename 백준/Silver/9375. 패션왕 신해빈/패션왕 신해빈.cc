#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;
int t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		unordered_map<string, int> um;

		for (int j = 0; j < t; ++j)
		{
			string name, category;
			cin >> name >> category;
			
			um[category]++;
		}
		int answer = 1;

		for (const auto& u : um)
		{
			answer *= (u.second + 1);
		}
		cout << answer - 1 << "\n";
	}
}