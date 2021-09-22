#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int convertBase6ToBase10(string s, int n)
{
    char last_char;
    if (s.length()!=0) 
    {
        last_char = s.back();
	    s.pop_back();
        return (pow(6,n) * (last_char - '0') + convertBase6ToBase10(s,n+1));
    }
    return 0;
}
int main()
{
    string s;
    while(cin >> s)
    cout << convertBase6ToBase10(s,0) << endl;
    return 0;
}