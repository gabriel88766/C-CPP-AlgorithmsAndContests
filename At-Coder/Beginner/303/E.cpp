#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
set<int> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<int> vg1;
    for(int i=1;i<=n;i++){
        if(adj[i].size() == 1) vg1.push_back(i);
    }
    vector<int> ans;
    while(vg1.size()){
        int u = vg1.back();
        vg1.pop_back();
        if(adj[u].size() == 1){
            int x = *adj[u].begin();
            ans.push_back(adj[x].size());
            vector<pair<int, int>> rem;
            for(auto &v : adj[x]){
                rem.push_back({v, x});
                for(auto &k : adj[v]){
                    if(k != x) rem.push_back({v, k});
                }
            }
            for(auto &[a, b] : rem){
                adj[a].erase(b);
                adj[b].erase(a);
                if(adj[a].size() == 1) vg1.push_back(a);
                if(adj[b].size() == 1) vg1.push_back(b);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(auto &x : ans) cout << x << " ";
    cout << "\n";
}
