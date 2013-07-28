/*ID:xdzhou3
LANG:C++
TASK:transform
*/
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("transform.in");
ofstream fout("transform.out");
struct matrix
{
    char c[10][10];
};
matrix rote(matrix s,int n)
{
    matrix temp;
    for(int i =0;i<n;i++)
     {
        for(int j = 0;j<n;j++)
        {
            temp.c[i][j] = s.c[n-j-1][i];
        }
    }
    return temp;
    /*for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
        {
            s->c[i][j] =temp.c[i][j];
        }*/
}
matrix refl(matrix s,int n)
{
    matrix temp;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            temp.c[i][j]=s.c[i][n-j-1];
        }
    }
    return temp;
}
bool equals(matrix a,matrix b,int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(a.c[i][j]!=b.c[i][j])
                return false;
        }
    return true;
}
int main()
{
    matrix trans[8],end;
    int i,j,N;
    bool comp = false;
    fin >> N;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
             fin >> trans[0].c[i][j];
        }
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
         {
             fin >> end.c[i][j];
         }
    trans[1]=rote(trans[0],N);
    trans[2]=rote(trans[1],N);
    trans[3]=rote(trans[2],N);
    trans[4]=refl(trans[0],N);
    trans[5]=rote(trans[4],N);
    trans[6]=rote(trans[5],N);
    trans[7]=rote(trans[6],N);
    for(i=1;i<8;i++)
    {
        if(equals(end,trans[i],N))
        {
            if(i<5)
             {
                fout << i<< endl;
                comp = true;
                break;
             }
            else
            {
                fout << 5 << endl;
                comp = true;
                break;
            }
        }
    }
    if(equals(end,trans[0],N)&&comp==false)
     {
         comp = true;
         fout << 6 << endl;
     }
    if(comp==false)
        fout << 7 << endl;
    /*for(i =0;i<N;i++)
        for(j=0;j<N;j++)
            cout << trans[4].c[i][j];*/
    return 0;
}
