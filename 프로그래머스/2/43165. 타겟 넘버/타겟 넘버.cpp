#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> number;
vector<int> ans;
int answer = 0;
int Target;

void Check()
{
	int sum = 0;
	for (int i = 0; i < ans.size(); ++i)
	{
		if (ans[i] == 0)
			sum += number[i];
		else
			sum -= number[i];
	}
	if (sum == Target)
		answer++;
}
void Choose(int cur)
{
	if (cur == number.size())
	{
		Check();
		return;
	}
	for (int i = 0; i <= 1; ++i)
	{
		ans.push_back(i);
		Choose(cur + 1);
		ans.pop_back();
	}
}

int solution(vector<int> numbers, int target)
{
	number = numbers;
	Target = target;
	Choose(0);

	return answer;
}