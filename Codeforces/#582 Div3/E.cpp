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
 
const int NMAX = 1e5+5;
const ll INF = 1e18;
 
string s1,s2;
char mp[105];
 
int main()
{
    ll N,i,j;
 
    cin>>N;
    cin>>s1>>s2;
 
    cout<<"YES\n";
 
    mp[0] = 'a';
    mp[1] = 'b';
    mp[2] = 'c';
    char ch1,ch2,ch3,ch4;
    if(s1[0] == s1[1] && s2[0] == s2[1])
    {
        //2 caractere egale
        for(i = 1 ; i <= N ; ++i)
            cout<<"abc";
    }
    else if(s1[0] == s1[1])
    {
        ch1 = s1[0];
        ch2 = s2[0];
        ch3 = s2[1];
        if(ch2 == ch1)
        {
            for(ch2 = 'a' ; ch2 == ch1 || ch2 == ch3 ; ++ch2);
 
            for(i = 1 ; i <= N ; ++i)
                cout<<ch3;
            for(i = 1 ; i <= N ; ++i)
                cout<<ch1<<ch2;
        }
        else if(ch3 == ch1)
        {
            for(ch3 = 'a' ; ch3 == ch1 || ch3 == ch2 ; ++ch3);
 
            for(i = 1 ; i <= N ; ++i)
                cout<<ch2;
 
            for(i = 1 ; i <= N ; ++i)
                cout<<ch3<<ch1;
        }
        else
        {
            for(i = 1 ; i <= N ; ++i)
                cout<<ch2<<ch1;
            for(i = 1 ; i <= N ; ++i)
                cout<<ch3;
        }
    }
    else if(s2[0] == s2[1])
    {
        ch1 = s2[0];
        ch2 = s1[0];
        ch3 = s1[1];
        if(ch2 == ch1)
        {
            for(ch2 = 'a' ; ch2 == ch1 || ch2 == ch3 ; ++ch2);
 
            for(i = 1 ; i <= N ; ++i)
                cout<<ch3;
            for(i = 1 ; i <= N ; ++i)
                cout<<ch1<<ch2;
        }
        else if(ch3 == ch1)
        {
            for(ch3 = 'a' ; ch3 == ch1 || ch3 == ch2 ; ++ch3);
 
            for(i = 1 ; i <= N ; ++i)
                cout<<ch2;
 
            for(i = 1 ; i <= N ; ++i)
                cout<<ch3<<ch1;
        }
        else
        {
            for(i = 1 ; i <= N ; ++i)
                cout<<ch2<<ch1;
            for(i = 1 ; i <= N ; ++i)
                cout<<ch3;
        }
    }
    else
    {
        ch1 = s1[0];
        ch2 = s1[1];
        ch3 = s2[0];
        ch4 = s2[1];
 
        if(ch1 == ch3)
        {
            if(ch2 == ch4)
            {
                for(ch3 = 'a' ; ch3 == ch1 || ch3 == ch2 ; ++ch3);
 
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch1<<ch3<<ch2;
            }
            else
            {
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch2<<ch4;
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch1;
            }
        }
        else if(ch1 == ch4)
        {
            if(ch2 == ch3)
            {
                for(ch3 = 'a' ; ch3 == ch1 || ch3 == ch2 ; ++ch3);
 
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch1<<ch3;
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch2;
            }
            else
            {
                for(i = 1 ; i <= N ; ++i)
                {
                    cout<<ch2;
                }
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch1;
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch3;
            }
        }
        else
        {
            if(ch2 == ch3)
            {
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch4;
                for(i =1  ; i<= N ; ++i)
                    cout<<ch2;
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch1;
            }
            else
            {
                //ch2 == ch4
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch2;
                for(i = 1 ; i <= N ; ++i)
                    cout<<ch1<<ch3;
            }
        }
    }
 
    return 0;
}
