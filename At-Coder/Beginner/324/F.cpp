#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
struct Frac{
    ll a, b;
    Frac(){
        a = b = 0;
    }
    Frac(ll a, ll b){
        this->a = a;
        this->b = b;
    }
    bool operator< (const Frac f) const {
        if(a == 0) return true;
        else return a*f.b < b*f.a;
    }
    Frac operator+ (const Frac f) const {
        return Frac(a+f.a, b+f.b);
    }
};


vector<ll> adj[N], adjb[N], adjv[N];
Frac dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, c, b, v;
        cin >> a >> c >> b >> v;
        adj[a].push_back(c);
        adjb[a].push_back(b);
        adjv[a].push_back(v);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size(); j++){
            Frac nowc =  dp[i] + Frac(adjb[i][j], adjv[i][j]);
            if(dp[adj[i][j]] < nowc){
                dp[adj[i][j]] = nowc;
            }
        }
    }
    cout << fixed << setprecision(15) << ((double)dp[n].a)/dp[n].b << "\n";
}
