#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
const int ROOT = 1;
int unused = 2;
const int MX = 500 * 80 + 5;

unordered_map<string, int> nxt[MX]; //v번 노드 중 자식 이름이 r
int depth[MX];
string name[MX];



vector<string> split(string& s, string& sep)
{
	vector<string> ret;

	while (s.find(sep) != -1)
	{
		ret.push_back(s.substr(0, s.find(sep)));
		s.erase(0, s.find(sep) + sep.size());
	}

	ret.push_back(s);

	return ret;
}

void insert(vector<string>& vec)
{
	int cur = ROOT;
	for (auto v : vec)
	{
		int s = nxt[cur][v];
		if (s == 0)
			s = nxt[cur][v] = unused++;
		depth[s] = depth[cur] + 1;
		name[s] = v;
		cur = s;
	}	
}

void print(int cur)
{
	if (cur != ROOT)
	{
		for (int i = 0; i < depth[cur]; ++i)
			cout << " ";
		cout << name[cur] << "\n";
	}
	vector<pair<string, int>> m(nxt[cur].begin(), nxt[cur].end());
	sort(m.begin(), m.end());
	for (auto mi : m)
		print(mi.second);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	depth[ROOT] = -1;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		string sep = "\\";
		vector<string> temp = split(str, sep);

		insert(temp);
	}
	print(ROOT);
}