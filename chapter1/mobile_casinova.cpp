#include <bits/stdc++.h>
using namespace std;

/*int process(int a,int d)
{
    int temp = 1;
    for(int i = 0 ; i < d ; i++)
    {
        temp = temp*10;
    }
    return a - (a / temp)*temp;
}*/

/*void print(int a,int b)
{
    int diff = a - b;
    int digits = (int)log10(diff) + 1;
    printf("0%d-", b);
    a = process(a,digits);
    printf("%d\n", a);
}*/

void print(int a,int b)
{
    int aux = a - b;
    string small = to_string(b);
    string big = to_string(a);
    for(int i=big.length()-1,e=small.length()-1,count=1;i>=-1&&e>=-1;i--,e--,count*=10)
    {
        if( (small[i]==big[e] &&aux<count)||i==-1 )
            {
                printf("0%d-",b);
                cout<<big.substr(e+1);
                printf("\n");
                return;
            }
    }
}

int main()
{
    int test,temp; int count = 1;
    while(true)
    {
        cin >> test;
        if(!test)
            break;
        printf("Case %d:\n", count); count++;
        int prev,toprint; bool printed = true;
        for(int i = 0 ; i < test ; i++)
        {
            cin >> temp;
            if( i == 0)
                prev = temp;
            if(test == 1)
            {
                printf("0%d", temp);
                break;
            }
            if(printed)
            {
                toprint = prev;
                printed = false;
            }
            else
            {
                if(temp != ( prev + 1) )
                {
                    printed = true;
                    int diff = prev-toprint;
                    if(!diff)
                    {
                        printf("0%d", prev);
                        prev = temp;
                        continue;
                    }
                    print(prev,toprint);
                }
            }
            if( i == test - 1 && printed )
            {
                printf("0%d\n", temp);
                break;
            }
            if( i == test - 1 && !printed )
            {
                print(temp,toprint);
            }
            prev = temp;
        }
        cout << endl;
    }
}