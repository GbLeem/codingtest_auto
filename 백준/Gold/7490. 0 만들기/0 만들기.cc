#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n;
vector<int> ans;
vector<string> result;

void Check()
{
	string temp = "1";

	for (int i = 0; i < ans.size(); ++i)
	{
		//+
		if (ans[i] == 0)
			temp += "+" + to_string(i + 2);
		//-
		else if (ans[i] == 1)
			temp += "-" + to_string(i + 2);
		else
			temp += " " + to_string(i + 2);
	}

	vector<int> digit;
	vector<char> oper;
	int value = 0;
	int p = 0;

	for (int i = temp.size() - 1; i >= 0; --i)
	{
		if (temp[i] == ' ')
			continue;
		if (isdigit(temp[i]))
		{
			value += (temp[i] - '0') * pow(10, p);
			p++;
		}
		else
		{
			digit.push_back(value);
			oper.push_back(temp[i]);
			value = 0;
			p = 0;
		}
	}
	digit.push_back(value);
	reverse(digit.begin(), digit.end());
	reverse(oper.begin(), oper.end());

	int answer = digit[0];
	for (int i = 0; i < oper.size(); ++i)
	{
		if (oper[i] == '+')
		{
			answer += digit[i + 1];
		}
		else
		{
			answer -= digit[i + 1];
		}
	}

	if (answer == 0)
		result.push_back(temp);
}

void Choose(int cur)
{
	if (cur == n - 1)
	{
		Check();
		return;
	}
	for (int i = 0; i < 3; ++i)
	{
		ans.push_back(i);
		Choose(cur + 1);
		ans.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--)
	{
		cin >> n;
		result.clear();

		Choose(0);
		sort(result.begin(), result.end());
		for (const auto& r : result)
			cout << r << "\n";
		cout << "\n";
	}
}