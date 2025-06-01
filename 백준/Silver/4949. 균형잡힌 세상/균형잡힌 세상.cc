#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1)
	{
		getline(cin, str);

		if (str == ".")
			break;

		stack<char> st;

		for (int i = 0; i < str.size() - 1; ++i)
		{		
			if (str[i] == ')' && !st.empty() && st.top() == '(')
			{
				st.pop();
			}
			else if (str[i] == ']' && !st.empty() && st.top() == '[')
			{
				st.pop();
			}			
			else if(str[i] == '(' || str[i] == '[' || str[i] == ')' || str[i] ==']')
				st.push(str[i]);
		
		}

		if (st.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}

}