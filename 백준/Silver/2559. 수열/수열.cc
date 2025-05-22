#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, k;
int answer = INT_MIN;
int arr[100'002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int st = 0;
	int en = 0;
	int temp = 0;

	while (en < n)
	{
		if (en - st < k)
		{
			temp += arr[en];
			en++;
		}
		else
		{			
			answer = max(answer, temp);
			temp -= arr[st];
			st++;
		}
	}	
	answer = max(answer, temp);

	cout <<answer;
}