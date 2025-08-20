#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 0;

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		n++;

		if (s[i] == 'c')
		{
			if (s[i + 1] == '=')
				n--;
			else if (s[i + 1] == '-')
				n--;
		}
		if (s[i] == 'd')
		{
			if (s[i + 1] == 'z')
			{
				if (s[i + 2] == '=')
					n--;
			}
			else if (s[i + 1] == '-')
				n--;
		}
		if (s[i] == 'l')
		{
			if (s[i + 1] == 'j')
				n--;
		}
		if (s[i] == 'n')
		{
			if (s[i + 1] == 'j')
				n--;
		}
		if (s[i] == 's')
		{
			if (s[i + 1] == '=')
				n--;
		}
		if (s[i] == 'z')
		{
			if (s[i + 1] == '=')
				n--;
		}
	}
	cout << n;
}