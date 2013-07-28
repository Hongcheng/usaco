/*
	ID: lvxiao31
	PROG: beads
	LANG: C++
*/
#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("beads.in");
ofstream fout("beads.out");

int main()
{
    char str[700],c='0';
    int n,w=0,t=0,l=0,ans=0;
    fin >> n >> str;
    memcpy(str+n,str,n);
    for(int i = 0;i<2*n;i++)
    {
        if(str[i]=='w')
        {
            w++;
            t++;
        }
        else if(str[i]==c)
        {
            t++;
            w=0;
        }
        else
        {
            if(l+t>ans)
                ans = l+t;
            c=str[i];
            l = t-w;
            t=w+1;
            w=0;
        }
    }
    if(l+t>ans)
        ans = l+t;
    fout << (ans>n?n:ans) << endl;
	return 0;
}
