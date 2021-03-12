#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define rsz resize
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pi  pair<int,int>
#define f first
#define s second
#define pll pair<ll, ll>
#define vpl vector<pll>
#define v(x) vector<x>
#define s(x) set<x>
#define mp make_pair
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 1005;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))

ll ans =0;

bool check(ll idx,ll n,string s,unordered_map<string,ll> &mp,vector<ll> &dp){
        if(idx == n){
            ans++;
            return true;
        } 
        
        if(dp[idx] == 0) return 0;
        else if(dp[idx] == 1){
            return check(n,n,s,mp,dp);
        }
        
        string temp;
        dp[idx] = 0;
        
        for(ll j= idx;j<n;j++){
            temp += s[j];
            if(mp[temp] && check(j+1,n,s,mp,dp))
                dp[idx] = 1;
        }
        
        return dp[idx];
    }
    
void wordBreak(string s, v(string)& wordDict) {

        ll n = s.size();

        v(ll) dp(n+1,-1);
        unordered_map<string,ll> mp;
        for(auto x:wordDict) mp[x]++;

        bool a =  check(0,n,s,mp,dp);
        
        cout <<  ans;
}

int main(){
    string str;
    cin >> str;

    ll n;
    cin >> n;

    v(string) dict(n);
    rep(i,0,n) cin >> dict[i];

    wordBreak(str,dict);
}