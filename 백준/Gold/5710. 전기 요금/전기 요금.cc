#include <iostream>
using namespace std;

int a, b;

int Calc(int w)
{
	int cost = 0;

	cost += min(w, 100) * 2;
	w -= 100;

	if (w > 0)
	{
		cost += min(w, 9900) * 3;
		w -= 9900;
		if (w > 0)
		{
			cost += min(w, 990'000) * 5;
			w -= 990'000;
			if (w > 0)
				cost += w * 7;
		}
	}

	return cost;
}

int Calc2(int c)
{
	int w = 0;

	w += min(c, 200) / 2;
	c -= 200;

	if (c > 0)
	{
		w += min(c, 29700) / 3;
		c -= 29700;
		if (c > 0)
		{
			w += min(c, 4950000) / 5;
			c -= 4950000;
			if (c > 0)
			{
				w += c / 7;
			}
		}
	}
	return w;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			return 0;
		
		int w = Calc2(a);

		int st = 0;
		int en = w;
		while (st <= en)
		{
			int m = (st + en) / 2;

			int costA = Calc(m);
			int costB = Calc(w - m);

			if (costB - costA == b)
			{
				cout << costA << "\n";
				break;
			}
			if (costB - costA > b)
				st = m + 1;
			else
				en = m - 1;
		}
	}
}