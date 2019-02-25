#include <bits/stdc++.h>
using namespace std;
string s;
int nr = 0;
char q[100100];
int v;
int main()
{
    cin >> s;

    for ( int i = 0; i < s.size(); i++ )
    {
        v++;
        q[v] = s[i];

        while ( q[v] == q[v - 1] && v > 0 )
        {
            nr++;
            v = v - 2;

        }
    }

    if ( nr % 2 == 0 )
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
