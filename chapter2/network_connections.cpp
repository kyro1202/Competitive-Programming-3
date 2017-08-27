#include <bits/stdc++.h>
using namespace std;

int rank[100000];
int p[100000];
void makeset(int a)
{
    rank[a] = 0;
    p[a] = a;
}
int findset(int a)
{
    return p[a] == a ? a : p[a] = findset(a);
}
void makeunion(int a,int b)
{
    int x = findset(a),y = findset(b);
    if(x != y)
    {
        if(rank[x] < rank[y])
        {
            p[x] = y;
        }
        else
        {
            p[y] = x;
            if(rank[x] == rank[y])
            rank[x]++;
        }
    }
}
int main()
{
    int test; scanf("%d", &test);
    while(test--)
    {
        int num; scanf("%d", &num); char line[100]; int a,b,s = 0,u = 0; char c;
        while(getchar() != '\n');
        for(int i = 0 ; i < num ; i++)
        {
            makeset(i);
        }
        while(gets(line) && sscanf(line, " %c %d %d", &c, &a, &b) == 3)
        {  
            if(c == 'c')
            {
                makeunion(a,b);
            }
            else
            {
                if(findset(a) == findset(b))
                s++;
                else
                u++;
            }
        }
        cout << s << "," << u << endl;
        if(test)
        cout << endl;
    }
}