#include <iostream>
#include <string>
using namespace std;

int N;

int Check(string str)
{
	int idx = str.find(':');
	int m = stoi(str.substr(0, idx));
	int s = stoi(str.substr(idx + 1));

	return m * 60 + s;
}

string Result(int num)
{
	string result;

	string m = to_string(num / 60);
	string s = to_string(num % 60);

	if (m.size() == 2)
		result += m;
	else
	{
		result += "0";
		result += m;
	}
	result += ":";

	if (s.size() == 2)
		result += s;
	else
	{
		result += "0";
		result += s;
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int TeamA = 0;
	int TeamB = 0;

	int TimeA = 0;
	int TimeB = 0;

	int NewTime = -1;

	while (N--)
	{
		int num;
		string time;

		cin >> num >> time;

		//다른 팀
		if (num == 1)
		{
			TeamA++;
		}
		else
		{
			TeamB++;			
		}

		if (TeamA == TeamB)
		{
			if (num == 1)
				TimeB += Check(time) - NewTime;
			else
				TimeA += Check(time) - NewTime;

			NewTime = -1;
		}		
		else
		{
			if (NewTime == -1)
			{
				NewTime = Check(time);
			}
		}
	}
	//마지막 경우
	if (TeamA > TeamB)
	{
		TimeA += Check("48:00") - NewTime;
	}
	else if(TeamB > TeamA)
	{
		TimeB += Check("48:00") - NewTime;
	}
	
	
	cout << Result(TimeA) << "\n" << Result(TimeB);
}