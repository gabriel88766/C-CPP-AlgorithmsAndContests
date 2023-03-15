// This is Hash in rooted trees
// using map of vector, we can effectively hash a tree without crazy hash functions.
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int n;
vector<int> adj1[N], adj2[N];
map<vector<int>, int> mp;
int cnt;

int dfs1(int u, int p){
    vector<int> ch;
    for(auto v : adj1[u]){
        if(v != p){
            ch.emplace_back(dfs1(v, u));
        }
    }
    sort(ch.begin(), ch.end());
    if(!mp.count(ch)) mp[ch] = ++cnt;
    return mp[ch];
}

int dfs2(int u, int p){
    vector<int> ch;
    for(auto v : adj2[u]){
        if(v != p){
            ch.emplace_back(dfs2(v, u));
        }
    }
    sort(ch.begin(), ch.end());
    if(!mp.count(ch)) mp[ch] = ++cnt;
    return mp[ch];
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
            adj1[a].emplace_back(b);
            adj1[b].emplace_back(a);
        }
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            adj2[a].emplace_back(b);
            adj2[b].emplace_back(a);
        }
        cnt = 1;
        mp[vector<int>(0)] = 1;
        dfs1(1, -1);
        int val = cnt;
        dfs2(1, -1);
        if(val == cnt) cout << "YES\n";
        else cout << "NO\n";
        
        for(int i=1;i<=n;i++){
             if(!adj1[i].empty()) adj1[i].clear();
             if(!adj2[i].empty()) adj2[i].clear();
        }
        mp.clear();
    }
}
