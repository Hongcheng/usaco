/*ID:xdzhouh3
LANG:C++
TASK:sprime
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <math.h>
using namespace std;
ifstream fin("sprime.in");
ofstream fout("sprime.out");
// int cmp(const void* a,const void*b)
// {
//     return (*(worktime *)a).t1>(*(worktime *)b).t1?1:-1;
// }
//     qsort(wt,N,sizeof(wt[0]),cmp);
int pri[7][50]={{2,3,5,7}};
int prin[7]={0};
bool beprime(int n)
{
    bool flag;
    int j,sqr;
    flag = true;
    sqr = (int)sqrt((double)n);
    for(j = 2;j<=sqr;j++)
    {
        if(n%j == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    int N;
    fin >> N;
    int i,j;
    prin[0] = 4;
    for(i=1;i<N;i++)
    {
        for(j=0;j<prin[i-1];j++)
        {
            if(beprime(pri[i-1][j]*10 + 1))
             {
                pri[i][prin[i]] = pri[i-1][j] * 10 + 1;
                prin[i]++;
             }
            if(beprime(pri[i-1][j]*10 + 3))
             {
                pri[i][prin[i]] = pri[i-1][j] * 10 + 3;
                prin[i]++;
             }
            if(beprime(pri[i-1][j]*10 + 5))
             {
                pri[i][prin[i]] = pri[i-1][j] * 10 + 5;
                prin[i]++;
             }
            if(beprime(pri[i-1][j]*10 + 7))
             {
                pri[i][prin[i]] = pri[i-1][j] * 10 + 7;
                prin[i]++;
             }
            if(beprime(pri[i-1][j]*10 + 9))
             {
                pri[i][prin[i]] = pri[i-1][j] * 10 + 9;
                prin[i]++;
             }
        }
    }
    for(i = 0; i<prin[N-1];i++)
    {
        fout << pri[N-1][i] << endl;
    }
    // for(i=1;i<N;i++)
    // {
    //     a *= 10;
    // }
    // b = a *10;
    // bool flag;
    // for(i = 2*a;i < b;i++)
    // {
    //     int num = i;
    //     flag = true;
    //     for(j=0;j<N;j++)
    //     {
    //         if(!beprime(num))
    //         {
    //             flag = false;
    //             break;
    //         }
    //         num /= 10;
    //      }
    //      if(flag)
    //         cout << i << endl;
    // }
    return 0;
}
