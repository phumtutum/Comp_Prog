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
 
const int NMAX = 1e5+5;
 
char s[NMAX];
 
bool istaken[105];
 
int main()
{
    int N,i,j;
    cin>>N;
    cin>>(s+1);
 
    N = strlen(s+1);
 
    for(i = 1 ; i <= N ; ++i)
    {
        if('0' <= s[i] && s[i] <= '9')
            istaken[s[i]-'0'] = 0;
        else if(s[i] == 'L')
        {
            for(j = 0 ; j < 10 ; ++j)
            {
                if(!istaken[j])
                {
                    istaken[j] = 1;
                    break;
                }
            }
        }
        else
        {
            for(j = 9 ; j >= 0 ; --j)
            {
                if(!istaken[j])
                {
                    istaken[j] = 1;
                    break;
                }
            }
        }
    }
 
    for(i = 0 ; i < 10 ; ++i)
    {
        if(istaken[i])
            cout<<"1";
        else
            cout<<"0";
    }
 
}
