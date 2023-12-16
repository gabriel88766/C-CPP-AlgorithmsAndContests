#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;   
int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    map<pair<int,int>, int> mp;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        mp[{a, b}] = 0;
    }
    for(int i=0;i<k;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        mp[{a, b}] = k-i;
    }
    vector<pair<int, pair<int,int>>> vp;
    for(auto [k, v] : mp){
        vp.push_back({v, k});
    }
    sort(vp.begin(), vp.end(), [&](const pair<int, pair<int,int>> &u, const pair<int, pair<int,int>> &v){
        return u.first < v.first;
    });
    vector<int> ans(k+2);
    int cp = n;
    init();
    for(auto [i, val] : vp){
        auto [u, v] = val;
        ans[k-i+1] = cp;
        if(get(u) != get(v)){
            cp--;
            unite(u, v);
        }
    }
    for(int i=1;i<=k;i++) cout << ans[i] << " ";
    cout << "\n";
}
