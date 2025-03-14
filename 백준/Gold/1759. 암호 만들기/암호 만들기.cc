#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char word[20];
char arr[20];
bool isused[20];

void func(int cur, int index)
{
	if (cur == L)
	{
		int cnt[2] = { 0,0 }; //모음 자음
		for (int i = 0; i < L; ++i)
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				cnt[0]++;
			else
				cnt[1]++;
		}
		if (cnt[0] >= 1 && cnt[1] >= 2)
		{
			for (int i = 0; i < L; ++i)
				cout << arr[i];
			cout << "\n";
			return;
		}
	}

	for (int i = index; i < C; ++i)
	{
		if (!isused[i])
		{
			arr[cur] = word[i];
			func(cur + 1, i + 1);
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;

	for (int i = 0; i < C; ++i)
	{
		cin >> word[i];
	}
	sort(word, word + C);
	func(0, 0);
}