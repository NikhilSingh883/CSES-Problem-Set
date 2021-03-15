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
string mat[1001];
int dx[4] ={1,-1,0,0};
int dy[4] ={0,0,1,-1};
ll n,m;

void dfs(int row,int col){
    if(row<0 || col < 0 || row >=n || col >=m || mat[row][col]=='#')
        return;

    mat[row][col] = '#';
    rep(i,0,4)
        dfs(row+dx[i],col+dy[i]);
}

int main(){

    cin >> n >> m;

    rep(i,0,n) cin >> mat[i];

    int ans =0;

    rep(i,0,n) rep(j,0,m) if(mat[i][j] == '.'){ dfs(i,j); ans++; }


    cout << ans << endl;
}