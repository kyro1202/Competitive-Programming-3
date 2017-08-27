#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,started = 0; string x;
    do
    {
        cin >> n >> p;
        if( n == 0 && p == 0)
        return 0;
        cin.ignore();
        for(int i = 0 ; i < n ; i++ )
        {
            getline(cin,x);
        }
        string name,nametemp;
        double price = numeric_limits<double>::max(); double pricetemp; int r = 0,rtemp;
        
        for(int j = 0 ; j < p ; j++)
        {
            getline(cin,nametemp);
            cin >> pricetemp >> rtemp;
            if(rtemp > r)
            {
                r = rtemp;
                name = nametemp;
                price = pricetemp;
            }
            else if(rtemp == r)
            {
                if(pricetemp < price)
                {
                    price = pricetemp;
                    name = nametemp;
                    r = rtemp;
                }
            }
            cin.ignore();
            for(int k = 0 ; k < rtemp ; k++)
            {
                getline(cin,x);
            }
        }
        if(started)
        cout << endl;
        started++;
        cout << "RFP #" << started << endl << name << endl;

    }while(1);
}