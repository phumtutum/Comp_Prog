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
 
const int NMAX = 105;
 
int v[NMAX];
 
int main()
{
    int n,i,j;
 
    cin>>n;
    int impare = 0;
    for(i = 1 ; i <= n ; ++i)
    {
        cin>>v[i];
        impare += (v[i]&1);
    }
 
    cout<<min(impare , n-impare);
 
 
 
 
}
