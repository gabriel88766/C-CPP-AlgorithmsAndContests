#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+3;   
int p[N], sz[N], ans[N];
 

struct custom_hash {
    size_t operator()(int const& num) const {
        int seed = num + 0x9e3779b9 + (num << 6) + (num >> 2);
        return seed;
    }
};
unordered_map<int,int, custom_hash> mp[N];
int t;
 
int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}
 
int cnt = 0;
void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    for(auto x : mp[b]){
        if(mp[a].count(x.first)){
            ans[x.first] = t;
            mp[a].erase(x.first);
            sz[a]-=2;
        }else{
            mp[a][x.first]++;
        }
    }
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin); //test input
    //freopen("out.txt", "w", stdout);
    vector<pair<int,int>> unites;
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        unites.emplace_back(a,b);
    }
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<=q;i++){
        int a,b;
        cin >> a >> b;
        sz[a]++, sz[b]++;
        mp[a][i]++, mp[b][i]++;
        if(a == b) ans[i] = 0;
        else ans[i] = -1;
    }
    for(int i=0;i<m;i++){
        t = i+1;
        unite(unites[i].first, unites[i].second);
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}
