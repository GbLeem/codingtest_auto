#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		string str;
		cin >> str;
		stack<char> st;

		for (int i = 0; i < str.size(); ++i)
		{
			if (!st.empty() && str[i] == ')' && st.top() == '(')
				st.pop();
			else
				st.push(str[i]);	
		}
		if (st.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}