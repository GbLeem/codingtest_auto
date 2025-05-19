#include <iostream>
#include <map>
using namespace std;

int n;
map<char, int> um;
string answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		um[str[0]]++;
	}

	for (const auto& u : um)
	{
		if (u.second >= 5)
			answer += u.first;
	}

	if (answer.empty())
		cout << "PREDAJA";
	else
		cout << answer;
}