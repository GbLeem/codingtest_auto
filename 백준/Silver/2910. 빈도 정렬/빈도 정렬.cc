#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int arr[1001];
int n, c;

bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
{
	if (get<0>(a) == get<0>(b))
		return get<2>(a) < get<2>(b);
	return get<0>(a) > get<0>(b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;

	vector<pair<int, int>> temp; //value index
	vector<tuple<int, int, int>> vec; //cnt value, index

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		temp.push_back({ num, i });
	}

	stable_sort(temp.begin(), temp.end()); //1 1 1 2 2 2 3 3 3

	int cnt = 1;
	int index = -1;
	for (int i = 0; i < n; ++i)
	{
		if (i == n - 1 || temp[i].first != temp[i + 1].first)
		{
			if (index == -1)
				index = temp[i].second;
			vec.push_back({ cnt, temp[i].first, index});
			cnt = 1;
			index = -1;
		}
		else if (temp[i].first == temp[i + 1].first)
		{
			cnt++;
			if (index == -1)
				index = temp[i].second;
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); ++i)
	{
		while (get<0>(vec[i]) > 0)
		{
			cout << get<1>(vec[i]) << " ";
			get<0>(vec[i])--;
		}
	}
}