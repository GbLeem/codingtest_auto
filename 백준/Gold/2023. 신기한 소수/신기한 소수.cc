#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int n;
vector<int> ans;
vector<int> result;
int prime[10] = { 1,2,3,5,7,9 };


bool isPrime(int num) 
{
	if (num < 2) 
	{
		return false;
	}
	for (int i = 2; i <= sqrt(num); ++i) 
	{
		if (num % i == 0) 
		{
			return false;
		}
	}
	return true;
}
void Check()
{
	int value = 0;
	bool find = true;

	for (int i = 0; i < ans.size(); ++i)
	{
		value *= 10;
		value += ans[i];		
		if (!isPrime(value))
		{
			find = false;
			break;
		}
	}

	if (find)
		result.push_back(value);
}

void Choose(int cur)
{
	if (cur == n)
	{
		Check();
		return;
	}

	for (int i = 0; i < 6; ++i)
	{
		ans.push_back(prime[i]);
		Choose(cur + 1);
		ans.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	Choose(0);
	
	sort(result.begin(), result.end());
	for (const auto& r : result)
	{
		cout << r << "\n";
	}
}