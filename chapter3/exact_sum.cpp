#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b,a1,b1;
    while(scanf("%d", &n) == 1)
    {
        int books[n];
        for(int i = 0 ; i < n ; i++)
            cin >> books[i];
        cin >> m;
        sort(books,books+n);
        int diff = 100000;
        a = 0,b = n-1;
        while(a < b)
        {
            if(books[a]+books[b] < m)
                a++;
            else if(books[a]+books[b] == m)
            {
                a1 = a;
                b1 = b;
                a++; b--;
            }
            else
                b--;
        }
        cout << "Peter should buy books whose prices are " << books[a1] << " and " << books[b1] << "." << endl << endl;
    }
}