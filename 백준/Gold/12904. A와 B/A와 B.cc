#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;

	//뒤에 A를 추가하기 -> 뒤의 A를 빼기

	//뒤집고 뒤에 B 추가하기 -> B삭제하고 뒤집기

	//ABBA
	//ABB
	//AB -> BA
	//B
	bool flag = true;

	while (s != t)
	{
		if (t.size() <= s.size())
		{
			flag = false;
			break;
		}
		if (t.back() == 'A')
		{
			t.pop_back();
		}
		else // B
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
	if (!flag)
		cout << 0 << "\n";
	else
		cout << 1 << "\n";
}