#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test; int a[3];
    for(int i = 1 ; i <= test ; i++)
    {
        cin >> a[0] >> a[1] >> a[2];
        cout << "Case " << i << ": ";
        sort(a,a+3);
        cout << a[1] << endl;
    }
}