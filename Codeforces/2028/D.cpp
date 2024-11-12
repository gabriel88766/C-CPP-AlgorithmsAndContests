#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1), c(n+1), ia(n+1), ib(n+1), ic(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            ia[a[i]] = i;
        }
        for(int i=1;i<=n;i++){
            cin >> b[i];
            ib[b[i]] = i;
        }
        for(int i=1;i<=n;i++){
            cin >> c[i];
            ic[c[i]] = i;
        }
        int ma = 0, mb = 0, mc = 0;
        queue<int> q;
        q.push(1);
        vector<int> vis(n+1, 0);
        vector<pair<int,int>> par(n+1);
        vis[1] = true;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(a[u] > ma){
                for(int i=ma+1;i<a[u];i++){
                    if(!vis[ia[i]] && ia[i] > u){
                        vis[ia[i]] = true;
                        q.push(ia[i]);
                        par[ia[i]] = {u, 'q'};
                    }
                }
                ma = a[u];
            }
            if(b[u] > mb){
                for(int i=mb+1;i<b[u];i++){
                    if(!vis[ib[i]] && ib[i] > u){
                        vis[ib[i]] = true;
                        q.push(ib[i]);
                        par[ib[i]] = {u, 'k'};
                    }
                }
                mb = b[u];
            }
            if(c[u] > mc){
                for(int i=mc+1;i<c[u];i++){
                    if(!vis[ic[i]] && ic[i] > u){
                        vis[ic[i]] = true;
                        q.push(ic[i]);
                        par[ic[i]] = {u, 'j'};
                    }
                }
                mc = c[u];
            }
        }
        if(vis[n]){
            int cur = n;
            vector<pair<int,int>> ans;
            while(cur != 1){
                ans.push_back({cur, par[cur].second});
                cur = par[cur].first;
            }
            reverse(ans.begin(), ans.end());
            cout << "YES\n" << ans.size() << "\n";
            for(auto [a, b] :ans){
                char c = b;
                cout << c << " " << a << "\n";
            }
        }else cout << "NO\n";
    }
}
