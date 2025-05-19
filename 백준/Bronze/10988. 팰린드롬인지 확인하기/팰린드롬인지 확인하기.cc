#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	
	for (int i = 0; i < str.size(); ++i)
	{
		st.push(str[i]);
	}

	for (int i = 0; i < str.size(); ++i)
	{
		if (st.top() != str[i])
		{
			cout << 0;
			return 0;
		}
		st.pop();
	}
	cout << 1;

}