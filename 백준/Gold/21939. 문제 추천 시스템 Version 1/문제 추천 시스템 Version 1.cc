#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;

int n, m;
set<int> s[100'002];
int level[100'002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		int p, l;
		cin >> p >> l; //번호 난이도
		level[p] = l; //번호로 난이도를 찾기 위해서
		s[l].insert(p); //난이도에 따라 문제번호 오름차순 정렬
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;

		if (str == "add")
		{
			int p, l;
			cin >> p >> l;

			level[p] = l;
			s[l].insert(p);
		}
		else if (str == "solved")
		{
			int p;
			cin >> p;
			s[level[p]].erase(p);
		}
		else if (str == "recommend")
		{
			int x;
			cin >> x;
			if (x == 1)
			{
				for (int L = 100; L >= 1; --L)
				{
					if (s[L].empty())
						continue;
					cout << *(--s[L].end()) << "\n";
					break;
				}
			}
			else
			{
				for (int L = 1; L <= 100; ++L)
				{
					if (s[L].empty())
						continue;
					cout << *s[L].begin() << "\n";
					break;
				}
			}
		}
	}
}