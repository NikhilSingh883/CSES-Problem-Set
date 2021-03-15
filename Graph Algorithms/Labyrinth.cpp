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
#define p(x) pair<x, x>
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

char addOn(ll idx){
    switch (idx)
    {
    case 0:
        return 'D';
    case 1:
        return 'U';
    case 2:
        return 'R';
    case 3:
        return 'L';
    }
}

int main(){

    cin >> n >> m;

    rep(i,0,n) cin >> mat[i];

    queue<pair<pair<ll,ll>,string>> Q;

    string path="";
    rep(i,0,n) rep(j,0,m) if(mat[i][j] == 'A') { Q.push({{i,j},""});}


    while(!Q.empty()){
        pair<pair<ll,ll>,string> top = Q.front();
        Q.pop();

        ll row = top.first.first;
        ll col = top.first.second;
        string ans = top.second;

        if(row<0 || col <0 || row >=n || col >=m || mat[row][col] == '#') continue;


        if(mat[row][col] =='B'){
            path = ans;
            break;
        }

        mat[row][col] = '#';

        rep(i,0,4)
            Q.push({{row+dx[i],col+dy[i]},ans + addOn(i)});

    }

    if(path.size()){
        cout <<"YES"<<endl;
        cout << path.size() << endl;
        cout << path << endl;
    }
    else cout << "NO" << endl;
    
}