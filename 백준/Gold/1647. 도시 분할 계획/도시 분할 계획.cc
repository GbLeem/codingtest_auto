#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
tuple<int, int, int>edge[1000002];
vector<int> parent(100'002, -1);

int find(int x)
{
	if (parent[x] < 0)
		return x;
	return parent[x] = find(parent[x]);
}

bool diff(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return 0;
	if (parent[u] == parent[v])
		parent[u]--;
	if (parent[u] < parent[v])
		parent[v] = u;
	else
		parent[u] = v;
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}
	sort(edge, edge + m);

	int cnt = 0;
	int ans = 0;

	int maxCost = -1;

	for (int i = 0; i < m; ++i)
	{
		int a, b, cost;
		tie(cost, a, b) = edge[i];

		if (!diff(a, b))
			continue;

		ans += cost;
		maxCost = max(cost, maxCost);
		cnt++;
		if (cnt == n - 1)
			break;
	}
	cout << ans - maxCost;
}