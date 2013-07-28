/*ID:xdzhou3
LANG:C++
TASK:calfflac
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
ifstream fin("calfflac.in");
ofstream fout("calfflac.out");
int main()
{
    int length,ai,bi,i,j,starta,enda,startb,endb,i1,i2;
    char a[20005],b[20005],c,t1,t2;
    int ba[20005];
    string str="";
    ai= 0;
    bi =0;
    while(!fin.eof())
    {
        c = fin.get();
        a[ai]=c;
        if(c>='a'&&c<='z')
        {
            b[bi]=c;
            ba[bi]=ai;
            bi++;
       }
        else
        if(c>='A'&&c<='Z')
        {
            b[bi]=c+'a'-'A';
            ba[bi]=ai;
            bi++;
        }
        ai++;
    }
 //   cout << bi << endl;
    length = 0;
    if(b[0]==b[1])
    {
        startb=0;
        endb = 1;
    }
    for(i=1;i<bi-1;i++)
    {
        /******ou******/
        i1=i;
        i2 = i+1;
        while(i1>=0&&i2<bi)
        {
            if(b[i1]==b[i2])
            {
                i1--;
                i2++;
            }
            else
            {
                break;
            }
        }
        if(i2-i1-2>length)
        {
            startb = i1+1;
            endb = i2-1;
            length = endb - startb;
        }
        /*********ji**********/
        i1 = i-1;
        i2 = i+1;
        while(i1>=0&&i2<bi)
        {
            if(b[i1]==b[i2])
            {
                i1--;
                i2++;
            }
            else
            {
                break;
            }
        }
        if(i2-i1-2>length)
        {
            startb = i1+1;
            endb = i2-1;
            length = endb - startb;
        }
        //while()
    }
 //   cout << startb << endb << endl;
 //   cout << length << endl;
    starta = ba[startb];
    enda = ba[endb];
 //   cout << starta << enda << endl;
    fout << length+1 << endl;
    for(i=starta;i<=enda;i++)
        fout << a[i];
    fout << endl;
//    length = b.size();
 //   cout << length << endl;
//    cout << a << endl;
 //   cout << b << endl;
    return 0;
}
