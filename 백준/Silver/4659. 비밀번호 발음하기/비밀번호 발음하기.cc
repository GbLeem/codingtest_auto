#include <iostream>
using namespace std;

int t;

bool Check(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//
	string str;

	while (1)
	{
		cin >> str;
		if (str == "end")
			break;

		bool check1 = false;
		bool already = false;
		int cnt = 1;
		int same = 1;
		char last = '@';


		for (int i = 0; i < str.size(); ++i)
		{
			//모음 하나 이상 포함
			if (Check(str[i]))
			{
				check1 = true;
			}
			//연속 체크
			//연속 모음 or 자음
			if (last != '@' && Check(last) == Check(str[i]))
			{
				cnt++;
				if (last == str[i])
				{
					same++;
				}
				if (cnt == 3)
				{
					cout << "<" << str << "> is not acceptable.\n";
					already = true;
					continue;
				} 
				if (same == 2)
				{
					if (last != 'e' && last != 'o')
					{
						cout << "<" << str << "> is not acceptable.\n";
						already = true;
						continue;
					}
				}
			}
			else
			{
				cnt = 1;
				same = 1;
			}
			last = str[i];
		}
		if (!already)
		{
			if(check1)
				cout << "<" << str << "> is acceptable.\n";
			else
				cout << "<" << str << "> is not acceptable.\n";
		}
	}
}