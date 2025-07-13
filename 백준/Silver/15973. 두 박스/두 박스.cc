#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int bigX[2];
int bigY[2];

unordered_map<string, vector<int>> pos;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 2; ++i)
	{
		int x_1, y_1, x_2, y_2;	
		cin >> x_1 >> y_1 >> x_2 >> y_2;	

		vector<int> temp;
		temp.push_back(x_1);
		temp.push_back(y_1);
		temp.push_back(x_2);
		temp.push_back(y_2);

		string tempX = to_string(x_2) + "x";
		string tempY = to_string(y_2) + "y";
		pos[tempX] = temp;
		pos[tempY] = temp;

		bigX[i] = x_2;		
		bigY[i] = y_2;
	}	

	sort(bigX, bigX + 2);
	sort(bigY, bigY + 2);

	//만나는 갯수
	int compX = -1;
	int compY = -1;

	//x좌표 비교
	string tempX = to_string(bigX[1]) + "x";
	int smallX = pos[tempX][0];
	if (bigX[0] > smallX)
	{
		compX = 2;
	}
	else if (bigX[0] == smallX)
	{
		compX = 1;
	}
	else
	{
		compX = 0;
	}

	//y좌표 비교
	string tempY = to_string(bigY[1]) + "y";
	int smallY = pos[tempY][1];
	if (bigY[0] > smallY)
	{
		compY = 2;
	}
	else if (bigY[0] == smallY)
	{
		compY = 1;
	}
	else
	{
		compY = 0;
	}

	if (compX == 0 || compY == 0)
		cout << "NULL";
	else if (compY + compX == 2)
		cout << "POINT";
	else if (compX + compY == 3)
		cout << "LINE";
	else
		cout << "FACE";
}

