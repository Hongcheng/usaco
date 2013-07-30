/*ID:xdzhouh3
LANG:C++
TASK:milk3
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
ifstream fin("milk3.in");
ofstream fout("milk3.out");
int cmp(const void* a,const void*b)
{
    return (*(int *)a)>(*(int *)b)?1:-1;
}
int ans=0;
int answer[10000];
int status[10000][3];
int va,vb,vc;
void milk3dfs(int a,int b,int c)
{
    int i;
    for(i = 0;i<ans;i++)
    {
        if(status[i][0] == a && status[i][1] == b && status[i][2] == c)
            return;
    }
    status[ans][0] = a;
    status[ans][1] = b;
    status[ans][2] = c;
    ans++;
    if(a > 0 && b < vb)
    {
        milk3dfs(max(0,a - (vb - b)), b + a - max(0,a - (vb - b)), c);
    }
    if(a > 0 && c < vc)
    {
        milk3dfs(max(0,a - (vc - c)), b, c + a - max(0,a - (vc - c)));
    }
    if(b > 0 && a < va)
    {
        milk3dfs(a + b - max(0, b - (va -a)), max(0, b - (va -a)), c);
    }
    if(b > 0 && c < vc)
    {
        milk3dfs(a, max(0,b - (vc - c)), c + b - max(0,b - (vc - c)));
    }
    if(c > 0 && a < va)
    {
        milk3dfs(a + c - max(0, c - (va - a)), b, max(0, c - (va - a)));
    }
    if(c > 0 && b < vb)
    {
        milk3dfs(a, b + c - max(0, c - (vb - b)), max(0, c - (vb - b)));
    }
}
int main()
{
    cin >> va >> vb >> vc;
    milk3dfs(0,0,vc);
    int i,num = 0;
    //cout << ans << endl;
    for(i = 0;i< ans;i++)
    {
        if(status[i][0] == 0)
        {
            answer[num++] = status[i][2];
        }
        // for(int j = 0;j<3;j++)
        // {
        //     cout << status[i][j] << " ";
        // }
        // cout << endl;
    }
    qsort(answer,num,sizeof(answer[0]),cmp);
    for(i = 0;i< num;i++)
    {
        if(i == 0)
            cout << answer[i];
        else
            cout << " " << answer[i];
    }
    cout << endl;
    return 0;
}
