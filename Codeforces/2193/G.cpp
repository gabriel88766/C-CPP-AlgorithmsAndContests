#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int xv = 0;
vector<pair<int, int>> vp;
void dfs(int u, int p){
    if(xv == 0) xv = u;
    else{
        vp.push_back({xv, u});
        xv = 0;
    }
    for(auto v : adj[u]){
        if(v != p) dfs(v, u);
    }
}
int ask(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
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
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        bool ok = false;
        for(auto [a, b] : vp){
            int ans = ask(a, b);
            if(ans == 1){
                int ans2 = ask(a, a);
                if(ans2 == 1) cout << "! " << a << "\n";
                else cout << "! " << b << "\n";
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << "! " << xv << "\n";
        }
        cout.flush();


        for(int i=1;i<=n;i++){
            adj[i].clear();
            xv = 0;
            vp.clear();
        }
    }
}
