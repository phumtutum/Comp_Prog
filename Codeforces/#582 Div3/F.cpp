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
 
ll p[NMAX],q[NMAX];
bool vizp[NMAX],vizq[NMAX];
ll top;
char s[NMAX];
 
int main()
{
    ll N,i,j,K;
 
    cin>>N>>K;
 
    for(i = 1 ; i <= N ; ++i)
        cin>>p[i];
 
    for(i = 1 ; i <= N ; ++i)
        cin>>q[i];
 
    int dif = 0;
    char ch = 'a';
    for(i = 1 ; i <= N ; ++i)
    {
        //daca p[i] a fost vazut anterior in q[1..i-1] reduce diferenta
        //daca nu, creste diferenta
        if(vizq[p[i]])
        {
            dif--;
        }
        else
            dif++;
        vizp[p[i]] = 1;
        //daca q[i] a fost vazut anterior in p[1..i] reduce diferenta
        //daca nu, creste diferenta
        if(vizp[q[i]])
        {
            dif--;
        }
        else
            dif++;
        vizq[q[i]] = 1;
 
        s[q[i]] = s[p[i]] = ch;
        if(dif == 0)
        {
            //pot creste valoarea
            if(ch < 'z')
                ch++;
        }
    }
    char maxim = 'a';
    for(i = 1 ; i <= N ; ++i)
    {
        maxim = max(s[i] , maxim);
    }
 
    if(maxim - 'a' + 1 >= K)
    {
        cout<<"YES\n";
        for(i =1  ; i <= N ; ++i)
            cout<<s[i];
    }
    else
        cout<<"NO\n";
    return 0;
}
