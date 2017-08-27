#include <bits/stdc++.h>
using namespace std;

int main()
{
        string s; getline(cin,s);
        while( s != "DONE")
        {
            int i = 0,j = s.length()-1;
            while(i < j)
            {
                while( !isalpha(s[i]) )
                i++;
                while( !isalpha(s[j]) )
                j--;
                if( tolower(s[i]) != tolower(s[j]) )
                break;
                i++; j--;
            }
            if(i>=j) cout << "You won't be eaten!" << endl;
		    else cout << "Uh oh.." << endl;
            getline(cin,s);
        }
}