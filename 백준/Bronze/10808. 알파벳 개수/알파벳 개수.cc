#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[26] = { 0, };
	string str;

	cin >> str;
	//97 
	for (int i = 0; i < str.size(); ++i)
	{
		arr[(int)str[i] - 97]++;
	}
	for (int i = 0; i < 26; ++i)
		cout << arr[i] << " ";
}