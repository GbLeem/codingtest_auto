#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<pair<string, string>> vec;
char check[52]; //NNNNN
vector<pair<int, int>> result;

void bitmasking()
{
	int answer = INT_MAX;
	int cnt = 0;

	for (int i = 0; i < (1 << vec.size()); ++i)
	{
		fill(check, check + m, 'N');
		cnt = 0;

		for (int j = 0; j < vec.size(); ++j)
		{
			//모든 경우의 수
			if (i & (1 << j))
			{				
				for (int k = 0; k < vec[j].second.size(); ++k)
				{
					//check 배열 바꿔주고
					if(check[k] == 'N')
						check[k] = vec[j].second[k];					
				}				
				//기타 갯수 추가
				cnt++;
			}
		}

		//Y의 갯수
		int cntY = 0;
		for (int k = 0; k < m; ++k)
		{
			if (check[k] == 'Y')
			{
				cntY++;
			}
		}
		result.push_back({ cntY, cnt });
	}

	sort(result.begin(), result.end());
	int maxY = result.back().first;

	for (auto r : result)
	{
		if (r.first == maxY)
			answer = min(answer, r.second);
	}
	
	if (answer == 0)
		cout << -1;
	else
		cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string name, song;
		cin >> name >> song;

		vec.push_back({ name, song });
	}
	
	bitmasking();
}