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
const int INF = 1e6+5;
 
int v[NMAX];
 
int main()
{
    int Q,N,i,j;
 
 
    cin>>Q;
 
    while(Q--)
    {
        cin>>N;
 
        for(i = 1 ; i <= N ; ++i)
            cin>>v[i];
 
        int minim = INF;
        int cnt = 0;
        for(i = N ; i ; --i)
        {
            if(v[i] > minim)
            {
                cnt++;
            }
            else
                minim = v[i];
        }
 
        cout<<cnt<<"\n";
    }
 
 
 
 
 
}
