#include <iostream>
#include <string>
using namespace std;

int N;
int name = 666;
string answer;
int cnt = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> N;

	while (1)
	{
		answer = to_string(name);
		if (answer.find("666") != string::npos)
		{
			cnt++;
			if (cnt == N)
			{
				cout << name;
				break;
			}
		}		
		name++;
	}
	
	//666
	//1666
	//2666
	//...
	//9666
	//10666
	//11666
	//12666
	//...
	//15666
	// ||
	//16661
}