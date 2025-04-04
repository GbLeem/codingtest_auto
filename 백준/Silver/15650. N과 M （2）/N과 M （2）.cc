#include <iostream>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	int index = 1;
	if (cur != 0)
		index = arr[cur - 1] + 1;

	for (int i = index; i <= n; ++i)
	{
		if (!isused[i])
		{
			arr[cur] = i;
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(0);
}