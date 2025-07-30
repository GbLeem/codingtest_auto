#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
vector<int> vec;
long long answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size()-1; ++i)
	{
		for (int j = i + 1; j < vec.size(); ++j)
		{
			long long temp = 0 - (vec[i] + vec[j]);
			answer += ((upper_bound(vec.begin() + j + 1, vec.end(), temp) - vec.begin()) - (lower_bound(vec.begin() + j + 1, vec.end(), temp) - vec.begin()));
		}
	}
	cout << answer;
}