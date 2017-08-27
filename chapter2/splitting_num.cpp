#include <bits/stdc++.h>
using namespace std;

int main()
{
    bitset<31> a,b;
    int count; long int n;
    while(true)
    {
        count = 0;
        cin >> n;
        if(!n)
        break;
        bitset<31> inp(n);
        a.reset(); b.reset();
        for(int i = 0 ; i < inp.size() ; i++)
        {
            if(inp.test(i))
            {
                count++;
                if(count%2)
                    a[i] = 1;
                else
                    b[i] = 1;
            }
        }
        cout << a.to_ulong() << " " << b.to_ulong() << endl;
    }
}