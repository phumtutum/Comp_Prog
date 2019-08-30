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
 
const int NMAX = 1e6+5;
 
string s , s1;
int kmp[NMAX];
 
 
inline void build_kmp(string v)
{
    //building the prefix function
    int i,j,N = v.size();
 
    for(i = 1 , j = 0 ; i < N ; ++i)
    {
        while(j != 0 && v[i] != v[j])
        {
            j = kmp[j-1];
        }
 
        if(v[i] == v[j])
            kmp[i] = ++j;
        else
            kmp[i] = 0;
    }
}
 
int main()
{
    int N,i,j;
 
    cin>>N;
 
    cin>>s;
    for(i = 2 ; i <= N ; ++i)
    {
        cin>>s1;
        string tmp = s1 + "$" + s.substr(max(0 , ((int) s.size()) - ((int) s1.size())));
        build_kmp(tmp);
        if(kmp[tmp.size()-1] < s1.size())
            s += s1.substr(kmp[tmp.size()-1]);
    }
    cout<<s;
 
}
