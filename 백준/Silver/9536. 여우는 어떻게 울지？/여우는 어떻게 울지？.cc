#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;
string str;
string input;

vector<string> split(string& input, string& cmp)
{
	vector<string> ret;
	int pos = 0;
	while (pos < input.size())
	{
		int nxt_pos = input.find(cmp, pos);
		if (nxt_pos == -1)
			nxt_pos = input.size();
		if (nxt_pos - pos > 0)
			ret.push_back(input.substr(pos, nxt_pos - pos));
		pos = nxt_pos + cmp.size();
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	getline(cin, str);
	
	while (t--)
	{
		getline(cin, str);
		
		vector<string> vec;
		vector<string> temp;

		while (1)
		{
			getline(cin, input);
			if (input == "what does the fox say?")
				break;
			vec.push_back(input);
		}
		
		string cmp = " ";
		string answer;
		vector<string> output = split(str, cmp);
		
		for (int i = 0; i < vec.size(); ++i)
		{
			int idx = vec[i].find("goes");
			string sound = vec[i].substr(idx + 5);
			
			for (int i = 0; i < output.size(); ++i)
			{
				if (output[i] == sound)
					output[i] = "!";
			}			
		}	
		for (const auto& o : output)
		{
			if (o != "!")
			{
				answer += o;
				answer += " ";
			}
		}
		cout << answer;
	}
}