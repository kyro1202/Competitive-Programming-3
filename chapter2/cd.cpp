#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,m;
    set<long long int> unique;
    while(true)
    {
        cin >> n >> m;
        if(!(m+n))
            break;
        unique.clear();
        long long int temp;
        for(int i = 0 ; i < m + n ; i++)
        {
            cin >> temp;
            unique.insert(temp);
        }
        cout << m + n - unique.size() << endl;
    }
}