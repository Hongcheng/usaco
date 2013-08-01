/*ID:xdzhouh3
LANG:C++
TASK:checker
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <math.h>
using namespace std;
ifstream fin("checker.in");
ofstream fout("checker.out");
// int cmp(const void* a,const void*b)
// {
//     return (*(worktime *)a).t1>(*(worktime *)b).t1?1:-1;
// }
//     qsort(wt,N,sizeof(wt[0]),cmp);
int answer[20];
int ans= 0;
int thresh;
int dfstm = 0;
int n;

void dfs(int row,int c,int ld,int rd)
{//cout << dfstm++ << endl;
    int i,j,temp,ldtemp,rdtemp;
    int col;
    bool flag;
    if(row < n)
    {
        col = 0x00000001;
        while(true)
        {
            flag = true;
            ldtemp = col << row;
            rdtemp = col << (n - row);
            if(col & c || ldtemp & ld || rdtemp & rd)
            {
                flag = false;
            }
            if(flag)
            {
                c = c | col;
                ld = ld | ldtemp;
                rd = rd | rdtemp;
                if(ans < 3)
                {
                    j = 0;
                    temp = col;
                    while(temp > 0)
                    {
                        j++;
                        temp = temp >> 1;
                    }
                    answer[row] = j;
                }
                dfs(row+1,c,ld,rd);
                c = c^col;
                ld = ld ^ ldtemp;
                rd = rd ^ rdtemp;
            }
            if(col < thresh)
                col = col << 1;
            else
                break;
        }
    }
    else
    {
        if(ans < 3)
        {
            for(i = 0;i< n;i++)
            {
                if(i == 0)
                    fout<< answer[0];
                else
                    fout<< " " << answer[i];
            }
            fout << endl;
        }
        ans++;
    }
    // if(row < n)
    // {
    //     col = 0x00000001;
    //     while(true)
    //     {
    //         flag = true;
    //         for(i = 0;i<row;i++)
    //         {
    //             if(col & status[i])
    //             {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if(flag)
    //         {
    //             for(i = row-1;i>=0;i--)
    //             {
    //                 if(status[i]<<(row-i) & col)
    //                 {
    //                     flag = false;
    //                     break;
    //                 }
    //                 if(status[i]>>(row-i) & col)
    //                 {
    //                     flag = false;
    //                     break;
    //                 }
    //             }
    //         }
    //         if(flag)
    //         {
    //             status[row] = col;
    //             dfs(row+1,status);
    //         }
    //         if(col < (0x00000001 << (n-1)))
    //             col = col << 1;
    //         else
    //             break;
    //     }
    // }
    // else
    // {
    //     if(ans < 3)
    //     {
    //         for(i = 0;i<n;i++)
    //         {
    //             j = 0;
    //             temp = status[i];
    //             while(temp > 0)
    //             {
    //                 j++;
    //                 temp = temp >> 1;
    //             }
    //             if(i == 0)
    //                 fout << j;
    //             else
    //                 fout << " " << j;
    //         }
    //         fout << endl;
    //     }
    //     ans++;
    // }
}
int main()
{
    //int status[20];
    //int c,ld,rd;
    //memset(status,0x0000000,sizeof(status[0])*20);
    //cout << status[7] << endl;
    fin >> n;
    //int a = 0x40000000;
    //a = a  >> 1;
    //cout << a << endl;
    thresh = 0x00000001 << (n-1);
    dfs(0,0,0,0);
    fout << ans << endl;
    return 0;
}
