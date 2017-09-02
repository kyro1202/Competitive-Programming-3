#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > line;
int main()
{
    string s; cin >> s;
    int len = s.length();
    line.resize(257);
    for(int i = 0 ; i < len ; i++)
    {
        line[s[i]].push_back(i);
    }
    int q; cin >> q;
    while(q--)
    {
        int flag = 1,min,max;
        cin >> s;
        len = s.length(); int ind = -1;
        for(int i = 0 ; i < len ; i++)
        {
            vector<int>::iterator high = upper_bound(line[s[i]].begin(),line[s[i]].end(),ind);
            ind = high - line[s[i]].begin();
            if(high == line[s[i]].end())
                flag = -1;
            ind = line[s[i]][ind];
            if(i == 0) min = ind;
            max = ind;
        }
        if(flag == -1)
        cout << "Not matched" << endl;
        else
        {
            cout << "Matched ";
            cout << min << " " << max << endl;
        }
    }
}