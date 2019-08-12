//check check
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<cstring>
 
#define ll long long
#define pb(x) push_back(x)
 
using namespace std;
 
const int NMAX = 105;
 
 
inline ll gcd(ll a , ll b)
{
    ll r;
    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
 
int main()
{
    ll N,M,Q;
 
    cin>>N>>M>>Q;
 
    ll k = gcd(N,M);
 
    while(Q--)
    {
        ll xa,ya,xb,yb;
        cin>>xa>>ya>>xb>>yb;
        ll v[5];
        v[1] = N/k , v[2] = M/k;
        ya--,yb--;
        if(ya/v[xa] == yb/v[xb])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
 
}
