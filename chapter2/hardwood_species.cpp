#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    cin.ignore();
    string s;
    getline(cin,s);
    while(test--)
    {
        map<string,int> table;
        map<string,int>::iterator it;
        set<string> index;
        set<string>::iterator sit;
        string t;
        float count = 0;
        while(true)
        {
            getline(cin,t);
            if(!t.length())
                break;
            index.insert(t);
            it = table.find(t);
            if(it != table.end())
                table[t] += 1;
            else
                table[t] = 1;
            count++;
        }
        sit = index.begin();
        float temp;
        while(sit != index.end())
        {
            it = table.find(*sit);
            temp = (it->second*100) / count;
            cout << *sit << " ";
            printf("%.4f\n", temp);
            sit++;
        }
        if(test > 0)
            cout << endl;
    }
}