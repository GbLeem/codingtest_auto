//나보다 큰 최초의 수 찾기 -> 정렬안된 상태로
//N^2 -> 너무 큼
//stack?

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1'000'002];
vector<int> ans;
stack<int> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];			
	}

	for (int i = n - 1; i >= 0; --i)
	{
		while (!st.empty() && st.top() <= arr[i])
		{
			st.pop();
		}

		if (st.empty())
			ans.push_back(-1);
		else
			ans.push_back(st.top());
		st.push(arr[i]);
	}
	reverse(ans.begin(), ans.end());
	for (const auto& ai : ans)
	{
		cout << ai << " ";
	}
}