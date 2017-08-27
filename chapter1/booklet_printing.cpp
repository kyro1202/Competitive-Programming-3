#include <bits/stdc++.h>
using namespace std;

int main()
{
    int pages;
    while(true)
    {
        cin >> pages;
        if(!pages)
        break;
        int sheets = 1;
        int maxpages = (pages%4) ? (pages/4 + 1)*4 : pages ;
        cout << "Printing order for " << pages << " pages:" << endl; string s = "Blank";
        int x = 1,y = maxpages;
        while(y > x)
        {
            cout << "Sheet " << sheets << ", front: ";
            if(y > pages)
            cout << s << ", " << x << endl;
            else cout << y << ", " << x << endl;
            x++; y--;
            if(pages==1) break;
            cout << "Sheet " << sheets << ", back : ";
            if(y > pages) cout << x << ", " << s << endl;
            else cout << x << ", " << y << endl;
            x++; y--;
            sheets++;
        }
                
    }
}