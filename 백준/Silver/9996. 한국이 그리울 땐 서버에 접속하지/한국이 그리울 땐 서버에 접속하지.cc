#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
string pattern;
string st;
string en;

int main()
{
	cin >> n;
	cin >> pattern;
	
	int idx = pattern.find('*');	

	st = pattern.substr(0, idx);
	en = pattern.substr(idx + 1);	

	for (int i = 0; i < n; ++i)
	{
		string answer = "DA";
		string file;

		cin >> file;
		if (st.size() + en.size() > file.size())
		{
			cout << "NE\n";			
		}
		else
		{
			if (st == file.substr(0, st.size()) && en == file.substr(file.size() - en.size()))
				cout << "DA\n";
			else
				cout << "NE\n";
		}		
	}
}