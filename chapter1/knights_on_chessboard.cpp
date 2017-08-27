#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    while(1)
    {
        int res = 0;
        cin >> m >> n;
        if( m + n == 0 )
        break;
        int row = m,column = n;
        if(m > n) swap(m,n);
        if( m == 1 || n == 1 )
        {
            res = max(m,n);
        }
        else if( m == 2 || n == 2 )
        {
            if( m == n )
            {
                res = m*n;
            }
            else if( n%2 == 1 )
            {
                res = n + 1 ;
            }
            else if( n % 2 == 0)
            {
                if( (n/2)%2 == 0 )
                res = n;
                else
                {
                    res = 2 + n;
                }
            }
        }
        else
        {
            res = ((m*n) + 1) / 2;
        }
        cout << res << " knights may be placed on a " << row << " row " << column << " column board." << endl;
    }
}