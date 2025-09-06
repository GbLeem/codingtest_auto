#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int t, n, k, w;
vector<int> adj[1002];
int deg[1002];
int D[1002];
int dp[1002];
set<int> ans;
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		for (int i = 0; i < 1002; ++i)
			adj[i].clear();
		fill(D, D + 1002, 0);
		fill(deg, deg + 1002, 0);
		fill(dp, dp + 1002, 0);
		answer = 0;

		cin >> n >> k;
		
		for (int i = 1; i <= n; ++i)
		{
			cin >> D[i];
		}

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			deg[y]++;
		}
		cin >> w;

		queue<int> q;

		for (int i = 1; i <= n; ++i)
		{
			if (deg[i] == 0)
			{
				q.push(i);
				dp[i] = D[i];
			}
		}

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (int nxt : adj[cur])
			{
				dp[nxt] = max(dp[nxt], dp[cur] + D[nxt]);
				deg[nxt]--;
				if (deg[nxt] == 0)
					q.push(nxt);
			}
		}

		cout << dp[w] << "\n";
	}
}