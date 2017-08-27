#include <bits/stdc++.h>

using namespace std;

#define FOR(i,test) for(int i = 0 ; i < test ; i++ ) 

int main()
{
    int test; cin >> test;
    FOR(i,test)
    {
        long long int a,b; cin >> a >> b;
        if(a > b)
        cout << ">";
        else if(a < b)
        cout << "<";
        else
        cout << "=";
        cout << endl;
    }
}