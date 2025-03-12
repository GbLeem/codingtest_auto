#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes)
{
	int big = 0;
	int small = 0;

	for (int i = 0; i < sizes.size(); ++i)
	{
		sort(sizes[i].begin(), sizes[i].end());
			
		big = max(big, sizes[i][1]);
		small = max(small, sizes[i][0]);
	}
	return big * small;
}