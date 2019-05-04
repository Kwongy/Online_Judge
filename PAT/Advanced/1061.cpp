#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 
string day[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
 
 
int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
 
	int i,d,h,m;
 
	for (i = 0; i < s1.size() && i < s2.size(); ++i)
	{
		if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
		{
			d = (s1[i]-'A');
			break;
		}
	}
 
	++i;
	for (; i < s1.size() && s2.size(); ++i)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] >= '0' && s1[i] <= '9')
			{
				h = s1[i] - '0';
				break;
			}
			else
			{
				if (s1[i] >= 'A' && s1[i] <= 'N')
				{
					h = s1[i] - 'A' + 10;
					break;
				}
			}
		}
	}
 
	for (i = 0; i < s3.size() && i < s4.size(); ++i)
	{
		if (s3[i] == s4[i])
		{
			if ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))
			{
				m = i;
				break;
			}
		}
	}
 
	printf("%s %02d:%02d\n",day[d].c_str(),h,m);
 
 
	system("pause");
	return 0;
}
