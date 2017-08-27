/*#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    map<long long int> flakes;
    while(test--)
    {
        flakes.clear();
        long long int n,temp; cin >> n;
        while(n--)
        {
            cin >> temp;
            flakes.insert(temp);
        }
        cout << flakes.size();
        if(test)
            cout << endl;
    }
}*/
#include <iostream>
#include <map>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    int cases, n;
    int snowflake;
    int *snowflakes = new int[1000001];
    int first, current, result, counter;

    cin >> cases;

    while (cases--) {
        first = current = result = counter = 0;
        map<int,bool> taken;
        map<int,bool>::iterator it;

        cin >> n;

        while (n--) {
            
            cin >> snowflake;
            snowflakes[current++] = snowflake;

            if (taken.find(snowflake) != taken.end()) {
                if (counter > result) result = counter;

                while (true) {
                    if (snowflakes[first] == snowflake) break;
                    taken.erase(snowflakes[first]);
                    counter--;
                    first++;
                }
                
                first++;
            } else {
                counter++;
                taken[snowflake] = true;
            }
        }

        if (counter > result) result = counter;
        
        cout << result << endl;
    }

    delete snowflakes;

    return 0;
}