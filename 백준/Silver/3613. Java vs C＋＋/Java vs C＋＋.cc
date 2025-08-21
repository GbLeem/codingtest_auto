#include <iostream>
#include <string>
using namespace std;

string str;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str;
	if (isupper(str[0]) || str[0] == '_' || str[str.size()-1] == '_')
	{
		cout << "Error!";
		return 0;
	}

	//c++
	if (str.find("_") != -1)
	{		
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == '_' && str[i + 1] == '_')
			{
				cout << "Error!";
				return 0;
			}
			if (isalpha(str[i]) && isupper(str[i]))
			{
				cout << "Error!";
				return 0;
			}
		}
		int idx = str.find("_");
		string temp;
		while (idx != -1)		
		{
			temp = toupper(str[idx + 1]);
			//cout << temp << "\n";
			
			str.replace(idx, 2, temp);
			idx = str.find("_");
		}		
	}
	//Java and stay
	else
	{
		for (int i = 0; i < str.size(); ++i)
		{
			if (isupper(str[i]))
			{
				str[i] = tolower(str[i]);
				str.insert(i, "_");
			}
		}
	}

	cout << str;
}