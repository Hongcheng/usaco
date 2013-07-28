/*ID:xdzhou3
LANG:C++
TASK:palsquare
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");
const char code[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
string coverse(int m,int n)
{
    string ret ="";
    while(m!=0)
    {
        ret=code[m%n]+ret;
        m=m/n;
    }
    return ret;
}
bool is_palsquare(string str)
{
    int j,l;
    l=str.size();
    for(j=0;j<=l/2;j++)
    {
        if(str[j]!=str[l-j-1])
            return false;
    }
    return true;
}
int main()
{
    int n,i,m;
    string str;
    fin >> n;
    for(i=1;i<=300;i++)
    {
        m=i*i;
        str=coverse(m,n);
        if(is_palsquare(str))
        {
            fout << coverse(i,n)<<" "<< str << endl;
        }
    }
    return 0;
}
