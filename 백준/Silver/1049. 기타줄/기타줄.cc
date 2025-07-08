#include <iostream>
#include <climits>
using namespace std;

int N, M;
int MinSum = INT_MAX;
int MinOne = INT_MAX;
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M; //끊어진 수, 브랜드

	for (int i = 0; i < M; ++i)
	{
		int sum, one;
		cin >> sum >> one;
		//6개짜리 가성비
		MinSum = min(sum, MinSum);
		MinSum = min(MinSum, one * 6);
		//1개짜리 가성비
		MinOne = min(one, MinOne);
	}

	//6개 짜리 세트로 빼기
	if (N >= 6)
	{
		answer += (N / 6) * MinSum;
		N = N % 6;
	}
	if(N != 0)
	{
		answer += min(N * MinOne, MinSum);
	}
	cout << answer;
}