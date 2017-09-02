#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(true);
    long long int nn,ln,un;
    while(scanf("%lld %lld %lld", &nn,&ln,&un) == 3)
    {
        bitset<32> n(nn);
        bitset<32> l(ln);
        bitset<32> u(un);
        bitset<32> ans; ans.set();
        for(int i = 31 ; i >= 0 ; i--)
        {
            if(n.test(i))
            {
                if(ans.to_ulong() > u.to_ulong())
                    ans.flip(i);
            }
            else
            {
                if(u.test(i))
                    ans[i] = 1;
            }
        }
    }
}