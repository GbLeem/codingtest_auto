#include <iostream>
using namespace std;

int a, b, c;
int arr[102];
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;

	for (int i = 0; i < 3; ++i)
	{
		int st, en;
		cin >> st >> en;

		for (int j = st+1; j <= en; ++j)
		{
			arr[j]++;
		}
	}

	for (int i = 1; i <= 100; ++i)
	{
		if (arr[i] == 1)
		{
			answer += a;
		}
		else if (arr[i] == 2)
		{
			answer += b * 2;
		}
		else if(arr[i] == 3)
		{
			answer += c * 3;
		}
	}
	cout << answer;
}