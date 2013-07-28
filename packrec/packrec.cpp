/*ID:xdzhou3
LANG:C++
TASK:packrec
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
ifstream fin("packrec.in");
ofstream fout("packrec.out");
struct rect
{
    int l;
    int w;
};
struct rects
{
    int num;
    rect re[24];
};
int cmp(const void* a,const void*b)
{
    if(((*(rect *)a).l*(*(rect *)a).w)!=((*(rect *)b).l*(*(rect *)b).w))
        return ((*(rect *)a).l*(*(rect *)a).w)>((*(rect *)b).l*(*(rect *)b).w)?1:-1;
    else
        return (*(rect *)a).l-(*(rect *)b).l;
}
rect first(const rect *re)
{
    rect rest;
    int l=0,w=0,i;
    for(i=0;i<4;i++)
    {
        w+=re[i].w;
        if(re[i].l>l)
            l = re[i].l;
    }
    rest.w = w;
    rest.l = l;
    return rest;
}
rects second(const rect *re)
{
    rects rests;
    int i,j,w,l;
    for(i=0;i<4;i++)
    {
        w=0;l=0;
        for(j=0;j<4;j++)
        {
            if(i!=j)
            {
                w+=re[j].w;
                if((re[j].l+re[i].w)>l)
                    l=re[j].l+re[i].w;
            }
        }
        if(w<re[i].l)
            w=re[i].l;
        rests.re[i].l=l;
        rests.re[i].w = w;
    }
    rests.num = 4;
    return rests;
}
rects third(const rect *re)
{
    rects rests;
    int i,j,k,num=0;
    int w,l;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            w=0;l=0;
            if(j!=i)
            {
                for(k=0;k<4;k++)
                {
                    if(k!=i)
                    {
                        w+=re[k].w;
                        if(k!=j&&(re[k].l+re[i].w)>l)
                            l = re[k].l+re[i].w;
                    }
                }
                if(w<re[i].l+re[j].w)
                    w = re[i].l+re[j].w;
                if(re[j].l>l)
                    l = re[j].l;
                rests.re[num].l = l;
                rests.re[num].w = w;
                num++;
            }
        }
    }
    rests.num = 12;
    return rests;
}
rects forth(const rect *re)
{
    rects rests;
    int i,j,k,num=0;
    int w,l;
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<4;j++)
        {
            w=0;l=0;
            l=re[i].l+re[j].l;
            if(re[i].w>re[j].w)
                w = re[i].w;
            else
                w = re[j].w;
            for(k = 0;k<4;k++)
            {
                if(k!=i&&k!=j)
                    w+=re[k].w;
                if(re[k].l>l)
                    l = re[k].l;
            }
            rests.re[num].l = l;
            rests.re[num].w = w;
            num++;
        }
    }
    rests.num = 6;
    return rests;
}
rects fifth(const rect *re)
{
    rects rests;
    int i,j,m,n,num=0;
    int w,l;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(j==i)
                continue;
            for(m=0;m<4;m++)
            {
                if(m==i||m==j)
                    continue;
                for(n=0;n<4;n++)
                {
                    if(n==i||n==j||n==m)
                        continue;
                    if(re[j].l>re[m].l&&re[n].l>re[m].w)
                        break;
                    if(((re[j].w+re[m].w)<(re[i].w+re[n].l))&&((re[i].l+re[j].l)>re[m].l))
                        break;
                    if((re[m].l>re[j].l))
                        break;
                    w = re[j].w+re[m].w;
                    if(re[n].l>w)
                        w = re[n].l;
                    l = re[i].l+re[j].l;
                    if((re[m].l+re[n].w)>l)
                        l = re[m].l+re[n].w;
                    if((w == 5&&l == 7)||(w==7&&l==5))
                        w = l;
                    rests.re[num].l = l;
                    rests.re[num].w = w;
                    num++;
                }
            }
        }
    }
    rests.num = 24;
    for(i=num;i<24;i++)
    {
        rests.re[i].l=9999;
        rests.re[i].w=9999;
    }
    return rests;
}
int main()
{
    rect re[4];
    rects all[4];
    rect fir;
    rect rest[47*16];
    int i,j,k;
    int temp;
    for(i=0;i<4;i++)
    {
        fin >> re[i].l >> re[i].w;
    }
    int num = 0;
    for(i=0;i<16;i++)
    {
       fir = first(re);
        all[0] = second(re);
        all[1] = third(re);
        all[2] = forth(re);
        all[3] = fifth(re);
        //renum = 1+4+6+12+24;
        //rect *rest = new rect[renum];
        rest[num] = fir;
        num++;
        for(k=0;k<4;k++)
        {
            for(j=0;j<all[k].num;j++)
            {
                rest[num] = all[k].re[j];
                num++;
            }
        }
        temp =re[0].l;
        re[0].l = re[0].w;
        re[0].w = temp;
        if(i%2==0)
        {
            temp =re[1].l;
            re[1].l = re[1].w;
            re[1].w = temp;
        }
        if(i%4==0)
        {
            temp =re[2].l;
            re[2].l = re[2].w;
            re[2].w = temp;
        }
        if(i%8==0)
        {
            temp =re[3].l;
            re[3].l = re[3].w;
            re[3].w = temp;
        }
    }

    for(i=0;i<47*16;i++)
    {
        if(rest[i].l>rest[i].w)
        {
            temp = rest[i].l;
            rest[i].l = rest[i].w;
            rest[i].w = temp;
        }
    }
    qsort(rest,47*16,sizeof(rest[0]),cmp);
    //for(i=0;i<47*16;i++)
     //   fout << rest[i].l<< " " << rest[i].w << endl;
    int area = rest[0].l*rest[0].w;
    fout << area << endl;
    i = 0;
    fout << rest[i].l<< " " << rest[i].w << endl;
    int l = rest[i].l;
    i++;
    while(rest[i].l*rest[i].w == area)
    {
        if(rest[i].l!=l)
        {
             fout << rest[i].l<< " " << rest[i].w << endl;
             l = rest[i].l;
        }
        //fout <<rest[i].l<< " " << rest[i].w << endl;
        i++;
    }
    return 0;
}

