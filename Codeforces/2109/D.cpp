#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int d[N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, l;
        cin >> n >> m >> l;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            d[i][0] = d[i][1] = 2'000'000'001;
        }
        vector<int> a(l);
        for(int i=0;i<l;i++) cin >> a[i];
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<pair<int, int>> q;
        d[1][0] = 0;
        q.push({1, 0});
        while(!q.empty()){
            auto [u, x] = q.front();
            q.pop();
            for(auto &v : adj[u]){
                if(d[v][x^1] > d[u][x] + 1){
                    d[v][x^1] = d[u][x] + 1;
                    q.push({v, x^1});
                }
            }
        }
        
        
        int sum = 0;
        int lo = 2'000'000'000;
        int bge = 0, bgo = 0;
        for(int i=0;i<l;i++){
            sum += a[i];
            if(a[i] % 2) lo = min(lo, a[i]);
        }
        if(sum % 2){
            bgo = sum;
            bge = max(0, sum - lo);
        }else{
            bge = sum;
            bgo = max(0, sum - lo);
        }
        for(int i=1;i<=n;i++){
            if(d[i][0] <= bge || d[i][1] <= bgo) cout << "1";
            else cout << "0";
        }
        cout << "\n";
    }
}
