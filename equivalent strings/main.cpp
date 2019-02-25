#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
string eq ( string n )
{
    if ( n.size() % 2 == 1 )
        return n;

    string a = eq ( n.substr ( 0, n.size() / 2 ) );
    string b = eq ( n.substr ( n.size() / 2 ) );

    if ( a < b )
        return a + b;
    else
        return b + a;
}
int main()
{
    cin >> a >> b;
    string s1, s2;
    s1 = eq ( a );
    s2 = eq ( b );

    if ( s1 == s2 )
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
