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
#define v(x) vector<x>
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 6;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

pair<ll,ll> getDir(char ch){
    switch (ch)
    {
    case 'R':
        return {1,0};
    case 'L':
        return {-1,0};
    case 'U':
        return {0,-1};
    case 'D':
        return {0,1};
    }
}
vector<vector<bool>> vis(N+1,vector<bool>(N+1,0));

int ans =0;
void paths(int idx,int row,int col,string dir){

    if(row == N && col == N && idx == dir.size()){
        ans++;
        return;
    }

    if(row < 0 || col < 0 || row > N || col > N || idx >= dir.size() || vis[row][col])
        return;

    vis[row][col] = 1;
    
    if(dir[idx] !='?'){
        pll a = getDir(dir[idx]);
        paths(idx+1,row+a.first,col+a.second,dir);
    }
    else
        rep(i,0,4)
            paths(idx+1,row+dx[i],col+dy[i],dir);

    vis[row][col] = 0;
} 
 
int main(){
    FAST;
    string dir;
    cin >> dir;
    paths(0,0,0,dir);

    cout << ans;

}