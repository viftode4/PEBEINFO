#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "cumpanit.in" );
ofstream fout ( "cumpanit.out" );
int prim[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
const int N = 12;
unsigned long long a, b;
vector <unsigned long long>sol;
void generare ( int x, int se, int sb, unsigned long long nr )
{
    if ( nr > b )
        return;

    if ( se == sb  && nr <= b && nr >= a )
        sol.push_back ( nr );

    for ( int i = x; i <= N; i++ )
        if ( nr % prim[i] == 0 )
            generare ( i, se + 1, sb, 1ULL * nr * prim[i] );
        else
            generare ( i, se + 1, sb + prim[i], 1ULL * nr * prim[i] );
}
int main()
{
    fin >> a >> b;
    generare ( 1, 0, 0, 1 );
    sort ( sol.begin(), sol.end() );

    for ( auto it : sol )
        fout << it << '\n';

    return 0;
}
