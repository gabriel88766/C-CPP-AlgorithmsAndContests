#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
pair<int,int> ans[N];
vector<int> adj[N];
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    map<pair<int,int>, vector<int>> mp;
    vector<pair<int,int>> anso(q+1);
    vector<int> outdg(n+1, 0);
    vector<int> ori(q+1, 0);
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        anso[i] = {a, b};
        outdg[a] ^= 1;
        if(a > b) swap(a, b);
        mp[{a, b}].push_back(i);
    }
    //solve for this graph
    
    
    
    for(auto [par, vec] : mp){
        auto [a, b] = par;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1, false);

    function<void(int, int)> dfsT = [&ori, &outdg, &mp, &dfsT, &vis](int u, int p){
        vis[u] = true;
        for(auto v : adj[u]){
            if(!vis[v]){
                dfsT(v, u);
            }
        }
        if(outdg[u] == 1 && p != 0){
            outdg[p] ^= 1;
            int a = u, b = p;
            if(a > b) swap(a, b);
            if(mp.count({a, b})){
                ori[mp[{a,b}][0]] ^= 1;
            }
        }   
    };

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfsT(i, 0);
        }
    }
    for(int i=1;i<=q;i++){
        if(ori[i] == 0){
            int cur = anso[i].first;
            if(cnt[cur]){
                ans[i] = {0, -1};
                cnt[cur]--;
            }else{
                ans[i] = {0, 1};
                cnt[cur]++;
            }
        }else{
            int cur = anso[i].second;
            if(cnt[cur]){
                ans[i] = {1, -1};
                cnt[cur]--;
            }else{
                ans[i] = {1, 1};
                cnt[cur]++;
            }
        }
    }
    for(int i=1;i<=q;i++){
        if(ans[i].first == 1) cout << "y";
        else cout << "x";
        if(ans[i].second == 1) cout << "+\n";
        else cout << "-\n";
    }
}

