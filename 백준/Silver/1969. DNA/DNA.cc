#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m;
vector<string> vec;
int answer;
string str;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		vec.push_back(str);
	}
	
	for (int j = 0; j < m; ++j)
	{
		unordered_map<char, int> um;
		for (int i = 0; i < vec.size(); ++i)
		{
			um[vec[i][j]]++;
		}

		int maxCnt = -1;
		char maxChar = 'Z';

		for (const auto& u : um)
		{
			if (maxCnt == u.second)
			{
				if (maxChar > u.first)
				{
					maxChar = u.first;
				}
			}
			else
			{
				if (maxCnt < u.second)
				{
					maxCnt = u.second;
					maxChar = u.first;
				}				
			}
		}
		answer += (n - maxCnt);
		str += maxChar;
	}
	
	cout << str << "\n" << answer;
}