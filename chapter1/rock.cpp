#include <bits/stdc++.h>
using namespace std;
string vil[2][100]; int currcol; int r,c,n;
int xi[4] = {1,0,-1,0};
int yi[4] = {0,1,0,-1};
bool compare(char a,char b)
{
    if( a == 'P')
    return b == 'S';
    else if( a == 'R')
    return b == 'P';
    else
    return b == 'R';
} 
char victor(int x,int y,char a)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        int cx = x + xi[i];
        int cy = y + yi[i];
        if(cx >=0 && cx < r && cy >= 0 && cy < c && compare(a,vil[currcol][cx][cy])) return vil[currcol][cx][cy];
    }
    return a;
}
int main()
{
    int test; cin >> test;
    while(test--)
    {
        cin >> r >> c >> n; currcol = 0;
        for(int i = 0 ; i < r ; i++)
        {
            cin >> vil[0][i];
        }
        while(n--)
        {
            for(int i = 0 ; i < r ; i++)
            {
                vil[1-currcol][i] = "";
                for(int j = 0 ; j < c ; j++)
                {
                    vil[1-currcol][i] += victor(i,j,vil[currcol][i][j]);
                }
            }
            currcol = 1 - currcol;
        }
        for(int i = 0 ; i < r ; i++)
        cout << vil[currcol][i] << endl;
        if(test)
        cout << endl;
    }
}