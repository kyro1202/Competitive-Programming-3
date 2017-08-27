#include <bits/stdc++.h>
using namespace std;

int main()
{
    float h,u,d,f,i,r; int count;
    while(1)
    {
        bool fail = false;
        count = 0;
        cin >> h >> u >> d >> f;
        if(h <= 0.0)
        {
            break;
        }
        i = 0.0; r = 0.0; f = u*f/100.0;
        do
        {   
            count++;
            r += u;
            if(r > h)
            {
                cout << "success on day ";
                break;
            }
            r -= d;
            if(r < 0)
            {
                cout << "failure on day ";
                break;
            }
            u -= f;
            if(u < 0)
            {
                u = 0;
            }
        }while(1);
        cout << count << endl;
    }
}