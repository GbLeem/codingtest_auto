#include<iostream>
#include <stack>
using namespace std;

int n;
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;

	while (n--)
	{
		string str;
		cin >> str;
		stack<char> st;

		for (int i = 0; i < str.size(); ++i)
		{
			if (st.empty())
			{
				st.push(str[i]);
			}
			else
			{
				if (str[i] == st.top())
				{
					st.pop();
				}
				else
				{
					st.push(str[i]);					
				}
			}
		}
		if (st.empty())
			answer++;
	}
	cout << answer;
}