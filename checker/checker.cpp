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
int dfstm = 0;
int n;

void dfs(int row,int *status)
{//cout << dfstm++ << endl;
    int i,j,temp;
    int col;
    bool flag;
    if(row < n)
    {
        col = 0x00000001;
        while(true)
        {
            flag = true;
            for(i = 0;i<row;i++)
            {
                if(col & status[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(i = row-1;i>=0;i--)
                {
                    if(status[i]<<(row-i) & col)
                    {
                        flag = false;
                        break;
                    }
                    if(status[i]>>(row-i) & col)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                status[row] = col;
                dfs(row+1,status);
            }
            if(col < (0x00000001 << (n-1)))
                col = col << 1;
            else
                break;
        }
    }
    else
    {
        if(ans < 3)
        {
            for(i = 0;i<n;i++)
            {
                j = 0;
                temp = status[i];
                while(temp > 0)
                {
                    j++;
                    temp = temp >> 1;
                }
                if(i == 0)
                    fout << j;
                else
                    fout << " " << j;
            }
            fout << endl;
        }
        ans++;
    }
}
int main()
{
    int status[20];
    memset(status,0x0000000,sizeof(status[0])*20);
    //cout << status[7] << endl;
    fin >> n;
    //int a = 0x40000000;
    //a = a  >> 1;
    //cout << a << endl;
    dfs(0,status);
    fout << ans << endl;
    return 0;
}
