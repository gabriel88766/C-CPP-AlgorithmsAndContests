#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+1;
set<int> adj[N];
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
        if(n == 1){
            cout << "0\n";
            continue;
        }
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        set<int> s;
        int ans = n;
        for(int i=1;i<=n;i++){
            if(adj[i].size() == 1){
                s.insert(i);
            }
        }
        for(int i=0;i<k;i++){
            if(ans == 0) break;
            vector<int> nvs;
            ans -= s.size();
            for(auto x : s){
                auto v = *adj[x].begin();
                adj[v].erase(x);
                if(adj[v].size() == 1) nvs.push_back(v);
            }
            s.clear();
            for(auto x : nvs) s.insert(x);
        }
        cout << ans << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
