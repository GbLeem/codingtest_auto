#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
tuple<int, int, int> edge[100'002];
vector<int> p(1002, -1);

int Find(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = Find(p[x]);
}

bool Diff(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)
		return 0;

	if (p[x] == p[y])
		p[x]--;
	if (p[x] < p[y])
		p[y] = x;
	else
		p[x] = y;

	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; ++i)
		p[i] = i;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c, a, b };
	}
	sort(edge, edge + m);
	int cnt = 0;
	int ans = 0;

	for (int i = 0; i < m; ++i)
	{
		int cost, a, b;
		tie(cost, a, b) = edge[i];

		if (!Diff(a, b))
			continue;
		ans += cost;
		cnt++;
		if (cnt == n - 1)
			break;
	}
	cout << ans;
}