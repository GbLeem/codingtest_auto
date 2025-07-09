#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
unordered_map<string, string> um;

string CenterStr(string str)
{
	string temp = "";	

	sort(str.begin() + 1, str.end() - 1);
	temp = str;
	
	return temp;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		if (str.size() <= 3)
			um.insert({ str, str });
		else
		{
			string temp = CenterStr(str);
			um.insert({ temp, str });
		}
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		string str;
		cin >> str;		

		//첫글자 마지막 글자로 원래 글자 만들기
		if (str.size() == 1)
			cout << um[str] << " ";
		else
		{
			string temp = CenterStr(str);
			cout << um[temp] << " ";
		}
	}
}