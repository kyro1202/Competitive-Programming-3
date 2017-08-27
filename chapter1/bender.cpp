#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        long int l; cin >> l; string inp; string otp = "+x";
        if(l <= 0)
            break;   
        for(int i = 0 ; i < l - 1 ; i++ )
        {
            cin >> inp;
            if(inp[0] == 'N')
                continue;
            if(inp[1] != otp[1] && otp[1] != 'x')
                continue;
            if(inp[1] == otp[1] && otp[1] != 'x')
            {
                if(inp[0] == otp[0])
                    otp = "-x";
                else
                    otp = "+x";
                continue;     
            }
            if(otp[1] == 'x' && otp[0] == '-')
            {
                if(inp[0] == '+')
                    otp[1] = inp[1];
                else
                {
                    otp[0] = '+'; otp[1] = inp[1];
                }    
            }
            else
                otp = inp;  
        }
        cout << otp << endl;    
    }
}