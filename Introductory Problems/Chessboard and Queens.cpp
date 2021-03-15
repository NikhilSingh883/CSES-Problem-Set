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
#define vll vector<ll, ll>
#define mp make_pair
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
ll ans =0;
const ll N = 8;

bool isValid(ll r, ll c,v(string) &s){
        for(ll i=r;i>=0;i--)
            if(s[i][c]=='Q')
                return false;
        for(ll i=r,j=c;i>=0 && j>=0;i--,j--)
            if(s[i][j]=='Q')
                return false;
        for(ll i=r,j=c;i>=0 && j<N;i--,j++)
            if(s[i][j]=='Q')
                return false;
        return true;
}

void Queens(v(string) &CB,ll row){
    if(row == N){
        ans++;
        return;
    }

    for(int i=0;i<N;i++)
        if(CB[row][i] =='.' && isValid(row,i,CB) ){
            CB[row][i] = 'Q';
            Queens(CB,row+1);
            CB[row][i] = '.';
        } 
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    v(string) CB(N);

    rep(i,0,N) cin >> CB[i];
    Queens(CB,0);


    cout << ans << endl;
}