#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<long long> vec;
long long minValue = LLONG_MAX;
vector<long long> answer;

void Print()
{
	sort(answer.begin(), answer.end());

	for (const auto& a : answer)
	{
		cout << a << " ";
	}
}

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

	for (int i = 0; i < n - 2; ++i)
	{
		int l = i + 1;
		int r = n - 1;

		while (l < r)
		{
			long long temp = vec[i] + vec[l] + vec[r];

			if (abs(temp) < minValue)
			{
				minValue = abs(temp);

				answer.clear();
				answer.push_back(vec[i]);
				answer.push_back(vec[l]);
				answer.push_back(vec[r]);
			}

			if (temp < 0)
				l++;
			else if (temp > 0)
				r--;
			else
			{
				Print();
				return 0;
			}
		}
	}
	Print();
}