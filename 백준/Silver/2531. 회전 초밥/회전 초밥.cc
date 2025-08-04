#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, d, k, c;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}

	//i에서 시작해서 연속된 k개의 초밥 종류
	int value = -1;
	int en = 0;

	unordered_map<int, int> um;
	for (int st = 0; st < n; ++st)
	{
		while (en - st < k)
		{			
			um[vec[en % n]]++;
			en++;
		}		
		//쿠폰
		um[c]++;
		value = max(value, (int)um.size());
		um[vec[st]]--;
		if (um[vec[st]] == 0)
		{
			um.erase(vec[st]);
		}
	}
	
	cout << value;
}