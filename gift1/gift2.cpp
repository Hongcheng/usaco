/*ID:xdzhou3
LANG:C++
TASK:gift1
*/

#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	int NP,come[10]={0};
	int money,personnumber,addmoney;
	int i,j,k;
	string name[10];
	string testname;
	fin >> NP;
	for(i = 0;i<NP;i++)
		fin >> name[i];
	for(i = 0;i<NP;i++)
	{
		fin >> testname;
		for(j =0;j<NP;j++)
			if(testname == name[j])
			{
				break;
			}
		fin >> money >> personnumber;
		if(personnumber == 0)
            continue;
		come[j] -=money;
		come[j] +=money%personnumber;
        addmoney = money/personnumber;
		for(j = 0;j<personnumber;j++)
		{
			fin >> testname;
			for(k = 0;k<NP;k++)
			{
				if(name[k] == testname)
				{
					come[k] += addmoney;
					break;
				}
			}
		}
	}
	for(i = 0;i<NP;i++)
		fout << name[i] <<" " << come[i] << endl;
	return 0;
}
