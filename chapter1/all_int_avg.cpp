#include <bits/stdc++.h>
using namespace std;

int c;

int num(float f)
{
    int mult = 1;
    while(f != (int)f)
    {
        f *= 10;
        mult *= 10;
    }
    c = mult;
    return f;
}
int digits(int i)
{
    if(i == 0)
    return 0;
    int mult = 10,count = 1;
    while(i / mult != 0)
    {
        mult *= 10;
        count++;
    }
    return count;
}
int main()
{
    int tot; int cas = 1;
    while(true)
    {
        cin >> tot; float sum = 0; int temp;
        if(!tot)
        {  /*cout << endl;*/  break; }
        printf("Case %d:\n", cas); cas++;    
        for(int i = 0 ; i < tot ; i++)
        {
            cin >> temp;
            sum += temp;
        }
        float avg = sum/tot;
        bool minus = ( avg < 0 ) ? 1 : 0;
        if(minus)
        { avg *= -1; sum *= -1; }
        int a = floor(avg);
        if(a == avg)
        {
            if(minus)
            { cout << "- " << a << endl;
            continue; }
            else
            {
                cout << a << endl; continue;
            }
        }
        int b = sum - a*tot; c = tot;
        for(int i = c - 1 ; i >= 2 ; i--)
        {
            if(b % i == 0 && c % i == 0)
            {
                b /= i; c /= i;
            }
        }
        int digitsb = digits(b);
        int digitsc = digits(c);
        int digitsa = digits(a);
        if(minus)
        {
            if(a)
            {
                for(int i = 0 ; i < digitsc - digitsb + 2 + digitsa ; i++)
                cout << " ";
                cout << b << endl;
                cout << "- " << a;
                for(int i = 0 ; i < digitsc ; i++)
                cout << "-";
                cout << endl;
                for(int i = 0 ; i < digitsa + 2 ; i++)
                cout << " ";
                cout << c << endl;
            }
            else
            {
                for(int i = 0 ; i < digitsc - digitsb + 2 ; i++)
                cout << " ";
                cout << b << endl;
                cout << "- ";
                for(int i = 0 ; i < digitsc ; i++)
                cout << "-";
                cout << endl;
                cout << "  " << c << endl;
            }
        }
        else
        {
            if(a)
            {
                for(int i = 0 ; i < digitsc - digitsb + digitsa ; i++)
                cout << " ";
                cout << b << endl;
                cout << a;
                for(int i = 0 ; i < digitsc ; i++)
                cout << "-";
                cout << endl;
                for(int i = 0 ; i < digitsa ; i++)
                cout << " ";
                cout << c << endl;
            }
            else
            {
                for(int i = 0 ; i < digitsc - digitsb ; i++)
                cout << " ";
                cout << b << endl;
                for(int i = 0 ; i < digitsc ; i++)
                cout << "-";
                cout << endl;
                cout << c << endl;
            }
        }    
    }
}