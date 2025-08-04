#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end()); //1 3 5 

	//차이가 m과 가장 가까운 수
	int value = INT_MAX;
	for (int i = 0; i < vec.size(); ++i)
	{
		int temp = m + vec[i];
		if (lower_bound(vec.begin(), vec.end(), temp) != vec.end())
		{
			value = min(value, *lower_bound(vec.begin(), vec.end(), temp) - vec[i]);
		}
	}

	cout << value;
}