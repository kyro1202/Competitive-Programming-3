#include <bits/stdc++.h>
using namespace std;
map<string,string> p;
map<string,int> r,size;
set<string> u;set<string>::iterator it;
void makeset(string s)
{
    p[s] = s;
    size[s] = 1;
    r[s] = 0;
}
string findset(string s)
{
    return p[s] == s ? s : (p[s] = findset(p[s]));
}
void makeunion(string a,string b)
{
    if(findset(a) != findset(b))
    {
        string x = findset(a),y = findset(b);
        if(r[x] > r[y])
        {
            p[y] = x;
            size[x] += size[y];
        }
        else
        {
            p[x] = y;
            size[y] += size[x];
            if(r[x] == r[y])
            r[y]++;
        }
    }
}
int main()
{
    int test,f; cin >> test;
    string s1,s2;
    while(test--)
    {
        cin >> f;
        p.clear(); size.clear(); r.clear(); u.clear();
        while(f--)
        {
            cin >> s1 >> s2;
            it = u.find(s1);
            if(it == u.end())
            {
                u.insert(s1); makeset(s1);
            }
            it = u.find(s2);
            if(it == u.end())
            {
                u.insert(s2); makeset(s2);
            }
            makeunion(s1,s2);
            cout << size[findset(s1)] << endl;
        }
    }
}