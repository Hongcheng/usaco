/*ID:xdzhou3
LANG:C++
TASK:crypt1
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
ifstream fin("crypt1.in");
ofstream fout("crypt1.out");
/*int cmp(const void* a,const void*b)
{
    return (*(worktime *)a).t1>(*(worktime *)b).t1?1:-1;
}
    qsort(wt,N,sizeof(wt[0]),cmp);*/
bool niu(int num[],int N,int test)
{
    int temp,i;
    bool flag;
    while(test>0)
    {
        flag = false;
        temp = test%10;
        for(i=0;i<N;i++)
        {
            if(temp ==num[i])
            {
                flag = true;
                continue;
            }
        }
        if(flag == false)
            return false;
        test=test/10;
    }
    return true;
}
int main()
{
    int N,i,j,count = 0;
    int num[9];
    fin >> N;
    for(i=0;i<N;i++)
    {
        fin >> num[i];
    }
    for(i=100;i<1000;i++)
    {
        for(j=10;j<100&&i*j<10000;j++)
        {
            if(i*(j/10)>999||i*(j%10)>999)
                continue;
            if(niu(num,N,i)&&niu(num,N,j)&&niu(num,N,i*(j/10))&&niu(num,N,i*(j%10))&&niu(num,N,i*j))
                count++;
        }
    }
    fout << count << endl;
    return 0;
}
