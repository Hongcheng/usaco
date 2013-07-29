/*ID:xdzhouh3
LANG:C++
TASK:ariprog
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
  class result
 {
 public:
    int a;
    int b;
 };
 int cmp(const void* a,const void*b)
 {
     return (*(int *)a)>(*(int *)b)?1:-1;
 }
 int cmp1(const void* a,const void*b)
{
    if((*(result *)a).b!=(*(result *)b).b)
        return (*(result *)a).b>(*(result *)b).b?1:-1;
    else
        return (*(result *)a).a>(*(result *)b).a?1:-1;
}

int list[40001];
bool exist[125001];
result re[1000];
int main()
{
    int n,m,i,j,k,listlen=0,temp,relen=0,diff,start;
    bool hasthis,flag;
    memset(exist,0,sizeof(exist));
    fin >> n >> m;
    for(i = 0;i<=m;i++)
    {
        for(j=i;j<=m;j++)
        {
            temp = i*i+j*j;
            exist[temp] = true;
            hasthis = false;
            for(k = 0;k<listlen;k++)
            {
                if(temp == list[k])
                {
                    hasthis = true;
                    break;
                }
            }
            if(hasthis == false)
            {
                list[listlen] = temp;
                listlen++;
            }
        }
    }
    qsort(list,listlen,sizeof(list[0]),cmp);
    for(i=0;i<=listlen-n+1;i++)
    {
        for(j=i+n-1;j<=listlen;j++)
        {
            if((list[j]-list[i])>=(n-1) &&(list[j]-list[i])%(n-1) == 0)
            {
                start = list[i];
                diff = (list[j]-list[i])/(n-1);
                flag = true;
                for(k=0;k<n;k++)
                {
                    if(exist[start+k*diff]==false)
                        flag = false;
                }
                if(flag == true)
                {
                    re[relen].a = start;
                    re[relen].b = diff;
                    relen++;
                }
            }
        }
    }
    qsort(re,relen,sizeof(re[0]),cmp1);
    // for(i=0;i<listlen;i++)
    // {
    //     cout << list[i] << " ";
    // }
    // cout << endl;
    for(i = 0;i<relen;i++)
    {
        fout << re[i].a << " " << re[i].b << endl;
    }
    if(relen == 0)
        fout << "NONE" << endl;
    return 0;
}
