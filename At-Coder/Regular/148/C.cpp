#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int par[N];
vector<int> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
        par[i] = p;
    }
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        set<int> s;
        for(int i=0;i<x;i++){
            int y;
            cin >> y;
            s.insert(y);
        }
        int ans = 0;
        for(auto &x : s){
            ans += adj[x].size() + 1;
            if(s.count(par[x])) ans -= 2;
        }
        cout << ans << "\n";
    }

}
