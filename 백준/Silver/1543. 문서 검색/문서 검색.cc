#include <iostream>
#include <string>
using namespace std;

string str, temp;
int answer = 0;

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, str);
	getline(cin, temp);
	
	int idx = 0;
	while (1)
	{
		if (str.find(temp, idx) != -1)
		{
			answer++;
			idx = str.find(temp, idx) + temp.size();
		}
		else
		{
			break;
		}
	}
	cout << answer;
}