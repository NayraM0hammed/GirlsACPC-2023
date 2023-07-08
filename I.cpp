#include <bits/stdc++.h>

using namespace std;

#define zrebeooo           ios_base::sync_with_stdio(false);cin.tie(NULL);
#define zrebeooo2          cin.tie(0); cin.sync_with_stdio(0);
#define ll                 long long
#define el                 '\n'
#define S                  second
#define F                  first
#define clr(x , v)         memset(x , v , sizeof(x))
#define l(i,k,n)           for (ll i=k ; i<n ; i++)
#define test               int t; cin>>t; while(t--)

ll n , a[2][(int)2e5] , inf = 9e18;
pair<ll,ll> dp[4][2][(int)2e5];

pair<ll,ll> ans(int p , int i , int j){
    if(j == n - 1) return {a[i][j],0};

    pair<ll,ll>& ret = dp[p][i][j];
    if(~ret.F) return ret;

    ret = {inf,inf};

    if(i > 0 && p != 1){
        pair<ll,ll> d = ans(0 , i-1 , j);
        d.F += a[i][j];
        d.S++;
        if(d.F <= ret.F){
            if(d.F < ret.F) ret = d;
            else ret.S = min(d.S,ret.S);
        }
    }

    if(i < 1 && p != 0){
        pair<ll,ll> d = ans(1 , i+1 , j);
        d.F += a[i][j];
        d.S++;
        if(d.F <= ret.F){
            if(d.F < ret.F) ret = d;
            else ret.S = min(d.S,ret.S);
        }
    }

    if(j < n - 1){
        pair<ll,ll> d = ans(2 , i , j+1);
        d.F += a[i][j];
        d.S++;
        if(d.F <= ret.F){
            if(d.F < ret.F) ret = d;
            else ret.S = min(d.S,ret.S);
        }
    }

    return ret;
}

int main ()
{
    zrebeooo  zrebeooo2

         test{
            cin >>  n;
            l(i , 0 , 2) l(j , 0 , n) cin >> a[i][j];
            clr(dp , -1);

            pair<ll,ll> m1 = ans(3,0,0) , m2 = ans(3,1,0);
            if(m2.F < m1.F) swap(m1,m2);
            if(m1.F == m2.F) m1.S = min(m1.S , m2.S);

            cout << m1.F << " " << m1.S << el;
         }
return 0;
}
