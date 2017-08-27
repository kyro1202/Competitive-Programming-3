#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test,len; cin >> test; string first,second,result;
    while(test--)
    {
        int up[12] = {},down[12] = {};
        for(int i = 0 ; i < 3 ; i++)
        {
            cin >> first >> second >> result;
            len = first.length();
            if(result == "even")
            {
               for(int j = 0 ; j < len ; j++)
               {
                    up[first[j] - 'A'] = -3;
                    down[first[j] - 'A'] = -3;
                    up[second[j] - 'A'] = -3;
                    down[second[j] - 'A'] = -3;
               }
            }
            else if(result == "down")
            {
                for(int j = 0 ; j < len ; j++)
                {
                    up[second[j] - 'A']++;
                    down[first[j] - 'A']++;
                }
            }
            else if(result == "up")
            {
                for(int j = 0 ; j < len ; j++)
                {
                    up[first[j] - 'A']++;
                    down[second[j] - 'A']++;
                }
            }
        }
        int max = -5,ans = 0; bool heavy;
        for(int i = 0 ; i < 12 ; i++)
        {
            if(max < up[i])
            {
                max = up[i];
                ans = i;
                heavy = true;
            }
            if(max < down[i])
            {
                max = down[i];
                ans = i;
                heavy = false;
            }
        }
        if(heavy)
        {
            cout << char('A' + ans) << " is the counterfeit coin and it is heavy." << endl;
        }
        else
        {
            cout << char('A' + ans) << " is the counterfeit coin and it is light." << endl;
        }
    }
}