#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int adj[N][2]; //next red light if I'm in a red light and in ith point.
bool inf[N][2];
int vis[N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> p(n+1);
        vector<ll> d(n+1);
        vector<ll> rd(n+1), ld(n+1);
        for(int i=1;i<=n;i++){
            cin >> p[i];
        }
        for(int i=1;i<=n;i++){
            cin >> d[i];
        }
        //normalize >> 
        map<ll, vector<int>> mrd, mld;
        for(int i=1;i<=n;i++){
            rd[i] = (p[i] - d[i]) % k;
            if(rd[i] < 0) rd[i] += k;
            mrd[rd[i]].push_back(i);
        }
        for(int i=1;i<=n;i++){
            ld[i] = (d[i] + p[i]) % k;
            if(ld[i] < 0) ld[i] += k;
            mld[ld[i]].push_back(i);
        }
        for(auto &[k, v] : mrd){
            for(int i=1;i<v.size(); i++){
                adj[v[i-1]][0] = v[i];
            }
        }
        for(auto &[k, v] : mld){
            for(int i=1;i<v.size(); i++){
                adj[v[i]][1] = v[i-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=1;j++){
                if(!vis[i][j]){
                    vector<pair<int, int>> fs;
                    int x = i, y = j;
                    while(x && vis[x][y] == 0){
                        fs.push_back({x, y});
                        vis[x][y] = 1;
                        x = adj[x][y];
                        y ^= 1;
                    }
                    if(x != 0 && (inf[x][y] || vis[x][y] == 1)){
                        for(auto &[a, b] : fs) inf[a][b] = true;
                    }
                    for(auto &[a, b] : fs) vis[a][b] = 2;
                }
            }
        }
        int q;
        cin >> q;
        for(int i=1;i<=q;i++){
            ll x;
            cin >> x;
            
            ll xx = x % k;
            if(mrd.count(xx)){
                int pos = lower_bound(p.begin(), p.end(), x) - p.begin();
                if(pos <= n){
                    auto it = lower_bound(mrd[xx].begin(), mrd[xx].end(), pos);
                    
                    if(it != mrd[xx].end() && inf[*it][1]) cout << "NO\n";
                    else cout << "YES\n";
                }else cout << "YES\n";
            }else cout << "YES\n";
        }

        for(int i=1;i<=n;i++){
            adj[i][0] = adj[i][1] = 0;
            vis[i][0] = vis[i][1] = 0;
            inf[i][0] = inf[i][1] = false;
        }
    }
}
