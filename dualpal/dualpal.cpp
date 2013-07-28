/*ID:xdzhou3
LANG:C++
TASK:dualpal
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
ifstream fin("dualpal.in");
ofstream fout("dualpal.out");
const char code[10]={'0','1','2','3','4','5','6','7','8','9'};
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
    int N,S,i,j;
    fin >> N >> S;
    i = 0;
    while(i<N)
    {
        S+=1;
        int num = 0;
        string str;
        for(j = 2;j<11;j++)
        {
            if(is_palsquare(coverse(S,j)))
            {
                num++;
            }
            if(num>=2)
            {
                fout << S << endl;
                i++;
                break;
            }
        }
    }
    return 0;
}
