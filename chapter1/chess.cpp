#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    for(int ti = 0 ; ti < test ; ti++ )
    {
        char piece; int m,n,res,temp; cin >> piece >> m >> n;
        switch (piece)
        {
        case 'r':
            res = min(m,n);
            break;
        case 'k':
            res = ( (m*n) % 2 == 0 ) ? (m*n) / 2 : (m*n) / 2 + 1 ;
            break;
        case 'Q':
            res = min(m,n);
            break;
        default:
            res = ((m + 1)/2) * ((n + 1)/2) ; 
            break;
        }
        cout << res << endl;       
    }
}