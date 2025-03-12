#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answer)
{
	int one = 0;
	int two = 0;
	int three = 0;

	vector<int> oneArr = { 1,2,3,4,5 };
	vector<int> twoArr = { 2,1,2,3,2,4,2,5 };
	vector<int> threeArr = { 3,3,1,1,2,2,4,4,5,5 };

	int oneIdx = 0;
	int twoIdx = 0;
	int threeIdx = 0;

	for (int i = 0; i < answer.size(); ++i)
	{
		if (oneArr[oneIdx] == answer[i])		
			one++;
		if (twoArr[twoIdx] == answer[i])
			two++;
		if (threeArr[threeIdx] == answer[i])
			three++;

		oneIdx++;
		oneIdx %= 5;
		twoIdx++;
		twoIdx %= 8;
		threeIdx++;
		threeIdx %= 10;
	}

	vector<int> result;
	int maxValue = max({ one, two, three });

	if (maxValue == one)
		result.push_back(1);
	if (maxValue == two)
		result.push_back(2);
	if (maxValue == three)
		result.push_back(3);

	return result;
}