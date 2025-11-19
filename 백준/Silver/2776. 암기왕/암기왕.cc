#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		vector<int> v1;
		vector<int> v2;

		int num;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			v1.push_back(num);
		}
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> num;
			v2.push_back(num);
		}

		sort(v1.begin(), v1.end());
		
		for (int i = 0; i < v2.size(); ++i)
		{
			if (binary_search(v1.begin(), v1.end(), v2[i]))
				cout << 1 << "\n";
			else
				cout << "0\n";
		}
	}
}