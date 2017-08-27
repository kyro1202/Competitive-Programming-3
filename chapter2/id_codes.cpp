#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(true)
    {
        s = "";
        cin >> s;

        if(s[0] == '#')
            break;
        bool check = next_permutation(s.begin(),s.end());
        if(check == true)
            cout << s << endl;
        else
            cout << "No Successor" << endl;
    }
}