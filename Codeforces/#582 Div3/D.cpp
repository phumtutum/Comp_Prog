//check check check
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<cstring>
#include<map>
#include<iomanip>
 
#define ll long long
#define pb(x) push_back(x)
 
using namespace std;
 
typedef pair<int,int> ii;
 
const int NMAX = 2e5+5;
const ll INF = 1e18;
 
 
ll v[NMAX],freq[NMAX],price[NMAX];
 
int main()
{
    ll N,i,j,K;
 
    cin>>N>>K;
    ll maxim = -1;
    for(i = 1 ; i <= N ; ++i)
        cin>>v[i],maxim = max(v[i] , maxim);
 
    ll step,it;
    for(it = 1 , step = 1 ; step <= maxim ; (step<<=1) , it++);
 
    ll rez = INF;
    for(i = 1 ;  i <= N ; ++i)
    {
        freq[v[i]]++;
        if(freq[v[i]] >= K)
            rez = min(price[v[i]] , rez);
    }
 
    for(i = 1 ;  i <= it ; ++i)
    {
        for(j = 1 ;  j <= N ; ++j)
        {
            if(v[j] != v[j]/2)
            {
                v[j] /=2;
                freq[v[j]]++;
                price[v[j]]+=i;
                if(freq[v[j]] >= K)
                    rez = min(price[v[j]] , rez);
            }
        }
    }
 
    cout<<rez;
    return 0;
}
