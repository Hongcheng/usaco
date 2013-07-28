/*ID:xdzhou3
LANG:C++
TASK:friday
*/
#include <fstream>
using namespace std;
ifstream fin("friday.in");
ofstream fout("friday.out");
bool leapyear(int year)
{
    if((year%4 == 0&&year%100!=0)||year==2000)
        return true;
    else
        return false;
}
int main()
{
        int N,i,j;
        int day[7] = {0};
        int today=6;
        int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        fin >> N;
        for(i= 0;i<N;i++)
        {
            if(leapyear(1900+i))
                month[1] = 29;
            else
                month[1] = 28;
           for(j=0;j<12;j++)
            {
                day[today]++;
                today = today+month[j];
                today = today%7;
            }
            today = today;
        }
        fout << day[6] ;
        for(i = 0;i<6;i++)
            fout << " " << day[i];
        fout << endl;
        return 0;
}
