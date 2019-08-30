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
 
typedef pair<int , int> ii;
 
const int NMAX = 2005;
 
char v[NMAX][NMAX];
 
int dp[2][NMAX][NMAX],sp[NMAX][NMAX],whitesl[NMAX],sp2[NMAX][NMAX],whitesc[NMAX];
 
//sp[i][j] = partial sums on the rows
//sp2[i][j] = partial sums on the columns
//dp[0][i][j] = the number of lines turnt to full white(which werent previously white) by choosing the square with bottom left corner on (i,j)
//dp[1][i][j] = the number of columns turn to full white(which werent previously white) by choosint the squeare with the UPPER RIGHT corner on (i,j)
 
deque<ii> rows,cols[NMAX];
 
int main()
{
    int N,K,i,j;
 
    cin>>N>>K;
    for(i = 1 ; i <= N ; ++i)
    {
        for(j = 1 ; j <= N ; ++j)
        {
            cin>>v[i][j];
            sp[i][j] = sp[i][j-1] + (v[i][j] == 'B');
            whitesl[i] += (v[i][j] == 'W');
            whitesc[j] += (v[i][j] == 'W');
        }
    }
    int maxim = 0,nrwhitel = 0,nrwhitec = 0;
 
    for(i = 1 ; i <= N ; ++i)
    {
        if(whitesl[i] == N)
            nrwhitel++;
        if(whitesc[i] == N)
            nrwhitec++;
    }
    for(j = 1 ; j <= N ; ++j)
    {
        for(i = 1 ; i <= K ; ++i)
            dp[0][i][j] = dp[0][i-1][j] + (whitesl[i] < N && sp[i][min(N , j+K-1)] - sp[i][j-1] + whitesl[i] == N);
 
 
        for(i ; i <= N ; ++i)
        {
            dp[0][i][j] = dp[0][i-1][j];
            dp[0][i][j] -= (whitesl[i-K] < N && whitesl[i-K] + sp[i-K][min(N , j+K-1)] - sp[i-K][j-1] == N);
            dp[0][i][j] += (whitesl[i] < N && whitesl[i] + sp[i][min(N , j+K-1)] - sp[i][j-1] == N);
 
        }
    }
 
    for(j = 1 ; j <= N ; ++j)
        for(i = 1 ; i <= N ; ++i)
            sp2[i][j] = sp2[i-1][j] + (v[i][j] == 'B');
 
    for(i = 1 ; i <= N ; ++i)
    {
        for(j = 1 ; j <= K ; ++j)
            dp[1][i][j] = dp[1][i][j-1] + (whitesc[j] < N && sp2[min(N , i+K-1)][j] - sp2[i-1][j] + whitesc[j] == N);
        j--;
        maxim = max(maxim , dp[0][max(i+K-1 , 1)][min(j-K+1 , N)] + dp[1][i][j]);
        for(j++ ; j <= N ; ++j)
        {
            dp[1][i][j] = dp[1][i][j-1];
            dp[1][i][j] -= (whitesc[j-K] < N && (sp2[min(N , i+K-1)][j-K] - sp2[i-1][j-K] + whitesc[j-K] == N));
            dp[1][i][j] += (whitesc[j] < N && sp2[min(N , i+K-1)][j] - sp2[i-1][j] + whitesc[j] == N);
            maxim = max(maxim , dp[0][max(i+K-1 , 1)][min(j-K+1 , N)] + dp[1][i][j]);
        }
    }
 
 
    cout<<nrwhitel + nrwhitec + maxim;
    return 0;
}
