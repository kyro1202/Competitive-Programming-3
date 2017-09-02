#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test; cin >> test; int x,y,z; bool sol;
    while(test--)
    {
        sol = false;
        int a,b,c; cin >> a >> b >> c;
        for(x = -100 ; x <= 100 && !sol; x++)
        {
            if(x*x <= c)
            {
                for(y = -100 ; y <= 100 && !sol ; y++)
                {
                    if(x*x + y*y <= c && y != x)
                    {
                        for(z = -100 ; z <= 100 && !sol ; z++)
                        {   
                            if(z != y && z != x && (x + y + z) == a && x*y*z == b)
                            {
                                if(x*x + y*y + z*z == c)
                                {
                                    cout << x << " " << y << " " << z << endl;
                                    sol = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(!sol)
            cout << "No solution." << endl;
    }
}