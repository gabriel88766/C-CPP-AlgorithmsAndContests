#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int n, k;
bool ok = true;

int dfs(int u, int p){
    vector<int> vx;
    for(auto &v : adj[u]){
        if(v != p){
            int cur = dfs(v, u);
            if(cur != 0) vx.push_back(cur);
        }
    }
    if(vx.size() == 0) return 1 % k ;
    else if(vx.size() == 1) return (vx[0] + 1) % k;
    else if(vx.size() == 2){
        if(vx[0] + vx[1] + 1 == k) return 0;
        else{
            ok = false;
            return 0;
        } 
    }else{
        ok = false;
        return 0;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> k;
    for(int i=1;i<n*k;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
   
    int val = dfs(1, 0);
    // if(val != 0) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}