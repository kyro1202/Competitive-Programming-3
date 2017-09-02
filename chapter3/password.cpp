#include <bits/stdc++.h>
using namespace std;
string screen1[6],screen2[6];
set<string> solutions;
vector<string> haystack;
void find(char* s,int size,int layer)
{
    if(size == 5)
    {
        haystack.push_back(s);
        return;
    }
    for(int i = 0 ; i < 6 ; i++)
    {
        s[size] = screen1[i][layer]; find(s,size+1,layer+1);
    }
}
int main()
{
    int n,test; cin >> test;
    while(test--)
    {
        cin >> n;
        for(int i = 0 ; i < 12 ; i++)
        {
            if(i / 6 < 1)
                cin >> screen1[i%6];
            else
                cin >> screen2[i%6];
        }
        solutions.clear();
        haystack.clear();
        char comb[5];
        find(comb,0,0);
        for(int k = 0 ; k < haystack.size() ; k++)
        {
            string s = haystack[k]; int i;
            for(i = 0 ; i < 5 ; i++)
            {
                char c = s[i]; bool found = false;
                for(int j = 0 ; j < 6 ; j++)
                {
                    if(screen2[j][i] == c)
                        found = true;
                }
                if(!found)
                    break;
            }
            if(i == 5)
                solutions.insert(s);
        }
        if(n > solutions.size())
            cout << "NO" << endl;
        else
        {
            int count = 0;
            set<string>::iterator it = solutions.begin();
            while(it != solutions.end())
            {
                count++;
                if(count == n)
                {
                    cout << (*it) << endl;
                    break;
                }
                it++;
            }
        }
    }
}