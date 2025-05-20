#include <iostream>
#include <string>
using namespace std;

string str;
string answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, str);

	for (int i = 0; i < str.size(); ++i)
	{
		if (islower(str[i]))
		{
			if (str[i] + 13 > 122)
				str[i] -= 26;
			str[i] += 13;
		}
		if (isupper(str[i]))
		{
			if (str[i] + 13> 90)
				str[i] -= 26;
			str[i] += 13;
		}
		else
			continue;
	}
	cout << str;
}