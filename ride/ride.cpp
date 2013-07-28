/*ID:xdzhou3
LANG:C++
TASK:ride
*/
#include <fstream>
using namespace std;
ifstream fin("ride.in");
ofstream fout("ride.out");
int main()
{
	int a[2] ={1,1},i,j;
	char s[7];
	for(i = 0;i<=1;i++)
	{
		fin>>s;
		for(j=0;s[j]!='\0';j++)
			a[i]*=s[j]-'@';
	}	
	if((a[0]-a[1])%47)
		fout << "STAY"<< endl;
	else
		fout << "GO" << endl;
	return 0;
}
