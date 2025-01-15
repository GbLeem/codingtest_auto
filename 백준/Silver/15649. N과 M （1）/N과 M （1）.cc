#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ans;
bool isused[10];

void Print()
{
	for (const auto& a : ans)
	{
		cout << a << " ";
	}
	cout << "\n";
}

void Choose(int cur)
{
	if (cur == M + 1)
	{
		Print();
		return;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!isused[i])
		{
			ans.push_back(i);
			isused[i] = true;
			Choose(cur + 1);
			ans.pop_back();
			isused[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	Choose(1);
	return 0;
}