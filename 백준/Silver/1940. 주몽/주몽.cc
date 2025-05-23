#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int answer = 0;
int arr[15'002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int st = 0;
	int en = n - 1;

	while (st < en)
	{
		if (arr[st] + arr[en] == m)
		{
			answer++;
			st++;
			en--;
		}
		else if (arr[st] + arr[en] < m)
		{
			st++;
		}
		else
		{
			en--;
		}
	}
	
	cout << answer;
}