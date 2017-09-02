#include <bits/stdc++.h>
using namespace std;
string led[10] = {
"YYYYYYN", 
"NYYNNNN", 
"YYNYYNY", 
"YYYYNNY", 
"NYYNNYY", 
"YNYYNYY", 
"YNYYYYY", 
"YYYNNNN",
"YYYYYYY",
"YYYYNYY",
};
int main()
{
    int n; vector<string> inp; string s;
    while(true)
    {
        cin >> n; inp.clear();
        if(!n)
            break;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> s;
            inp.push_back(s);
        }
        bool flag = false;
        for(int i = 9 ; i >= n - 1 ; i--)
        {
            int broken[8] = {0};
            int j;
            for( j = 0 ; j < n ; j++)
            {
                int k;
                for( k = 0 ; k < 7 ; k++)
                {
                    if(broken[k] && inp[j][k] == 'Y')
                        break;
                    if(inp[j][k] == 'N' && led[i-j][k] == 'Y')
                        broken[k] = 1;
                    else if(inp[j][k] == 'Y' && led[i-j][k] == 'N')
                        break;
                }
                if(k != 7)
                    break;
            }
            if( j == n)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "MIS";
        cout << "MATCH" << endl;
    }
}