//선분이 원과 점 몇개에서 만나는지 체크

#include <iostream>
#include <cmath>
using namespace std;

int T;
int x_1, y_1, x_2, y_2;
int n;

bool Check(int cx, int cy, int r)
{
	int dx = x_2 - x_1;
	int dy = y_2 - y_1;

	int fx = x_1 - cx;
	int fy = y_1 - cy;
	
	double a = dx * dx + dy * dy;
	double b = 2 * (fx * dx + fy * dy);
	double c = fx * fx + fy * fy - r * r;

	double D = b * b - 4 * a * c;

	//원과 두번 겹침
	if (D > 0)
	{
		//하나만 
		double t1 = (-b - sqrt(D)) / (2 * a);
		double t2 = (-b + sqrt(D)) / (2 * a);
		if (t1 >= 0 && t1 <= 1)
		{
			if (t2 < 0 || t2 > 1)
				return true;
			return false;
		}
		else if (t2 >= 0 && t2 <= 1)
		{
			if(t1 < 0 || t1 > 1)
				return true;	
			return false;
		}
		else
			return false;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	
	while (T--)
	{
		int answer = 0;
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		cin >> n;

		while (n--)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;

			if (Check(cx, cy, r))
				answer++;
		}
		cout << answer << "\n";
	}
}