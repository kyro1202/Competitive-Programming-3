#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inp;
    while(cin >> inp)
    {
        
        int l = inp.length(); 
        bool pali = true,mirr = true;
        map<char,char> w;
        w['A'] = 'A';
	    w['E'] = '3';
	    w['H'] = 'H';
	    w['I'] = 'I';
	    w['J'] = 'L';
	    w['L'] = 'J';
	    w['M'] = 'M';
	    w['O'] = 'O';
	    w['S'] = '2';
	    w['T'] = 'T';
	    w['U'] = 'U';
	    w['V'] = 'V';
	    w['W'] = 'W';
	    w['X'] = 'X';
	    w['Y'] = 'Y';
	    w['Z'] = '5';
	    w['1'] = '1';
	    w['2'] = 'S';
	    w['3'] = 'E';
	    w['5'] = 'Z';
	    w['8'] = '8';
        if( l%2 == 1 && w[inp[l/2]] != inp[l/2])
        {
            mirr = false;
        }
        for(int i = 0 ; i < l/2 ; i++)
        {        
            if( inp[i] != inp[l-1-i] )
            {
                pali = false;
            }
            if( w[inp[i]] != inp[l-1-i] )
            {
                mirr = false;
            }
        }
        string res;
        if(pali && mirr)
        res = "is a mirrored palindrome.";
        else if(pali && !mirr)
        res = "is a regular palindrome.";
        else if(!pali && mirr)
        res = "is a mirrored string.";
        else
        res = "is not a palindrome.";
        cout << inp << " -- " << res << endl << endl;
    }
}