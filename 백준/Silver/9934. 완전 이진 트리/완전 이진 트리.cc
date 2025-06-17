#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K;
int arr[1025];
vector<int> ans[12]; //레벨

void func(int start, int end, int depth)
{
	if (start == end)
	{
		ans[depth].push_back(arr[start]);
		return;
	}
	int mid = (start + end) / 2;
	ans[depth].push_back(arr[mid]);

	func(start, mid, depth + 1);
	func(mid + 1, end, depth + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	int total = pow(2, K) - 1;
	for (int i = 0; i < total; ++i)
	{
		cin >> arr[i];
	}
	
	func(0, total, 0);

	for (int i = 0; i < K; ++i)
	{
		for (const auto& a : ans[i])
			cout << a << " ";
		cout << "\n";
	}
}