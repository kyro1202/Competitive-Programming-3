#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[100001];
    while(scanf("%s", s) != EOF )
    {
        list<char> line;
        list<char>::iterator it;
        it = line.begin();
        int len = strlen(s);
        for(int i = 0 ; i < len ; i++)
        {
            if(s[i] == '[')
                it = line.begin();
            else if(s[i] == ']')
                it = line.end();
            else
                line.insert(it,s[i]);
        }
        it = line.begin();
        while(it != line.end())
        {
            cout << *it;
            it++;
        }
        cout << endl;
    }
}