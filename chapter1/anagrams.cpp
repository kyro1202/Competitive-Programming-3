#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test; cin.ignore(); cin.ignore();
    while(test--)
    {
        map<string,string> dic; string s,ss; int count = 0;
        while(true)
        {
            s = ""; ss = "";
            getline(cin,s);
            if(!s.length())
            break;
            count++;
            for(int i = 0 ; i < s.length() ; i++)
            {
                if( s[i] != ' ')
                ss+=s[i];
            }
            sort(ss.begin(),ss.end());
            dic[s] = ss;
        }
        map<string,string>::iterator i = dic.begin();
        while(count > 1)
        {
            s = i->first; ss = i->second;
            map<string,string>::iterator j = i; j++;
            while( j != dic.end() )
            {
                if(j->second == ss)
                cout << s << " = " << j->first << endl;
                j++;
            }    
            i++; count--;
        }
        if(test) cout << endl;
    }
}