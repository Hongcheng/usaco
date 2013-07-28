/*ID:xdzhou3
LANG:C++
TASK:clocks
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
ifstream fin("clocks.in");
ofstream fout("clocks.out");
/*int cmp(const void* a,const void*b)
{
    return (*(worktime *)a).t1>(*(worktime *)b).t1?1:-1;
}
    qsort(wt,N,sizeof(wt[0]),cmp);*/
int main()
{
    int i;
    int clockstatus[9];
    int c[9];
    for(i = 0;i<9;i++)
    {
        fin >> clockstatus[i];
        if(clockstatus[i] == 12)
            clockstatus[i]=0;
    }
    bool flag = false;
    for(c[8]=0;c[8]<4;c[8]++)
     {
         for(c[7]=0;c[7]<4;c[7]++)
          {
              for(c[6]=0;c[6]<4;c[6]++)
               {
                   for(c[5]=0;c[5]<4;c[5]++)
                    {
                        for(c[4]=0;c[4]<4;c[4]++)
                        {
                            for(c[3]=0;c[3]<4;c[3]++)
                            {
                                for(c[2]=0;c[2]<4;c[2]++)
                                {
                                    for(c[1]=0;c[1]<4;c[1]++)
                                    {
                                        for(c[0]=0;c[0]<4;c[0]++)
                                        {
                                            if(flag == true)
                                                break;
                                            clockstatus[0] = (clockstatus[0]+3)%12;
                                            clockstatus[1] = (clockstatus[1]+3)%12;
                                            clockstatus[3] = (clockstatus[3]+3)%12;
                                            clockstatus[4] = (clockstatus[4]+3)%12;
                                            if(clockstatus[0]==0&&clockstatus[1]==0&&clockstatus[2]==0&&clockstatus[3]==0
                                               &&clockstatus[4]==0&&clockstatus[5]==0&&clockstatus[6]==0&&clockstatus[7]==0&&clockstatus[8]==0)
                                               flag = true;
                                        }
                                        if(flag == true)
                                            break;
                                        clockstatus[0] = (clockstatus[0]+3)%12;
                                        clockstatus[1] = (clockstatus[1]+3)%12;
                                        clockstatus[2] = (clockstatus[2]+3)%12;
                                        if(clockstatus[0]==0&&clockstatus[1]==0&&clockstatus[2]==0&&clockstatus[3]==0
                                               &&clockstatus[4]==0&&clockstatus[5]==0&&clockstatus[6]==0&&clockstatus[7]==0&&clockstatus[8]==0)
                                               flag = true;
                                    }
                                    if(flag == true)
                                        break;
                                    clockstatus[1] = (clockstatus[1]+3)%12;
                                    clockstatus[2] = (clockstatus[2]+3)%12;
                                    clockstatus[4] = (clockstatus[4]+3)%12;
                                    clockstatus[5] = (clockstatus[5]+3)%12;
                                    if(clockstatus[0]==0&&clockstatus[1]==0&&clockstatus[2]==0&&clockstatus[3]==0
                                               &&clockstatus[4]==0&&clockstatus[5]==0&&clockstatus[6]==0&&clockstatus[7]==0&&clockstatus[8]==0)
                                               flag = true;
                                }
                                if(flag == true)
                                    break;
                                clockstatus[0] = (clockstatus[0]+3)%12;
                                clockstatus[3] = (clockstatus[3]+3)%12;
                                clockstatus[6] = (clockstatus[6]+3)%12;
                                if(clockstatus[0]==0&&clockstatus[1]==0&&clockstatus[2]==0&&clockstatus[3]==0
                                               &&clockstatus[4]==0&&clockstatus[5]==0&&clockstatus[6]==0&&clockstatus[7]==0&&clockstatus[8]==0)
                                               flag = true;
                            }
                            if(flag == true)
                                break;
                            clockstatus[5] = (clockstatus[5]+3)%12;
                            clockstatus[1] = (clockstatus[1]+3)%12;
                            clockstatus[3] = (clockstatus[3]+3)%12;
                            clockstatus[4] = (clockstatus[4]+3)%12;
                            clockstatus[7] = (clockstatus[7]+3)%12;
                            if(clockstatus[0]==0&&clockstatus[1]==0&&clockstatus[2]==0&&clockstatus[3]==0
                                               &&clockstatus[4]==0&&clockstatus[5]==0&&clockstatus[6]==0&&clockstatus[7]==0&&clockstatus[8]==0)
                                               flag = true;
                        }
                        if(flag == true)
                            break;
                        clockstatus[2] = (clockstatus[2]+3)%12;
                        clockstatus[5] = (clockstatus[5]+3)%12;
                        clockstatus[8] = (clockstatus[8]+3)%12;
                        if(clockstatus[0]==0&&clockstatus[1]==0&&clockstatus[2]==0&&clockstatus[3]==0
                                               &&clockstatus[4]==0&&clockstatus[5]==0&&clockstatus[6]==0&&clockstatus[7]==0&&clockstatus[8]==0)
                                               flag = true;
                    }
                    if(flag == true)
                        break;
                    clockstatus[3] = (clockstatus[3]+3)%12;
                    clockstatus[4] = (clockstatus[4]+3)%12;
                    clockstatus[6] = (clockstatus[6]+3)%12;
                    clockstatus[7] = (clockstatus[7]+3)%12;
                    if(clockstatus[0]==0&&clockstatus[1]==0&&clockstatus[2]==0&&clockstatus[3]==0
                                               &&clockstatus[4]==0&&clockstatus[5]==0&&clockstatus[6]==0&&clockstatus[7]==0&&clockstatus[8]==0)
                                               flag = true;
               }
               if(flag == true)
                    break;
               clockstatus[6] = (clockstatus[6]+3)%12;
               clockstatus[7] = (clockstatus[7]+3)%12;
               clockstatus[8] = (clockstatus[8]+3)%12;
               if(clockstatus[0]==0&&clockstatus[1]==0&&clockstatus[2]==0&&clockstatus[3]==0
                                               &&clockstatus[4]==0&&clockstatus[5]==0&&clockstatus[6]==0&&clockstatus[7]==0&&clockstatus[8]==0)
                                               flag = true;
          }
          if(flag == true)
                break;
          clockstatus[4] = (clockstatus[4]+3)%12;
          clockstatus[5] = (clockstatus[5]+3)%12;
          clockstatus[7] = (clockstatus[7]+3)%12;
          clockstatus[8] = (clockstatus[8]+3)%12;
          if(clockstatus[0]==0&&clockstatus[1]==0&&clockstatus[2]==0&&clockstatus[3]==0
                                               &&clockstatus[4]==0&&clockstatus[5]==0&&clockstatus[6]==0&&clockstatus[7]==0&&clockstatus[8]==0)
                                               flag = true;
    }
    char str[60];
    int weizhi = 0;
    for(i = 0;i<9;i++)
    {
        if(c[i]>0)
        {
            for(int j = 0;j<c[i];j++)
            {
                str[weizhi] = char(i+49);
                weizhi++;
                str[weizhi]=' ';
                weizhi++;
                //cout << char(i+49) << " ";
            }
        }
    }
    for(i =0;i<weizhi-1;i++)
        fout << str[i];
    fout << endl;
    return 0;
}
