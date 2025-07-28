#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
ll hv[101][N];
bool iadj[101][101];
int val[101][101];
int ihv[N];
int cl[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        //at most 100 heavy nodes
        for(int i=1;i<=n;i++){
            cin >> cl[i];
        }
        vector<vector<pair<int, int>>> adj(n+1);
        ll ans = 0, sum = 0;
        for(int i=1;i<n;i++){
            int a, b, c;
            cin >> a >> b >> c;
            ans += c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(adj[i].size() >= 2000){
                ihv[i] = ++cnt;
            }else ihv[i] = 0;
        }
        assert(cnt <= 100);
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=n;j++){
                hv[i][j] = 0;
            }
        }
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=cnt;j++){
                iadj[i][j] = false;
                val[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++){
            for(auto [v, w] : adj[i]){
                if(ihv[v] && ihv[i]){
                    iadj[ihv[i]][ihv[v]] = iadj[ihv[v]][ihv[i]] = true;
                    val[ihv[i]][ihv[v]] = val[ihv[v]][ihv[i]] = w;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            if(ihv[i]){
                for(auto [b, c] : adj[i]){
                    hv[ihv[i]][cl[b]] += c;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(ihv[i]){
                sum += hv[ihv[i]][cl[i]];
            }else{
                for(auto [b, c] : adj[i]){
                    if(cl[b] == cl[i]) sum += c;
                }
            }
        }
        sum /= 2;
        for(int i=1;i<=q;i++){
            int x, c;
            cin >> x >> c;
            if(ihv[x]){
                //subtract current
                //sum next
                sum -= hv[ihv[x]][cl[x]];
                sum += hv[ihv[x]][c];
                //update heavy
                for(int j=1;j<=cnt;j++){
                    if(ihv[x] == j) continue;
                    if(iadj[ihv[x]][j]){
                        hv[j][cl[x]] -= val[ihv[x]][j];
                        hv[j][c] += val[ihv[x]][j];
                    }
                }
                cl[x] = c;
            }else{
                for(auto [v, cc] : adj[x]){
                    if(cl[v] == cl[x]) sum -= cc;
                    if(cl[v] == c) sum += cc;
                    if(ihv[v]){
                        hv[ihv[v]][cl[x]] -= cc;
                        hv[ihv[v]][c] += cc;
                    } 
                }
                cl[x] = c;
            }

            // cout << ans << " " << sum << "\n";
            cout << ans - sum << "\n";
        }
    }
}   
