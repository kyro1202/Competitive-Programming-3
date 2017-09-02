#include <bits/stdc++.h>
using namespace std;

int d(int a,int b)
{
    return abs(a/5 - b/5)+abs(a%5-b%5);
}
int main()
{
    int test,a,b,p; cin >> test;
    while(test--)
    {
        int city[25];
        int min_d = 0;
        int sol[5];
        for(int i = 0 ; i < 25 ; i++)
        {
            city[i] = 0;
            min_d += 2*5*10000;
        }
        int n; cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a >> b >> p;
            city[a*5+b] = p;
        }
        for(int i = 0 ; i < 21 ; i++)
        {
            for(int j = i+1 ; j < 22 ; j++)
            {
                for(int k = j+1 ; k < 23 ; k++)
                {
                    for(int l = k+1 ; l < 24 ; l++)
                    {
                        for(int m = l+1 ; m < 25 ; m++)
                        {
                            int office[5] = { i , j , k , l , m }; int sum = 0;
                            for(int n = 0 ; n < 25 ; n++)
                            {
                                int temp;
                                if(city[n] > 0)
                                {
                                    temp = d(office[0],n); 
                                    for(int o = 1 ; o < 5 ; o++)
                                    {
                                        temp = min(temp,d(office[o],n));
                                    }
                                    temp*=city[n];
                                    sum += temp;
                                }    
                            }
                            if(sum < min_d)
                            {
                                min_d = sum;
                                memcpy(sol,office,sizeof(int)*5);
                            }
                        }
                    }
                }
            }
        }
        cout << sol[0];
        for(int i = 1 ; i < 5 ; i++)
            cout << " " << sol[i];
        cout << endl;
    }
}