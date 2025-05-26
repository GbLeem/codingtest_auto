#include <iostream>
using namespace std;

int n, m, j;
int arr[22];
int mx, px;
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> j;

	mx = 1;
	px = m;
	
	for (int i = 0; i < j; ++i)
	{
		cin >> arr[i];

		if (arr[i] - px > 0)
		{
			answer += (arr[i] - px);
			int value = arr[i] - px;
			px += value;
			mx += value;
		}
		else if (arr[i] - mx < 0)
		{
			answer += (mx - arr[i]);
			int value = mx - arr[i];
			px -= value;
			mx -= value;
		}
		else
			continue;
	}
	cout << answer;
}