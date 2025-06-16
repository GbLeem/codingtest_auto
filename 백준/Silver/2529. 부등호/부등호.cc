#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k;
char cmp[10]; //부등호 저장
bool isused[10];
vector<int> ans;
string minAns;
string maxAns;

bool comp(const string& a, const string& b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

bool Check()
{
	int answer = 1;

	for (int i = 0; i < k; ++i)
	{
		if (cmp[i] == '<')
		{
			if (ans[i] > ans[i + 1])
				return false;				
		}
		else
		{
			if (ans[i] < ans[i + 1])
				return false;
		}
	}
	return true;
}

void Choose(int cur)
{
	if (cur == k + 1)
	{		
		if (Check())
		{	
			string str;
			for (int i = 0; i < ans.size(); ++i)
			{
				str += to_string(ans[i]);
			}	

			if (minAns == "")
				minAns = str;
			
			else
				minAns = min(minAns, str);
			maxAns = max(maxAns, str);
		}
		return;
	}

	for (int i = 0; i < 10; ++i)
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
	
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> cmp[i];
	}

	Choose(0);

	cout << maxAns << "\n" << minAns;

}