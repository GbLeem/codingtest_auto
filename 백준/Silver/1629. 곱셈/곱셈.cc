#include <iostream>
using namespace std;

long long func1(long long a, long long b, long long m)
{
	if (b == 1)
		return a % m;

	long long val = func1(a, b / 2, m);

	//a^2m = a^m * a^m 
	val = val * val % m;

	if (b % 2 == 0) //짝수이면
		return val;

	return val * a % m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, B, C;

	cin >> A >> B >> C;
	cout << func1(A, B, C);
}