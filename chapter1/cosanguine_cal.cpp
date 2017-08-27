#include <bits/stdc++.h>
using namespace std;

int main()
{
    int CASE = 0; string s;
    while(getline(cin,s))
    {
        string family[3] = {}; int mark = 0; bool misspar = false;
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] == ' ' )
            { mark++; continue; }
            family[mark] += s[i];
            if(s[i] == '?')
            {
                if(mark == 0 || mark == 1)
                misspar = true;
            }
        }
        int test = 3;
        while(test--)
        cout << family[test] << endl;
    }
}