#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<string, int> vis;

bool Check(string comp, string cur)
{
	int cnt = 0;
	int total = cur.size();

	for (int i = 0; i < cur.size(); ++i)
	{
		if (comp[i] == cur[i])
			cnt++;
	}
	if (cnt == total - 1)
		return true;
	return false;
}

int solution(string begin, string target, vector<string> words)
{

	queue<string> q;
	q.push(begin);
	vis[begin] = 1;

	while (!q.empty())
	{
		string cur = q.front();
		q.pop();

		for (int i = 0; i < words.size(); ++i)
		{
			if (vis[words[i]])
				continue;
			if (Check(words[i], cur))
			{
				q.push(words[i]);
				vis[words[i]] = vis[cur] + 1;
			}
		}
	}

    if(vis[target])
	    return vis[target] - 1;
    return 0;
}