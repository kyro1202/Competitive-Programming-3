#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int test; cin >> test;
    for(int ti = 1 ; ti <= test ; ti++)
    {
        cout << "Case " << ti << ": ";
        int n; cin >> n; bool check[n],flag = false;
        string s; cin >> s;
        int counter = 0;
        for(int i = 1 ; i <= n ; )
        {
            if(s[i-1] == '.')
            {
                counter++;
                i += 3;
            }
            else
                i++;
        }
        cout << counter << endl;
    }
}