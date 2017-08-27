#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    while(test--)
    {
        int tot; cin >> tot;
        int ascii[130] = {0};
        int score = 0;char temp1; int temp2;
        for(int i = 0 ; i < tot ; i++)
        {
            cin >> temp1 >> temp2;
            ascii[temp1] = temp2;
        }
        int lines; cin >> lines; string s;
        cin.ignore();
        for(int i = 0 ; i < lines ; i++)
        {
            s = "";
            getline(cin,s);
            int len = s.size();
            for(int j = 0 ; j < len ; j++)
                score += ascii[s[j]];
        }
        float ans = score / 100.0;
        printf("%.2f$\n", ans);
    }
    cout << endl;
}