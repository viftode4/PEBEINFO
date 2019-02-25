#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "interesant.in" );
ofstream fout ( "interesant.out" );
int n, cer, nr;
string a[210];
vector <string> sol;
int verif ( string a, string b )
{
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    while ( i < n && j < m )
    {
        if ( a[i] == b[j] )
        {
            i++;
            j++;
        }
        else
            j++;
    }

    if ( i == n )
        return 1;

    return 0;
}
int main()
{
    fin >> cer;
    fin >> n;

    for ( int i = 1; i <= n; i++ )
        fin >> a[i];

    if ( cer == 1 )
    {
        sort ( a + 1, a + n + 1 );
        int imax = 1, m = a[1].size();

        for ( int i = 2; i <= n; i++ )
            if ( a[i].size() > m )
            {
                m = a[i].size();
                imax = i;
            }

        fout << a[imax];
        return 0;
    }

    for ( int i = 1; i <= n; i++ )
    {
        int ok = 0;

        for ( int j = 1; j <= n; j++ )
            if ( verif ( a[i], a[j] ) && i != j )
            {
                ok = 1;
                break;
            }

        if ( ok == 0 )
        {
            nr++;
            sol.push_back ( a[i] );
        }
    }

    fout << nr << '\n';

    for ( auto it : sol )
        fout << it << '\n';
}
