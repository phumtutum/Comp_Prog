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
 
const int NMAX = 150005;
 
 
ll v[NMAX];
bool viz[104];
 
int main()
{
    ll Q, N ,i,j,M,k,K;
 
    cin>>Q;
 
    while(Q--)
    {
        cin>>N>>M;
 
        for(i = 0 ; i < 10 ; ++i)
            viz[i] = 0;
 
        //i e lungimea perioadei
        for(i = 1 , k = M % 10 ; !viz[k] ; ++i , k = (k+M)%10)
            viz[k] = 1;
 
        i--;
        ll sum = 0;
        for(j = 0 ; j < 10 ; ++j)
            sum += viz[j]*j;
        ll K = N/M;
        ll fact = K/i;
        ll rez = fact*sum;
 
        for(j = 1 , k = M%10 ; j <= K%i ; ++j , k = (k+M)%10)
            rez += k;
 
        cout<<rez<<"\n";
    }
 
 
 
}
