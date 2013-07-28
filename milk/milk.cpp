/*ID:xdzhou3
LANG:C++
TASK:milk
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
ifstream fin("milk.in");
ofstream fout("milk.out");
int main()
{
    unsigned int num[1001]={0};
    unsigned int N,M,i,n,m,money;
    fin >> N >> M;
    for(i=0;i<M;i++)
    {
        fin >> n;
        fin >> m;
        num[n]+=m;
    }
    m=0;
    money = 0;
    for(i=0;i<=1000;i++)
    {
        if(num[i]==0)
            continue;
        if(num[i]+m<N)
        {
            money+=i*num[i];
            m+=num[i];
        }
        else
        {
            money+=i*(N-m);
            break;
        }
    }
    fout << money << endl;

    return 0;
}
/*struct milk
{
    int price;
    int number;
};
int cmp(const void* a,const void*b)
{
    return (*(milk *)a).price>(*(milk *)b).price?1:-1;
}
int main()
{
    int N,M,i,j,sum_price;
    fin >> N >> M;
    milk *m = new milk[M];
    sum_price = 0;
    for(i=0;i<M;i++)
    {
        fin >> m[i].price >> m[i].number;
    }
    qsort(m,M,sizeof(m[0]),cmp);
    i = 0;
    j=0;
    while(i<N)
    {
        if(m[j].number+i<=N)
        {
            sum_price+=m[j].price*m[j].number;
            i+=m[j].number;
            j++;
        }
        else
        {
            sum_price+=m[j].price*(N-i);
            break;
        }
    }
    fout << sum_price << endl;
    return 0;
}*/
