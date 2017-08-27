#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector< stack <char> > ship;
    stack<char> temp;
    bool found = false;
    int count = 1; 
    while(true)
    {
        ship.clear();
        getline(cin,s);
        if(s == "end")
            break;
        temp.push(s[0]);
        ship.push_back(temp);
        temp.pop();
        int len = s.length();
        for(int i = 1 ; i < len ; i++)
        {
            found = false;
            for(int j = 0 ; j < ship.size() ; j++)
            {
                if(s[i] <= ship[j].top())
                {
                    ship[j].push(s[i]);
                    found = true;
                    break;
                }
            }
            if(!found)
            {
                temp.push(s[i]);
                ship.push_back(temp);
                temp.pop();
            }
        }

        printf("Case %d: %ld\n", count,ship.size());
        count++;
    }
}