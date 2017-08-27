#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,string> m; string ss,s; set<string> answer; char c;
    /*while(true)
    {
        s = ""; temp = "";
        while( c = getchar(), c != ' ' && c != '\n' )
        temp += c;
        if(temp[0] == '#')
        break;
        if(!temp.length())
        continue;
        int l = temp.length();
        for(int i = 0 ; i < l ; i++)
        {
            s += tolower(temp[i]);
        }
        sort(s.begin(),s.end());
        if(dic.count(temp))
        {
            dic[s] = "";
        }
        else
        {
            dic[s] = temp;
        }
    }*/
      while(true) {
            s = ""; ss = "";
            while(c=getchar(), c!=' ' && c!='\n') {
                s+=c;
            }
            if(s[0] == '#') break;
            if(!s.length()) continue;
            for(int i = 0 ; i < s.length() ; i++) {
                ss += tolower(s[i]);
            }
            sort(ss.begin(), ss.end());
            if(!m.count(ss)) {
                m[ss] = s;
            } else {
                m[ss]= "";
            }
        }
    for(map<string,string>::iterator i = m.begin() ; i != m.end() ; i++ )
    {
        if(i->second.length())
        {
            answer.insert(i->second);
        }
    }
    for(set<string>::iterator i = answer.begin() ; i != answer.end() ; i++)
    {
        cout << *i << endl;
    }
}