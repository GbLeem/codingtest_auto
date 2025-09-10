#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> adj[502];
int deg[502];
int cost[502];
int ans[502];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];

		while (1)
		{
			int num;
			cin >> num;
			if (num == -1)
				break;
			adj[num].push_back(i);
			deg[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (deg[i] == 0)
		{
			q.push(i);
			ans[i] = cost[i];
		}		
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur])
		{
			deg[nxt]--;
			ans[nxt] = max(ans[nxt], ans[cur] + cost[nxt]);

			if (deg[nxt] == 0)			
				q.push(nxt);			
		}
	}

	for (int i = 1; i <= n;++i)
	{
		cout << ans[i] << "\n";
	}
}