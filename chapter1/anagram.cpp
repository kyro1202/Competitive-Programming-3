#include <bits/stdc++.h>
using namespace std;

bool comp(char a,char b)
{
    char x = tolower(a); char y = tolower(b);
    if(x < y) return true;
    if(x == y) return a < b;
    return false;
}
int main()
{
    int test; cin >> test; string s;
    while(test--)
    {
        cin >> s;
        sort(s.begin(),s.end(),comp);
        do
        {
            cout << s << endl;
        }while(next_permutation(s.begin(),s.end(),comp));
    }
}