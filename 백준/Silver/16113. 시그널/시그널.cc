#include <iostream>
#include <string>
using namespace std;

string str;
string answer;
int num;
char arr[5][20'002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> num;
	cin >> str;
	
	int maxW = str.size() / 5;
	int h = 0;
	int w = 0;

	for (int i = 0; i < str.size(); ++i)
	{
		if (i % maxW == 0 && i != 0)
		{
			h++;
			w = 0;
		}
		arr[h][w] = str[i];
		w++;
	}

	int value1 = 0;
	for (int j = 0; j < maxW; ++j)
	{		
		if (value1 == 0)
		{
			for (int i = 0; i < 5; ++i)
			{
				if (arr[i][j] == '#')
					value1++;
			}		
		}
		else
		{
			int value2 = 0;
			int value3 = 0;
			for (int i = 0; i < 5; ++i)
			{
				if (arr[i][j] == '#')
					value2++;
			}			
			if (value1 == 5 && value2 == 0)
			{
				answer += "1";
				value1 = 0;
				continue;
			}
			for (int i = 0; i < 5; ++i)
			{
				if (arr[i][j + 1] == '#')
					value3++;
			}			
			if (value1 == 5 && value2 == 2 && value3 == 5)
				answer += "0";
			else if (value1 == 4 && value2 == 3 && value3 == 4 && arr[1][j - 1] == '.')
				answer += "2";
			else if (value1 == 3 && value2 == 3 && value3 == 5)
				answer += "3";
			else if (value1 == 3 && value2 == 1 && value3 == 5)
				answer += "4";
			else if (value1 == 4 && value2 == 3 && value3 == 4)
				answer += "5";
			else if (value1 == 5 && value2 == 3 && value3 == 4)
				answer += "6";
			else if (value1 == 1 && value2 == 1 && value3 == 5)
				answer += "7";
			else if (value1 == 5 && value2 == 3 && value3 == 5)
				answer += "8";
			else if (value1 == 4 && value2 == 3 && value3 == 5)
				answer += "9";
			value1 = 0;
			j++;
			/*if (j >= maxW)
				break;*/
		}
	}
	if (value1 != 0)
		answer += "1";
	cout << answer;
	//0  1  2  3  4  5  6   7  8   9 
  	//12 5  11 11 9  11 12  7  13  12
	
	//5 2 5
	//5 0
	//4 3 4
	//3 3 5
	//3 1 5
	//4 3 4
	//5 3 4
	//1 1 5
	//5 3 5
	//4 3 5

	//###.###.....#
	//#.#...#.....# 
	//###...#.....#
	//#.#...#.....#
	//###...#.....#
}