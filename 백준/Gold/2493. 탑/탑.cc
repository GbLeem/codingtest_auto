#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
stack<pair<int, int>> st;
vector<int> answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
			
		while (!st.empty() && st.top().first < num)
		{
			st.pop();
		}
		
		if (st.empty())
			answer.push_back(0);
		else
			answer.push_back(st.top().second);

		st.push({ num, i + 1 });
	}

	for (const auto& ai : answer)
		cout << ai << " ";
}