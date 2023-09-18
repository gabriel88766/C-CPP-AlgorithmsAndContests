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
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        if(k == 1){
            //trivial
            bool ok = true;
            for(int i=1;i<=n;i++) if(v[i] != i) ok = false;
            if(ok) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        vector<int> vis(n+1, 0);
        bool ok = true;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int cur = i;
                vector<int> aux;
                while(!vis[cur]){
                    aux.push_back(cur);
                    vis[cur] = 1;
                    cur = v[cur];
                }
                if(vis[cur] == 1){
                    vector<int> cycle;
                    while(vis[cur] == 1){
                        cycle.push_back(cur);
                        vis[cur] = 2;
                        cur = v[cur];
                    }
                    if(k != cycle.size()) ok = false;
                }
                for(auto j : aux) vis[j] = 2;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
