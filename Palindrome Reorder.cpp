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
#define vl vector<ll>
#define vll vector<ll, ll>
#define mp make_pair
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 1005;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))

int main(){
 
    string str;
    cin >> str;

    int ch[27]={0};

    for(char x:str) ch[x-'A']++;

    ll odd=0;
    string str1,str2;
    for(int i=0;i<27;i++) {
        if(ch[i]%2){ 
            odd++; 
            str1 += (i + 'A');
            ch[i]--;
        }

        if(ch[i]%2==0) {
            ll m = ch[i]/2;
            while(m--){
                str2 += (i + 'A');
            }
        }
    }

    string ans;
    string s3 = str2;
    reverse(all(s3));

    ans = str2 + str1 +  s3;
    ll n = str.size();

    if((n%2==1 && odd==1) || (n%2==0 && odd==0)) {
        cout << ans << endl;
    }
    else cout << "NO SOLUTION" << endl;

}