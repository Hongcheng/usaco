/*ID:xdzhou3
LANG:C++
TASK:namenum
*/
#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;
ifstream fin("namenum.in");
ofstream fout("namenum.out");
ifstream din("dict.txt");
const char code[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
int main()
{
    char a[13],b[13];
    unsigned int i;
    bool flag = false;
    bool flag1;
    fin >> a;
    while(din>>b)
    {
        flag1=true;
        if(strlen(a)!=strlen(b))
            continue;
        for(i=0;i<strlen(a);i++)
        {
            if(code[b[i]-65]!=a[i])
            {
                flag1=false;
                break;
            }
        }
        if(flag1 ==true)
        {
            flag = true;
            fout<<b<<endl;
        }
    }
    if(flag==false)
        fout << "NONE"<<endl;
    return 0;
}
