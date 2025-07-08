#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[10];
vector<int> ans;
int answer = 0;
bool isused[10];

int Check()
{
	int temp = 0;
	for (int i = 0; i < ans.size() - 1; ++i)
	{
		temp += abs(arr[ans[i]] - arr[ans[i + 1]]);
	}

	return temp;
}
void Choose(int cur)
{
	if (cur == N)
	{
		answer = max(answer, Check());
	}

	//index
	for (int i = 0; i < N; ++i)
	{
		if (!isused[i])
		{
			ans.push_back(i);
			isused[i] = 1;
			Choose(cur + 1);
			ans.pop_back();
			isused[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	Choose(0);

	cout << answer;
}