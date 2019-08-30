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
 
int h[NMAX];
 
int main()
{
    int T,N,i,j,M,K;
 
    cin>>T;
 
    while(T--)
    {
        cin>>N>>M>>K;
        for(i = 1 ; i <= N ; ++i)
            cin>>h[i];
        int sum = 0;
        bool ok = 1;
        for(i = 1 ; i < N ; ++i)
        {
            int pt = max(h[i+1] - K , 0);
            M += h[i] - pt;
            if(M < 0)
                ok = 0;
        }
 
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
 
}
