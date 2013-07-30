/*ID:xdzhouh3
LANG:C++
TASK:numtri
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
ifstream fin("numtri.in");
ofstream fout("numtri.out");
// int cmp(const void* a,const void*b)
// {
//     return (*(worktime *)a).t1>(*(worktime *)b).t1?1:-1;
// }
//     qsort(wt,N,sizeof(wt[0]),cmp);
int R;
int num[1000][1000];
int main()
{
    fin >> R;
    int i,j,maxnum=0;
    for(i =0;i<R;i++)
    {
        for(j = 0;j<=i;j++)
        {
            cin >> num[i][j];
        }
    }
    for(i = 1;i<R;i++)
    {
        for(j = 0;j<=i;j++)
        {
            if(j == 0)
                num[i][0] = num[i-1][0]+num[i][0];
            else if(j == i)
                num[i][j] = num[i-1][j]+num[i][j];
            else
                num[i][j] = max(num[i-1][j-1],num[i-1][j]) + num[i][j];
        }
    }
    for(i = 0;i<R;i++)
    {
        cout << num[R-1][i] << " ";
        if(num[R-1][i] > maxnum)
            maxnum = num[R-1][i];
    }//cout << endl;
    fout << maxnum;
    return 0;
}
