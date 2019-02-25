#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "kbin.in" );
ofstream fout ( "kbin.out" );
const int MOD = 1234567;
unsigned long long n, k;
unsigned long long sum = 0;
void gen ( int n1, unsigned long long nr )
{
    if ( nr >= n )
        return;

    if ( n1 > k )
        return;

    if ( n1 == k )
    {
        sum += nr % MOD;
        sum = sum % MOD;
    }

    gen ( n1 + 1, 1ULL * nr * 2 + 1 );

    if ( nr != 0 )
        gen ( n1, 1ULL * nr * 2 );
}

int main()
{
    fin >> n >> k;
    gen ( 0, 0 );
    fout << sum  << endl;
    return 0;
}
