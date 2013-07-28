/*ID:xdzhou3
LANG:C++
TASK:milk2
*/
#include <fstream>
#include <stdlib.h>
using namespace std;
ifstream fin("milk2.in");
ofstream fout("milk2.out");
struct worktime{
int t1;
int t2;
};
int cmp(const void* a,const void*b)
{
    return (*(worktime *)a).t1>(*(worktime *)b).t1?1:-1;
}
int main()
{
    int i=0,N;
    fin >> N;
 //   int *t1 = new int[N];
  //  int *t2 = new int[N];
    worktime  *wt = new worktime[N];
    while(i<N)
    {
        fin >> wt[i].t1>>wt[i].t2;
        i++;
    }
    qsort(wt,N,sizeof(wt[0]),cmp);
    int start = wt[0].t1,end = wt[0].t2,maxmilk = end-start,maxunmilk = 0;
    for(i = 1;i<N;i++)
    {
        if(wt[i].t1<=end)
         {
            if(wt[i].t2>end)
                end = wt[i].t2;
         }
        else
        {
            if(end-start>maxmilk)
                maxmilk = end-start;
            if(wt[i].t1-end>maxunmilk)
                maxunmilk = wt[i].t1-end;
            start = wt[i].t1;
            end = wt[i].t2;
        }
    }
    fout << maxmilk << " "<<maxunmilk << endl;
    return 0;
}
