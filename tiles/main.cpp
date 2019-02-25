#include <bits/stdc++.h>
using namespace std;
int dhi[] = {1, 1, 0};
int dhj[] = {1, 3, 0};
int dvi[] = {3, 3, 3, 3, 0};
int dvj[] = {1, 2, 3, 4, 0};
string s;
int main()
{
    cin >> s;
    int nrv = 0, nrh = 0;

    for ( int i = 0; s[i]; i++ )
    {
        if ( s[i] == '0' )
        {
            cout << dvi[nrv % 4] << ' ' << dvj[nrv % 4] << '\n';
            nrv++;
        }
        else if ( s[i] == '1' )
        {
            cout << dhi[nrh % 2] << ' ' << dhj[nrh % 2] << '\n';
            nrh++;
        }
    }

    return 0;
}
