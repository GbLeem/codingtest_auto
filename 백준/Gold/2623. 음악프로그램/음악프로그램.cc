#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[1002];
int indegree[1002];
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int num;
		cin >> num;

		vector<int> temp;

		for (int j = 0; j < num; ++j)
		{
			int order;
			cin >> order;
			temp.push_back(order);			
		}

		for (int i = 0; i < temp.size() - 1; ++i)
		{			
			//i가 i+1보다 앞
			adj[temp[i]].push_back(temp[i + 1]);
			indegree[temp[i + 1]]++;
		}
	}

	queue<int>q;
	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
	vector<int> answer;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		answer.push_back(cur);

		for (int nxt : adj[cur])
		{
			indegree[nxt]--;
			if (indegree[nxt] == 0)
				q.push(nxt);
		}
	}

	if (answer.size() != n)
	{
		cout << 0;
		return 0;
	}
	for (const auto& a : answer)
	{
		cout << a << "\n";
	}
}