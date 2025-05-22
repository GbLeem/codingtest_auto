#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string str; 
string answer;
map<char, int> um;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;

	//sort(str.begin(), str.end()); //AAABB

	for (const auto& s : str)
	{
		um[s]++;
	}
	
	int odd = 0;
	char ch = '@';

	for (const auto& u : um)
	{
		if (u.second % 2 != 0)
		{
			odd++;
			ch = u.first;
		}
	}
	if (odd > 1)
		cout << "I'm Sorry Hansoo";
	else
	{
		string temp;
		for (const auto& u : um)
		{			
			temp += string(u.second / 2, u.first);
		}

		answer += temp;
		if (ch != '@')
			answer += ch;

		reverse(temp.begin(), temp.end());

		answer += temp;
	}
	cout << answer;
}