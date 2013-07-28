/*ID:xdzhou3
LANG:C++
TASK:barn1
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
ifstream fin("barn1.in");
ofstream fout("barn1.out");
int cmp(const void* a,const void*b)
{
    return *(int *)a>*(int *)b?1:-1;
}
int cmp1(const void* a,const void*b)
{
     return *(int *)a>*(int *)b?-1:1;
}
//    qsort(wt,N,sizeof(wt[0]),cmp);
int main()
{
    int M,S,C,i;
    int length;
    fin >> M >> S >> C;
    int *stall_number = new int[C];
    int *hole = new int[C-1];
    for(i=0;i<C;i++)
    {
        fin >> stall_number[i];
    }
    qsort(stall_number,C,sizeof(stall_number[0]),cmp);
    length = stall_number[C-1]-stall_number[0]+1;
    for(i=0;i<C-1;i++)
    {
        hole[i]=stall_number[i+1]-stall_number[i]-1;
    }
    qsort(hole,C-1,sizeof(hole[0]),cmp1);
    for(i=0;i<M-1&&i<C-1;i++)
    {
        length -= hole[i];
    }
    fout << length << endl;
    return 0;
}
