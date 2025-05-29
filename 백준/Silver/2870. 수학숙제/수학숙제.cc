#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> vec;
string str;

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
		
	for (int i = 0; i < n; ++i)
	{
		cin >> str;

		string temp;

		for (int j = 0; j < str.size(); ++j)
		{
			if (isalpha(str[j]))
			{
				if (!temp.empty())
				{			
					vec.push_back(temp);
					temp.clear();
				}
			}
			else
			{
				temp += str[j];
			}
		}
		if (!temp.empty())
		{
			vec.push_back(temp);
			temp.clear();
		}
	}
	
	for (auto& vi : vec)
	{
		if (vi.front() == '0')
		{
			int idx = vi.find_first_not_of('0');
			if (idx != string::npos)
				vi = vi.substr(idx);
			else
				vi = "0";
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	for (const auto& vi :vec)
	{
		cout << vi << "\n";
	}
}