#include <iostream>
using namespace std;

char Check(int x_1, int y_1, int p_1, int q_1, int x_2, int y_2, int p_2, int q_2)
{
	if (p_1 < x_2 || q_1 < y_2 || p_2 < x_1 || q_2 < y_1)
		return 'd';
	int inter_x = max(x_1, x_2);
	int inter_y = max(y_1, y_2);
	int inter_p = min(p_1, p_2);
	int inter_q = min(q_1, q_2);

	int w = inter_p - inter_x;
	int h = inter_q - inter_y;
	
	if (w > 0 && h > 0)
		return 'a';
	else
	{
		if (w == 0 && h == 0)
			return 'c';
		if (w == 0 || h == 0)
			return 'b';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	char answer;

	for (int i = 0; i < 4; ++i)
	{
		int x_1, y_1, p_1, q_1, x_2, y_2, p_2, q_2;
		cin >> x_1 >> y_1 >> p_1 >> q_1 >> x_2 >> y_2 >> p_2 >> q_2;

		cout << Check(x_1, y_1, p_1, q_1, x_2, y_2, p_2, q_2) << "\n";
	}
}