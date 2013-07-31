/*ID:xdzhouh3
LANG:C++
TASK:pprime
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <math.h>
using namespace std;
ifstream fin("pprime.in");
ofstream fout("pprime.out");
// int cmp(const void* a,const void*b)
// {
//     return (*(worktime *)a).t1>(*(worktime *)b).t1?1:-1;
// }
//     qsort(wt,N,sizeof(wt[0]),cmp);
bool Palind(int n)
{
    int newn = 0,oldn = n;
    while(n != 0)
    {
        newn = newn * 10 + n%10;
        n /= 10;
    }
    if(newn == oldn)
        return true;
    else
        return false;
}
int pri[1300],prin = 0;
int main()
{
    int i,j,sqr,a,b;
    bool flag;
    for(i = 2;i<10000;i++)
    {
        flag = true;
        sqr = (int)sqrt((double)i);
        for(j = 2;j<=sqr;j++)
        {
            if(i%j == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            pri[prin] = i;
            prin++;
        }
    }
    fin >> a >> b;
    if(b > 10000000)
        b = 10000000;
    for(i = a; i<= b;i++)
    {
        if(i%2 == 0)
            continue;
        if(!Palind(i))
            continue;
        flag = true;
        for(j = 0;j<prin&&pri[j]<i;j++)
        {
            if(i%pri[j] == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            fout << i << endl;
    }

    return 0;
}
