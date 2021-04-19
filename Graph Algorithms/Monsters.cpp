#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define rsz resize
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pi  pair<int,int>
#define x first
#define y second
#define p(x,y) pair<x, y>
#define v(x) vector<x>
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mxN = 1001;
const ll mod = 1e9 + 7;
const ll N = 6;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)

int dx[4] ={1,-1,0,0};
int dy[4] ={0,0,1,-1};

ll vis[mxN][mxN];
ll par[mxN][mxN];
ll grid[mxN][mxN];
p(ll,ll) from[mxN][mxN];
char dir[mxN][mxN];

bool possible(ll n,ll m,ll x,ll y,v(string) &mat){
    if(x >=n || x <0 || y < 0 || y >=m || mat[x][y] =='#' || vis[x][y]==1)
        return false;
    return true;
}
int main(){
    FAST;
 
    ll n,m;
    cin >> n >>m;
    v(string) mat(n);
    v(p(ll,ll)) mon;
    ll ax,ay;
    rep(i,0,n) cin >> mat[i];

    rep(i,0,n)
        rep(j,0,m)
            if(mat[i][j] =='A'){ax = i,ay=j;}
            else if(mat[i][j] =='M') mon.pb({i,j});

    
    queue<p(ll,p(ll,ll))> q;
    memset(grid,-1,sizeof grid);

    rep(i,0,mon.size()){
        q.push({0,{mon[i].x,mon[i].y}});
        vis[mon[i].x][mon[i].y] = 1;
    }

    while(!q.empty()){
        p(ll,ll) p = q.front().y;
        ll lvl = q.front().x;

        q.pop();
        grid[p.x][p.y] = lvl;

        rep(i,0,4){
            ll nx = p.x + dx[i],ny = p.y + dy[i];
            if(!possible(n,m,nx,ny,mat)) continue;

            q.push({lvl + 1,{nx,ny}});
            vis[nx][ny] = 1;
        }
    }

    memset(vis,0,sizeof vis);
    string s = "DURL";

    q.push({0,{ax,ay}});
    p(ll,ll) to={-1,-1};

    while(!q.empty()){
        p(ll,ll) p = q.front().y;
        ll lvl = q.front().x;
        q.pop();

        if(grid[p.x][p.y] != -1 && lvl >= grid[p.x][p.y]) continue;

        if(p.x ==0 || p.x == n-1 || p.y ==0 ||p.y == m-1){
                to = p;
                break;
        }
        rep(i,0,4){
            ll nx = p.x + dx[i],ny = p.y + dy[i];
            if(!possible(n,m,nx,ny,mat)) continue;
            if(grid[nx][ny] != -1 && lvl >= grid[nx][ny]) continue;

            from[nx][ny] = p;
            q.push({lvl + 1,{nx,ny}});
            vis[nx][ny] = 1;
            dir[nx][ny] = s[i];
        }

        if(to.x!=-1)break;
    }

    if(to.x==-1) {
        cout <<"NO" << endl;
        return 0;
    }

    cout <<"YES"<<endl;
    s="";

    while(to.x!=ax || to.y!=ay){
        s += dir[to.x][to.y];
        to = from[to.x][to.y];
    }

    reverse(all(s));
    cout << s.size() << endl;
    cout << s;

    return 0;
}