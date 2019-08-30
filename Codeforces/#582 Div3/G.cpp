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
 
struct al
{
    ll id,val;
}q[NMAX];
 
struct edge
{
    ll from,to,cost;
}edges[NMAX];
 
ll tata[NMAX],h[NMAX],rez[NMAX];
ll cnt;
 
ll findSet(ll node)
{
    if(node != tata[node])
        tata[node] = findSet(tata[node]);
    return tata[node];
}
 
void unionSet(ll p1 , ll p2)
{
    ll t1 = findSet(p1) , t2 = findSet(p2);
    if(t1 == t2)
        return;
    cnt += h[t1]*h[t2];
    if(h[t1] > h[t2])
    {
        h[t1] += h[t2];
        tata[t2] = t1;
    }
    else
    {
        h[t2] += h[t1];
        tata[t1] = t2;
    }
 
}
 
void addtotree(edge p1)
{
    unionSet(p1.to, p1.from);
}
 
bool cmp(const al &p1 , const al &p2)
{
    return p1.val < p2.val;
}
 
bool cmp2(const edge &p1 , const edge &p2)
{
    return p1.cost < p2.cost;
}
 
 
int main()
{
    ll N,Q,i,j;
    cin>>N>>Q;
 
    for(i = 1 ; i < N ; ++i)
    {
        ll x,y,c;
        cin>>x>>y>>c;
        edges[i].from = x;
        edges[i].to = y;
        edges[i].cost = c;
    }
 
    for(i = 1 ; i <= Q ; ++i)
    {
        cin>>q[i].val , q[i].id = i;
    }
 
    for(i = 1 ; i <= N ; ++i)
        tata[i] = i , h[i] = 1;
 
    sort(q+1 , q+Q+1,cmp);
    sort(edges+1 , edges+N , cmp2);
    //todo cmpurile
 
    for(i = 1,j = 0 ; i <= Q ; ++i)
    {
        while(j < N && edges[j+1].cost <= q[i].val)
        {
            addtotree(edges[j+1]);
            j++;
        }
        rez[q[i].id] = cnt;
    }
 
    for(i = 1 ; i <= Q ; ++i)
        cout<<rez[i]<<" ";
 
    return 0;
}
