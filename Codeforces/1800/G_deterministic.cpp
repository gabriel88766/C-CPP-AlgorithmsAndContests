// This is Hash in rooted trees
// using map of vector, we can effectively hash a tree without crazy hash functions.
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int n;
vector<int> adj[N];
map<vector<int>, int> mp;
int val[N];
int cnt;

int dfs(int u, int p){
    vector<int> ch;
    for(auto v : adj[u]){
        if(v != p){
            ch.emplace_back(dfs(v, u));
        }
    }
    sort(ch.begin(), ch.end());
    if(!mp.count(ch)) mp[ch] = ++cnt;
    return val[u] = mp[ch];
}

bool isSym(int rt, int p = -1){
    set<pair<int,int>> ch;
    set<int> vals;
    for(auto v : adj[rt]) if(v != p) {ch.insert({val[v], v}); vals.insert(val[v]); }
    int cntodd = 0, vodd;
    for(auto x : vals){
        int cnt = 0;
        auto it = ch.lower_bound({x, 0});
        while(it != ch.end() && it->first == x){
            cnt++;
            ++it;
        }
        if(cnt % 2){
            cntodd++;
            --it;
            vodd = it->second; 
        }
    }
    if(cntodd > 1) return false;
    else if(cntodd == 1) return isSym(vodd, rt);
    else return true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        cnt = 1;
        mp[vector<int>(0)] = 1;
        dfs(1, -1);
        if(isSym(1)) cout << "YES\n";
        else cout << "NO\n";
        


        for(int i=1;i<=n;i++) if(!adj[i].empty()) adj[i].clear();
        for(int i=1;i<=n;i++) val[i] = 0;
        mp.clear();
    }
}
