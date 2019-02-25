#include <bits/stdc++.h>
using namespace std;
int n;
long long a[10009], v;
void generare(long long k)
{
    if(k<=1e9)
    {
        a[++v]=k*10+4;
        generare(k*10+4);
        a[++v]=k*10+7;
        generare(k*10+7);
        k=k/10;
    }
}
int main()
{
    generare(0);
    sort(a+1,a+v+1);
    int x;
    cin>>x;
    cout<<v<<' ';
    for(int i=1; i<=v; i++)
        if(a[i]==x)
        {
            cout<<i;

        }
    return 0;
}
