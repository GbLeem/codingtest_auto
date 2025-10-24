#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int n, k;
string str;
string answer;
unordered_map<string, int>um;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		char ch;
		cin >> ch;

		str += ch;
	}
	answer = str;
	sort(answer.begin(), answer.end());

	queue<pair<string, int>> q;
	q.push({ str, 0 });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur.first == answer)
		{
			cout << cur.second;
			return 0;
		}

		//없을 때
		if (um.find(cur.first) == um.end())
		{
			um[cur.first] = 1;

			for (int i = 0; i <= n - k; ++i)
			{
				string temp = cur.first.substr(i, k);
				reverse(temp.begin(), temp.end());
				string res = cur.first.substr(0, i) + temp + cur.first.substr(i + k, cur.first.size());
				q.push({ res, cur.second + 1 });
			}
		}
	}
	
	cout << -1;


}