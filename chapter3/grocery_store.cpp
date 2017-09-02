#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    for(a = 1 ; 4*a <= 2000 ; a += 1)
    {
        for(b = a ; a + 3*b <= 2000 ; b += 1)
        {
            for(c = b ; a + b + 2*c <= 2000 ; c += 1)
            {
                long long p = a*b*c; long long s = a + b + c;
                if(p <= 1000000)
                    continue;
                long long d = (1000000*s)/(p-1000000);
                if(d < c || s + d > 2000)
                    continue; 
                if(fabs((a + b + c + d)/100.0 - (a*b*c*d)/100000000.0) < 1e-9)
                    printf("%.2lf %.2lf %.2lf %.2lf\n", a/100.0,b/100.0,c/100.0,d/100.0);
            }
        }
    }
}